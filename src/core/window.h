#pragma once

#include "../util/types.h"
#include "../util/string.h"

typedef struct GLFWwindow GLFWwindow;

typedef struct {
    GLFWwindow* raw;
    i32 width, height;
} window_s;

window_s window_create(i32 width, i32 height, string_s title);
bool window_is_good(const window_s* window);
void window_display(const window_s* window);
void window_destroy(const window_s* window);