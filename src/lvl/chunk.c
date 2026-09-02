#include "chunk.h"

#include <stdlib.h>
#include <string.h>

#include "tile.h"

#define CHUNK_IDX(x, y, z) ((x) + chunk_width * ((z) + chunk_depth * y))

static void generate_chunk(chunk_s *chunk) {
    for (usize x = 0; x < chunk_width; x++) {
        for (usize z = 0; z < chunk_depth; z++) {
            for (usize y = 0; y < chunk_height; y++) {
                tile_type_e tile_type = tile_type_air;

                i32 idx = (i32)y + (chunk->y * chunk_height);

                if (idx < 1) {
                    tile_type = tile_type_stone;
                } else if (idx < 4) {
                    tile_type = tile_type_grass;
                }

                chunk->tiles[CHUNK_IDX(x, y, z)] = tile_type;
            }
        }
    }
}

chunk_s *chunk_create(i32 x, i32 y, i32 z) {
    chunk_s *chunk = malloc(sizeof(chunk_s));
    memset(chunk, 0, sizeof(chunk_s));

    chunk->x = x;
    chunk->y = y;
    chunk->z = z;

    generate_chunk(chunk);

    chunk->mesh = chunk_mesh_create(chunk, chunk->x, chunk->y, chunk->z);

    return chunk;
}

void chunk_blit(chunk_s *chunk) {
    chunk_mesh_blit(&chunk->mesh);
}

void chunk_destroy(chunk_s *chunk) {
    chunk_mesh_destroy(&chunk->mesh);
    free(chunk);
}

tile_type_e chunk_tile_at(chunk_s *chunk, usize x, usize y, usize z) {
    return chunk->tiles[CHUNK_IDX(x, y, z)];
}

void chunk_set_tile(chunk_s *chunk, usize x, usize y, usize z, tile_type_e tile_type) {
    chunk->tiles[CHUNK_IDX(x, y, z)] = tile_type;
    chunk_mesh_destroy(&chunk->mesh);
    chunk->mesh = chunk_mesh_create(chunk, chunk->x, chunk->y, chunk->z);
}