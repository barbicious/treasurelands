#include "chunk_table.h"

#include <stdio.h>
#include <stdlib.h>

static constexpr usize initial_capacity = 16;

static bool chunk_cmp(chunk_s *chunk, i32 x, i32 y, i32 z) {
    return chunk->x == x && chunk->y == y && chunk->z == z;
}

static u64 hash_key(i32 x, i32 y, i32 z) {
    u64 hash = 14695981039346656037UL;

    hash = (hash * 33) ^ (u32)x;
    hash = (hash * 33) ^ (u32)y;
    hash = (hash * 33) ^ (u32)z;

    return hash;
}

chunk_table_s chunk_table_create() {
    chunk_table_s table = {0};
    table.length = 0;
    table.capacity = initial_capacity;

    table.entries = calloc(table.capacity, sizeof(entry_s));
    if (table.entries == nullptr) {
        fprintf(stderr, "chunk_table_create: calloc() failed\n");
        exit(-1);
    }

    return table;
}

void chunk_table_destroy(chunk_table_s *table) {
    for (usize i = 0; i < table->length; i++) {
        if (table->entries[i].chunk != nullptr) {
            chunk_destroy(table->entries[i].chunk);
        }
    }

    free(table->entries);
}

chunk_s *chunk_table_get(chunk_table_s *table, i32 x, i32 y, i32 z) {
    u64 hash = hash_key(x, y, z);

    // ensure the hash is within capacity of array
    usize index = hash & table->capacity - 1;

    while (table->entries[index].chunk != nullptr) {
        if (chunk_cmp(table->entries[index].chunk, x, y, z)) {
            return table->entries[index].chunk;
        }

        index++;
        if (index >= table->capacity) {
            index = 0;
        }
    }

    return nullptr;
}

static void chunk_table_set_entry(chunk_table_s *table, u64 hash, chunk_s *chunk) {
    // ensure the hash is within capacity of array
    usize index = hash & table->capacity - 1;

    while (table->entries[index].chunk != nullptr) {
        if (chunk_cmp(table->entries[index].chunk, chunk->x, chunk->y, chunk->z)) {
            table->entries[index].chunk = chunk;
            return;
        }

        index++;

        if (index >= table->capacity) {
            index = 0;
        }
    }

    table->entries[index].chunk = chunk;

    table->entries[index].x = chunk->x;
    table->entries[index].y = chunk->y;
    table->entries[index].z = chunk->z;

    table->length++;
}

static void chunk_table_resize(chunk_table_s *table, u64 hash, chunk_s *chunk) {
    if (table->length >= table->capacity / 2) {
        usize new_capacity = table->capacity * 2;
        if (new_capacity < table->capacity) {
            fprintf(stderr, "chunk_table_set: capacity overflow, hashtable got too big\n");
        }

        entry_s *entries = calloc(new_capacity, sizeof(entry_s));
        if (entries == nullptr) {
            fprintf(stderr, "chunk_table_set: calloc() failed\n");
            exit(EXIT_FAILURE);
        }

        for (usize i = 0; i < table->length; i++) {
            const entry_s entry = table->entries[i];
            if (entry.chunk != nullptr) {
                chunk_table_set_entry(table, hash, entry.chunk);
            }
        }

        free(table->entries);
        table->entries = entries;
        table->capacity = new_capacity;
    }
}

void chunk_table_set(chunk_table_s *table, chunk_s *chunk) {
    u64 hash = hash_key(chunk->x, chunk->y, chunk->z);

    chunk_table_resize(table, hash, chunk);

    chunk_table_set_entry(table, hash, chunk);
}
