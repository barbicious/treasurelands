#pragma once

#include "../util/types.h"
#include "cglm/mat4.h"

typedef struct {
    u32 id;
} shader_s;

shader_s shader_create(const char *vs_path, const char *fs_path);

void shader_destroy(const shader_s *shader);

void shader_bind(const shader_s *shader);

void shader_unbind();

void shader_set_mat4(const shader_s *shader, const char *name, const mat4 m);
