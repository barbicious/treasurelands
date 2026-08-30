#include "shader.h"

#include <stdio.h>
#include <stdlib.h>

#include "glad/glad.h"

u32 load_shader(const char *path, const u32 type) {
    u32 shader = glCreateShader(type);

    FILE *file = fopen(path, "r");
    if (file == nullptr) {
        perror("Error opening shader file");
        exit(EXIT_FAILURE);
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to end of shader file");
        exit(EXIT_FAILURE);
    }

    i64 size = ftell(file);
    if (size < 0) {
        perror("Error reading size of shader file");
        exit(EXIT_FAILURE);
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("Error seeking to start of shader file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char *buffer = malloc(size + 1);
    if (buffer == nullptr) {
        perror("Error allocating shader buffer");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    usize bytes_read = fread(buffer, 1, size, file);
    if (bytes_read < (usize) size && ferror(file)) {
        perror("Error reading shader file");
        free(buffer);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';
    fclose(file);

    const char *src = buffer;

    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    i32 success = GL_TRUE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        char info_log[1024];
        glGetShaderInfoLog(shader, 1024, nullptr, info_log);
        printf("%s\n", info_log);
    }

    free(buffer);

    return shader;
}

shader_s shader_create(const char *vs_path, const char *fs_path) {
    shader_s shader = {0};

    u32 vs = load_shader(vs_path, GL_VERTEX_SHADER);
    u32 fs = load_shader(fs_path, GL_FRAGMENT_SHADER);

    shader.id = glCreateProgram();
    glAttachShader(shader.id, vs);
    glAttachShader(shader.id, fs);
    glLinkProgram(shader.id);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return shader;
}

void shader_destroy(const shader_s *shader) {
    glDeleteProgram(shader->id);
}

void shader_bind(const shader_s *shader) {
    glUseProgram(shader->id);
}

void shader_unbind() {
    glUseProgram(0);
}

void shader_set_mat4(const shader_s *shader, const char *name, const mat4 m) {
    glUniformMatrix4fv(glGetUniformLocation(shader->id, name), 1, GL_FALSE, &m[0][0]);
}
