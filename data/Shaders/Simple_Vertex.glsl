#version 330 core

layout(location=0) in vec3 inVertexPosition;
layout(location=1) in vec2 inTexturePosition;

out vec2 passTexturePosition;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position =	projection * view * model * 
					vec4(inVertexPosition.x, inVertexPosition.y, inVertexPosition.z, 1.0);

	passTexturePosition = inTexturePosition;
}
