#include "vao.h"

#include "vbo.h"
#include "glad/glad.h"

vao_s vao_create() {
    vao_s vao = {0};
    glGenVertexArrays(1, &vao.id);
    return vao;
}

void vao_destroy(const vao_s *vao) {
    glDeleteVertexArrays(1, &vao->id);
}

void vao_bind(const vao_s *vao) {
    glBindVertexArray(vao->id);
}

void vao_unbind() {
    glBindVertexArray(0);
}

void vao_attribute(const u32 index, const i32 size, const i32 stride, const u32 offset) {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, (void *) offset);
}
