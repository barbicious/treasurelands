#pragma once

#include "../util/types.h"
#include "vao.h"

typedef struct {
    u32 id;
} vbo_s;

vbo_s vbo_create();

void vbo_destroy(const vbo_s *vbo);

void vbo_bind(const vbo_s *vbo);

void vbo_unbind();

void vbo_submit_data(vao_s *vao, vbo_s *vbo, i32 size, const void *data);
