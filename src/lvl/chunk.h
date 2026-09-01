#pragma once
#include "chunk_mesh.h"

constexpr i32 chunk_width = 16;
constexpr i32 chunk_height = 16;
constexpr i32 chunk_depth = 16;

typedef struct {
    chunk_mesh_s mesh;

    i32 x, y, z;
} chunk_s;

chunk_s *chunk_create(i32 x, i32 y, i32 z);
void chunk_blit(chunk_s *chunk);
void chunk_destroy(chunk_s *chunk);