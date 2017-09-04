#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 texcoord;

in mat4 projection;
in mat4 view;
in mat4 model;

out vec2 Texcoord;

void main()
{
	gl_Position = /*projection * view **/ model * vec4(pos, 1.0);
    Texcoord = texcoord;
}
