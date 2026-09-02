#include "tile.h"

#include <stdio.h>
f32 *tile_vertices(tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z, f32 vertices[vertices_per_face]) {
    f32 u = 0.0f, v = 0.0f;

    switch (tile_type) {
        case tile_type_grass:
            u = 0.0f / atlas_width;
            v = 0.0f / atlas_height;
            break;
        case tile_type_stone:
            u = 8.0f / atlas_width;
            v = 0.0f / atlas_height;
            break;
    }

    f32 full_u = 8.0f / atlas_width + u, full_v = 8.0f / atlas_height + v;

    switch (face) {
        case face_bottom: {
            vertices = (f32[]){
                x,        y,        z, u, v,
                x + 1.0f, y,        z, full_u, v,
                x + 1.0f, y, z + 1.0f, full_u, full_v,
                x + 1.0f, y, z + 1.0f, full_u, full_v,
                x,        y, z + 1.0f, u, full_v,
                x,        y,        z, u, v,
            };
        }
        break;
        case face_top: {
            vertices = (f32[]){
                x + 1.0f, y + 1.0f,        z, u, v,
                x,        y + 1.0f,        z, full_u, v,
                x,        y + 1.0f, z + 1.0f, full_u, full_v,
                x,        y + 1.0f, z + 1.0f, full_u, full_v,
                x + 1.0f, y + 1.0f, z + 1.0f, u, full_v,
                x + 1.0f, y + 1.0f,        z, u, v,
            };
        }
        break;
        case face_front: {
            vertices = (f32[]){
                x + 1.0f,        y,        z, u, v,
                x, y,        z, full_u, v,
                x, y + 1.0f, z, full_u, full_v,
                x, y + 1.0f, z, full_u, full_v,
                x + 1.0f,        y + 1.0f, z, u, full_v,
                x + 1.0f,        y,        z, u, v,
            };
        }
        break;

        case face_back: {
            vertices = (f32[]){
                x,        y,        z + 1.0f, u, v,
                x + 1.0f, y,        z + 1.0f, full_u, v,
                x + 1.0f, y + 1.0f, z + 1.0f, full_u, full_v,
                x + 1.0f, y + 1.0f, z + 1.0f, full_u, full_v,
                x,        y + 1.0f, z + 1.0f, u, full_v,
                x,        y,        z + 1.0f, u, v,
            };
        }
        break;

        case face_left: {
            vertices = (f32[]){
                x,        y + 1.0f,        z, u, v,
                x, y,        z, full_u, v,
                x, y, z + 1.0f, full_u, full_v,
                x, y, z + 1.0f, full_u, full_v,
                x,        y + 1.0f, z + 1.0f, u, full_v,
                x,        y + 1.0f,        z, u, v,
            };
        }
        break;

        case face_right: {
            vertices = (f32[]){
                x + 1.0f,        y,        z, u, v,
                x + 1.0f, y + 1.0f,        z, full_u, v,
                x + 1.0f, y + 1.0f, z + 1.0f, full_u, full_v,
                x + 1.0f, y + 1.0f, z + 1.0f, full_u, full_v,
                x + 1.0f,        y, z + 1.0f, u, full_v,
                x + 1.0f,        y,        z, u, v,
            };
        }
        break;
    }

    return vertices;
}
