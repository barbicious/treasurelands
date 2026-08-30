#pragma once

#include "../util/types.h"
#include "../util/string.h"

typedef struct GLFWwindow GLFWwindow;

typedef struct {
    GLFWwindow* raw;
    s32 width, height;
} window_s;

window_s window_create(s32 width, s32 height, string_s title);
bool window_is_good(const window_s* window);
void window_display(const window_s* window);
void window_destroy(const window_s* window);