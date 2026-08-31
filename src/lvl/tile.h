#pragma once

#include "../util/types.h"

constexpr f32 atlas_width = 256;
constexpr f32 atlas_height = 256;

constexpr usize vertices_per_face = 30;
constexpr usize bytes_per_face = sizeof(f32) * vertices_per_face;

constexpr usize faces = 6;
constexpr usize total_vertices = vertices_per_face * faces;

typedef enum : u8 {
    tile_type_grass,
} tile_type_e;

typedef enum : u8 {
    face_east,
    face_west,
    face_top,
    face_bottom,
    face_left,
    face_right,
} face_e;

f32 *tile_vertices(tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z, f32 vertices[vertices_per_face]);

#define TILE_DEFINE(name)\
    extern const f32 front_##name##_vertices[vertices_per_face];\
    extern const f32 back_##name##_vertices[vertices_per_face];\
    extern const f32 top_##name##_vertices[vertices_per_face];\
    extern const f32 bottom_##name##_vertices[vertices_per_face];\
    extern const f32 left_##name##_vertices[vertices_per_face];\
    extern const f32 right_##name##_vertices[vertices_per_face];

TILE_DEFINE(grass);