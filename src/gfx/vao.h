#pragma once

#include "vbo.h"
#include "../util/types.h"

typedef struct {
    u32 id;
} vao_s;

vao_s vao_create();

void vao_destroy(const vao_s *vao);

void vao_bind(const vao_s *vao);

void vao_unbind();

void vao_attribute(u32 index, i32 size, i32 stride, u32 offset);
