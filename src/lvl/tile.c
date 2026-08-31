#include "tile.h"

#define TILE_IMPL(name, texture_x, texture_y)\
    const f32 front_##name##_vertices[] = {\
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,\
         0.5f, -0.5f, -0.5f,  texture_x / atlas_width, 0.0f,\
         0.5f,  0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
         0.5f,  0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
        -0.5f,  0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,\
    };\
    const f32 back_##name##_vertices[] = {\
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,\
         0.5f, -0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
        -0.5f,  0.5f,  0.5f,  0.0f, texture_y / atlas_height,\
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,\
    };\
    const f32 left_##name##_vertices[] = {\
        -0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
        -0.5f,  0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
        -0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
        -0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,\
        -0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
    };\
    const f32 right_##name##_vertices[] = {\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
         0.5f,  0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
         0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
         0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
    };\
    const f32 bottom_##name##_vertices[] = {\
        -0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
         0.5f, -0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
         0.5f, -0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
         0.5f, -0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,\
        -0.5f, -0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
    };\
    const f32 top_##name##_vertices[] = {\
        -0.5f,  0.5f, -0.5f,  0.0f, texture_y / atlas_height,\
         0.5f,  0.5f, -0.5f,  texture_x / atlas_width, texture_y / atlas_height,\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
         0.5f,  0.5f,  0.5f,  texture_x / atlas_width, 0.0f,\
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,\
        -0.5f,  0.5f, -0.5f,  0.0f, texture_y / atlas_height\
    };

f32 *tile_vertices(tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z, f32 vertices[vertices_per_face]) {
    f32 full_u = 8.0f / atlas_width, full_v = 8.0f / atlas_height;

    f32 u, v;

    switch (tile_type) {
        case tile_type_grass:

            break;
    }

    switch (face) {
        case face_bottom: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;
        case face_top: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;
        case face_east: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;

        case face_west: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;

        case face_left: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;

        case face_right: {
            vertices = (f32[]){
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height,
                 0.5f,  0.5f, -0.5f,  8.0f / atlas_width, 8.0f / atlas_height,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                 0.5f,  0.5f,  0.5f,  8.0f / atlas_width, 0.0f,
                -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0.0f, 8.0f / atlas_height
            };
        } break;
    }

    return vertices;
}

TILE_IMPL(grass, 8.0f, 8.0f);
