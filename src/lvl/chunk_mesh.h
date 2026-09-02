#pragma once

#include "tile.h"
#include "../gfx/vao.h"
#include "../gfx/vbo.h"
#include "../util/types.h"

typedef struct chunk chunk_s;

typedef struct {
    f32 vertices[total_vertices * 16 * 16 * 16];

    usize faces;

    vao_s vao;
    vbo_s vbo;
} chunk_mesh_s;

chunk_mesh_s chunk_mesh_create(chunk_s *chunk, i32 x, i32 y, i32 z);

void chunk_mesh_destroy(chunk_mesh_s *chunk_mesh);

void chunk_mesh_blit(chunk_mesh_s *chunk_mesh);
