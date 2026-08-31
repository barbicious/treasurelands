#include "chunk_mesh.h"

#include <stdio.h>
#include <string.h>

#include "glad/glad.h"

static void chunk_mesh_add_face(chunk_mesh_s *chunk_mesh, tile_type_e tile_type, face_e face, f32 x, f32 y, f32 z) {
    f32 vertices[vertices_per_face] = {0};
    memcpy(chunk_mesh->vertices + vertices_per_face * chunk_mesh->faces, tile_vertices(tile_type, face, x, y, z, vertices), bytes_per_face);
    chunk_mesh->faces++;
}

chunk_mesh_s chunk_mesh_create() {
    chunk_mesh_s chunk_mesh = {0};

    chunk_mesh.vao = vao_create();
    chunk_mesh.vbo = vbo_create();

    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_west, 0, 0, 0);
    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_east, 0, 0, 0);
    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_bottom, 0, 0, 0);
    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_top, 0, 0, 0);
    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_left, 0, 0, 0);
    chunk_mesh_add_face(&chunk_mesh, tile_type_grass, face_right, 0, 0, 0);

    vbo_submit_data(&chunk_mesh.vao, &chunk_mesh.vbo, sizeof(chunk_mesh.vertices), chunk_mesh.vertices);

    return chunk_mesh;
}

void chunk_mesh_destroy(chunk_mesh_s *chunk_mesh) {
    vao_destroy(&chunk_mesh->vao);
    vbo_destroy(&chunk_mesh->vbo);
}

void chunk_mesh_blit(chunk_mesh_s *chunk_mesh) {
    glDrawArrays(GL_TRIANGLES, 0, 180);
}
