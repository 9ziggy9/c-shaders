#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec4 clr; // vec4 for alpha

// contrast with varying keyword
out vec3 out_clr;

void main() {
    gl_Position = vec4(pos, 1.0); // homogeneous coordinates
    out_clr = clr;
}
