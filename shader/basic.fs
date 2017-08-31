#version 330 core

in vec2 Texcoord;

out vec4 outColor;

uniform vec3 uniColor;
uniform sampler2D tex;

void main()
{
	outColor = texture(tex, Texcoord) * vec4(uniColor, 1.0);
}
