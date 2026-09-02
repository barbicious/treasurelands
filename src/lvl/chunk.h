#pragma once
#include "chunk_mesh.h"

#define CHUNK_TILE_POS(tile, i)\
    if (ray.end[i] > 0) {\
        tile = (i32)ray.end[i] % chunk_width;\
    } else {\
        tile = (i32)(ray.end[i] - 1) + abs((chunk_width) * chunk_coordinates(ray.end[i]));\
    }

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
i32 chunk_coordinates(f32 n);