#include "level.h"

level_s level_create() {
    chunk_table_s chunk_table = chunk_table_create();

    for (i32 z = -1; z <= 1; z++) {
        for (i32 y = -1; y <= 1; y++) {
            for (i32 x = -1; x <= 1; x++) {
                chunk_table_set(&chunk_table, chunk_create(x, y, z));
            }
        }
    }

    return (level_s){
        .chunk_table = chunk_table,
    };
}

void level_blit(level_s *level) {
    for (i32 z = -1; z <= 1; z++) {
        for (i32 y = -1; y <= 1; y++) {
            for (i32 x = -1; x <= 1; x++) {
                chunk_s *chunk = chunk_table_get(&level->chunk_table, x, y, z);

                if (chunk == nullptr) {
                    continue;
                }

                chunk_blit(chunk);
            }
        }
    }
}

void level_destroy(level_s *level) {
    chunk_table_destroy(&level->chunk_table);
}
