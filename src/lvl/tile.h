#pragma once

#include "../util/types.h"

constexpr f32 atlas_width = 256;
constexpr f32 atlas_height = 256;

constexpr usize vertices_per_face = 30;
constexpr usize face_size = sizeof(f32) * vertices_per_face;

constexpr usize faces = 6;
constexpr usize total_vertices = vertices_per_face * faces;

typedef enum : u8 {
    tile_type_grass,
} tile_type_e;

typedef enum : u8 {
    face_front,
    face_back,
    face_top,
    face_bottom,
    face_left,
    face_right,
} face_e;

f32 *tile_vertices(tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z, f32 vertices[vertices_per_face]);
