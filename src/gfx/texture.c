#include "texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glad/glad.h"

texture_s texture_load(const char *path) {
    texture_s texture = {0};

    glGenTextures(1, &texture.id);
    texture_bind(&texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    i32 channels = 0;
    const u8 *data = stbi_load(path, &texture.width, &texture.height, &channels, 4);
    if (data == nullptr) {
        printf("failed to load texture %s\nError: %s", path, stbi_failure_reason());
    } else {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    return texture;
}

void texture_destroy(texture_s *texture) {
    glDeleteTextures(1, &texture->id);
}

void texture_bind(texture_s *texture) {
    glBindTexture(GL_TEXTURE_2D, texture->id);
}

void texture_unbind(texture_s *texture) {
    glBindTexture(GL_TEXTURE_2D, 0);
}
