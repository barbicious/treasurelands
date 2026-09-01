#include "chunk.h"

#include <stdlib.h>

chunk_s *chunk_create(i32 x, i32 y, i32 z) {
    chunk_s *chunk = malloc(sizeof(chunk_s));

    chunk->x = x;
    chunk->y = y;
    chunk->z = z;

    chunk->mesh = chunk_mesh_create(chunk->x, chunk->y, chunk->z);

    return chunk;
}

void chunk_blit(chunk_s *chunk) {
    chunk_mesh_blit(&chunk->mesh);
}

void chunk_destroy(chunk_s *chunk) {
    chunk_mesh_destroy(&chunk->mesh);
    free(chunk);
}
