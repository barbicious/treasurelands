#include "vbo.h"

#include "glad/glad.h"

vbo_s vbo_create() {
    vbo_s vbo = {0};
    glGenBuffers(1, &vbo.id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
}

void vbo_destroy(const vbo_s *vbo) {
    glDeleteBuffers(1, &vbo->id);
}

void vbo_bind(const vbo_s *vbo) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo->id);
}

void vbo_unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void vbo_submit_data(const vbo_s *vbo, const i32 size, const void *data) {
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
