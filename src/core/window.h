#pragma once

#include "../util/types.h"
#include "../util/string.h"

#include <glad/glad.h>
#include "GLFW/glfw3.h"

typedef struct {
    struct {
        bool previous[GLFW_KEY_LAST];
        bool current[GLFW_KEY_LAST];
    } keyboard;

    GLFWwindow *raw;

    struct {
        f32 delta_x, delta_y;
        f32 x, y;
        bool first;
    } mouse;

    i32 width, height;
} window_s;

void window_create(i32 width, i32 height, string_s title);
void window_destroy();
bool window_is_good();
void window_display();
bool window_is_key_down(i32 key);
bool window_is_key_pressed(i32 key);
f32 delta_time();

extern window_s window;