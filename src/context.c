#include "context.h"

#include <string.h>

#include "cglm/cglm.h"
#include "cglm/affine-pre.h"
#include "core/window.h"
#include "gfx/shader.h"
#include "gfx/texture.h"
#include "gfx/vao.h"
#include "gfx/vbo.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "lvl/chunk_mesh.h"
#include "lvl/chunk_table.h"
#include "lvl/tile.h"

context_s context_create() {
    window_create(1280, 720, string_create("Treasurelands"));

    return (context_s){
        .level = level_create()
    };
}

void context_run(context_s *context) {
    glEnable(GL_DEPTH_TEST);

    chunk_table_s chunk_table = chunk_table_create();
    chunk_table_set(&chunk_table, chunk_create(-1, -1, -1));
    chunk_s *chunk = chunk_table_get(&chunk_table, -1, -1, -1);
    chunk_table_destroy(&chunk_table);

    const shader_s shader = shader_create("res/shd/cube.vert", "res/shd/cube.frag");
    shader_bind(&shader);

    mat4 proj = GLM_MAT4_IDENTITY_INIT;
    glm_perspective(glm_rad(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f, proj);
    shader_set_mat4(&shader, "u_proj", proj);

    texture_s texture = texture_load("res/treasurelands_atlas.png");
    texture_bind(&texture);

    vec3 camera_position = {0.0f, 0.0f, 0.0f};
    vec3 camera_front = {0.0f, 0.0f, -1.0f};
    vec3 camera_up = {0.0f, 1.0f, 0.0f};

    mat4 view = GLM_MAT4_IDENTITY_INIT;

    f32 pitch = 0.0f, yaw = -90.0f;

    while (window_is_good()) {
        if (window_is_key_pressed(GLFW_KEY_ESCAPE)) {
            break;
        }

        const f32 camera_speed = 2.5f * delta_time();
        vec3 delta_position = {0.0f, 0.0f, 0.0f};
        glm_vec3_muladds(camera_front, camera_speed, delta_position);

        if (window_is_key_down(GLFW_KEY_W)) {
            glm_vec3_add(camera_position, delta_position, camera_position);
        }

        if (window_is_key_down(GLFW_KEY_S)) {
            glm_vec3_sub(camera_position, delta_position, camera_position);
        }

        vec3 direction = {0.0f, 0.0f, 0.0f};
        vec3 camera_right = {0.0f, 0.0f, 0.0f};
        glm_cross(camera_front, camera_up, camera_right);
        glm_normalize(camera_right);
        glm_vec3_muladds(camera_right, camera_speed, direction);

        if (window_is_key_down(GLFW_KEY_A)) {
            glm_vec3_sub(camera_position, direction, camera_position);
        }

        if (window_is_key_down(GLFW_KEY_D)) {
            glm_vec3_add(camera_position, direction, camera_position);
        }

        if (window.mouse.delta_x != 0 || window.mouse.delta_y != 0) {
            static constexpr f32 sensitivity = 0.1f;
            f32 x_offset = window.mouse.delta_x * sensitivity;
            f32 y_offset = window.mouse.delta_y * sensitivity;

            yaw += x_offset;
            pitch += y_offset;

            pitch = glm_clamp(pitch, -90.0f, 90.0f);

            vec3 dir = {
                cosf(glm_rad(yaw)) * cosf(glm_rad(pitch)),
                sinf(glm_rad(pitch)),
                sinf(glm_rad(yaw)) * cosf(glm_rad(pitch))
            };
            glm_normalize(dir);
            memcpy(camera_front, dir, sizeof(dir));
        }

        vec3 camera_center = {0.0f, 0.0f, 0.0f};
        glm_vec3_add(camera_position, camera_front, camera_center);
        glm_lookat(camera_position, camera_center, camera_up, view);
        shader_set_mat4(&shader, "u_view", view);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.8f, 0.6f, 0.1f, 1.0f);

        level_blit(&context->level);

        window_display();
    }

    level_destroy(&context->level);
    window_destroy();
}
