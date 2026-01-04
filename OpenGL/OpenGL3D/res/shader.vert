#version 330 core

layout (location = 0) in vec3 VertexPos;
layout (location = 1) in vec2 VertexTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec2 TexCoord;

void main() {
    gl_Position = proj * view * model * vec4(VertexPos, 1.0);
    TexCoord = VertexTex;
}