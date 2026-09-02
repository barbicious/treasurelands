#pragma once
#include "chunk_mesh.h"

constexpr i32 chunk_width = 16;
constexpr i32 chunk_height = 16;
constexpr i32 chunk_depth = 16;

typedef struct chunk {
    chunk_mesh_s mesh;

    tile_type_e tiles[chunk_width * chunk_height * chunk_depth];

    i32 x, y, z;
} chunk_s;

chunk_s *chunk_create(i32 x, i32 y, i32 z);
void chunk_blit(chunk_s *chunk);
void chunk_destroy(chunk_s *chunk);
tile_type_e chunk_tile_at(chunk_s *chunk, usize x,  usize y, usize z);
void chunk_set_tile(chunk_s *chunk, usize x, usize y, usize z, tile_type_e tile_type);