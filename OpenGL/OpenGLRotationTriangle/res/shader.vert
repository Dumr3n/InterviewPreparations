#version 330 core

layout (location = 0) in vec3 VertexPos;
layout (location = 1) in vec3 VertexColor;

out vec3 Color;

uniform float scr_aspect;
uniform float angle;

void main() {
    vec4 newPosition;
    newPosition.x = (VertexPos.x*cos(angle) - VertexPos.y*sin(angle))*scr_aspect;
    newPosition.y = VertexPos.x*sin(angle) + VertexPos.y*cos(angle);
    newPosition.z = VertexPos.z;
    newPosition.w = 1.0;
    
    gl_Position = newPosition;
    Color = VertexColor;
}