#include "window.h"

#include <stdio.h>
#include <stdlib.h>
#include <glad/glad.h>
#include "GLFW/glfw3.h"

window_s window_create(const i32 width, const i32 height, const string_s title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(width, height, title.raw, nullptr, nullptr);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        glfwDestroyWindow(window);
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    return (window_s){
        .raw = window,
        .width = width,
        .height = height,
    };
}

bool window_is_good(const window_s* window) {
    glfwPollEvents();
    return !glfwWindowShouldClose(window->raw);
}

void window_display(const window_s* window) {
    glfwSwapBuffers(window->raw);
}

void window_destroy(const window_s* window) {
    glfwDestroyWindow(window->raw);
}
