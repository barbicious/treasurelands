#pragma once

#include "chunk.h"
#include "chunk_table.h"

typedef struct {
    chunk_table_s chunk_table;
} level_s;

level_s level_create();
void level_blit(level_s *level);
void level_destroy(level_s *level);