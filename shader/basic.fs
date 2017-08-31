#version 330 core

out vec4 outColor;

uniform vec3 uniColor;

void main()
{
	outColor = vec4(uniColor, 1.0); // white
}
