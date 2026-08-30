#pragma once

#include "types.h"

typedef struct {
    char* raw;
    u32 len;
} string_s;

string_s string_create(char* string);