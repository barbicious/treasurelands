#pragma once

#include "tile.h"
#include "../gfx/vao.h"
#include "../gfx/vbo.h"
#include "../util/types.h"

typedef struct {
    f32 vertices[total_vertices];

    usize faces;

    vao_s vao;
    vbo_s vbo;
} chunk_mesh_s;

chunk_mesh_s chunk_mesh_create();
void chunk_mesh_destroy(chunk_mesh_s *chunk_mesh);
void chunk_mesh_blit(chunk_mesh_s *chunk_mesh);