#version 460 core

in vec2 v_uv;

out vec4 o_color;

uniform sampler2D tex;

void main() {
    o_color = texture(tex, v_uv);
}