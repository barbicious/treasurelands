#pragma once
#include "chunk.h"

typedef struct {
    i32 x, y, z;
    chunk_s *chunk;
} entry_s;

typedef struct {
    entry_s *entries;

    usize capacity;
    usize length;
} chunk_table_s;

chunk_table_s chunk_table_create();
void chunk_table_destroy(chunk_table_s *table);
chunk_s *chunk_table_get(chunk_table_s *table, i32 x, i32 y, i32 z);
void chunk_table_set(chunk_table_s *table, chunk_s *chunk);