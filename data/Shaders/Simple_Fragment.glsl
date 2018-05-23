#version 330 core

in vec2 passTexturePosition;

out vec4 color;

uniform sampler2D ourTexture;

uniform float time;

void main()
{
	color = texture(ourTexture, passTexturePosition);// * sin(time);
}