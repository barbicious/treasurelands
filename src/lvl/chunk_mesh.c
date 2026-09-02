#include "chunk_mesh.h"

#include <stdio.h>
#include <string.h>

#include "chunk.h"
#include "glad/glad.h"

#define WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z)\
    (f32)tile_x + (f32)(x * chunk_width),\
    (f32)tile_y + (f32)(y * chunk_height),\
    (f32)tile_z + (f32)(z * chunk_depth)

static void chunk_mesh_add_face(chunk_mesh_s *chunk_mesh, tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z) {
    f32 vertices[vertices_per_face] = {0};
    memcpy(&chunk_mesh->vertices[vertices_per_face * chunk_mesh->faces],
           tile_vertices(tile_type, face, x, y, z, vertices), face_size);
    chunk_mesh->faces++;
}

chunk_mesh_s chunk_mesh_create(chunk_s *chunk, i32 x, i32 y, i32 z) {
    chunk_mesh_s chunk_mesh = {0};

    chunk_mesh.vao = vao_create();
    vao_bind(&chunk_mesh.vao);

    chunk_mesh.vbo = vbo_create();
    vbo_bind(&chunk_mesh.vbo);

    vao_attribute(0, 3, 5 * sizeof(f32), 0);
    vao_attribute(1, 2, 5 * sizeof(f32), 3 * sizeof(f32));

    for (usize tile_z = 0; tile_z < chunk_depth; tile_z++) {
        for (usize tile_y = 0; tile_y < chunk_height; tile_y++) {
            for (usize tile_x = 0; tile_x < chunk_width; tile_x++) {
                tile_type_e tile_type = chunk_tile_at(chunk, tile_x, tile_y, tile_z);

                if (tile_type == tile_type_air) {
                    continue;
                }

                if (tile_z > 0 && chunk_tile_at(chunk, tile_x, tile_y, tile_z - 1) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_front, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

                if (tile_z < chunk_depth - 1 && chunk_tile_at(chunk, tile_x, tile_y, tile_z + 1) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_back, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

                if (tile_y > 0 && chunk_tile_at(chunk, tile_x, tile_y - 1, tile_z) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_bottom, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

                if (tile_y < chunk_height - 1 && chunk_tile_at(chunk, tile_x, tile_y + 1, tile_z) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_top, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

                if (tile_x > 0 && chunk_tile_at(chunk, tile_x - 1, tile_y, tile_z) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_left, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

                if (tile_x < chunk_width - 1 && chunk_tile_at(chunk, tile_x + 1, tile_y, tile_z) == tile_type_air) {
                    chunk_mesh_add_face(&chunk_mesh, tile_type, face_right, WORLD_POSITION(tile_x, tile_y, tile_z, x, y, z));
                }

            }
        }
    }

    vbo_submit_data(&chunk_mesh.vao, &chunk_mesh.vbo, sizeof(chunk_mesh.vertices), chunk_mesh.vertices);
    
    return chunk_mesh;
}

void chunk_mesh_destroy(chunk_mesh_s *chunk_mesh) {
    vao_destroy(&chunk_mesh->vao);
    vbo_destroy(&chunk_mesh->vbo);
}

void chunk_mesh_blit(chunk_mesh_s *chunk_mesh) {
    vao_bind(&chunk_mesh->vao);
    vbo_bind(&chunk_mesh->vbo);
    glDrawArrays(GL_TRIANGLES, 0, chunk_mesh->faces * vertices_per_face);
}
