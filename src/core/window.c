#include "window.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

window_s window;

static void cursor_position_callback(GLFWwindow *glfw_window, f64 xpos, f64 ypos) {
    if (window.mouse.first) {
        window.mouse.x = (f32) xpos;
        window.mouse.y = (f32) ypos;

        window.mouse.first = false;
    }

    window.mouse.delta_x = (f32) xpos - window.mouse.x;
    window.mouse.delta_y = window.mouse.y - (f32) ypos;

    window.mouse.x = (f32) xpos;
    window.mouse.y = (f32) ypos;
}

static void framebuffer_size_callback(GLFWwindow *glfw_window, i32 width, i32 height) {
    glViewport(0, 0, width, height);
}

void window_create(const i32 width, const i32 height, const string_s title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow *raw = glfwCreateWindow(width, height, title.raw, nullptr, nullptr);
    if (raw == nullptr) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(raw);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        glfwDestroyWindow(raw);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(raw, framebuffer_size_callback);
    glfwSetCursorPosCallback(raw, cursor_position_callback);

    glfwSetInputMode(raw, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    window = (window_s){
        .raw = raw,
        .width = width,
        .height = height,
        .mouse = {
            .first = true,
        }
    };
}

bool window_is_good() {
    glfwPollEvents();

    memcpy(window.keyboard.previous, window.keyboard.current, sizeof(window.keyboard.current));
    for (usize i = 0; i < GLFW_KEY_LAST; i++) {
        window.keyboard.current[i] = glfwGetKey(window.raw, (i32) i) == GLFW_PRESS;
    }

    return !glfwWindowShouldClose(window.raw);
}

bool window_is_key_down(i32 key) {
    return window.keyboard.current[key] && window.keyboard.previous[key];
}

bool window_is_key_pressed(i32 key) {
    return window.keyboard.current[key];
}

void window_display() {
    glfwSwapBuffers(window.raw);

    window.mouse.delta_x = window.mouse.delta_y = 0;
}

void window_destroy() {
    glfwDestroyWindow(window.raw);
    glfwTerminate();
}

f32 delta_time() {
    static f32 last_time = 0.0f;
    f32 delta_time = (f32) glfwGetTime() - last_time;
    last_time = (f32) glfwGetTime();
    return delta_time;
}
