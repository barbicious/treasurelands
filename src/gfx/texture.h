#pragma once

#include "../util/types.h"

typedef struct {
    u32 id;

    i32 width, height;
} texture_s;

texture_s texture_load(const char *path);

void texture_destroy(texture_s *texture);

void texture_bind(texture_s *texture);

void texture_unbind(texture_s *texture);
