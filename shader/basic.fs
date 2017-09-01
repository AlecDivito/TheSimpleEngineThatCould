#version 330 core

in vec2 Texcoord;

out vec4 outColor;

uniform vec3 uniColor;
uniform int isSpriteNull;
uniform sampler2D tex;

void main()
{
    if (isSpriteNull == 1)
        outColor =  vec4(uniColor, 1.0);
    else
    	outColor = texture(tex, Texcoord) * vec4(uniColor, 1.0);
}
