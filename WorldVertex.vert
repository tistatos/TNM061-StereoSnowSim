#version 330 core

layout(location = 0) in vec2 textureCoordinates;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec3 vertexPositions;

//model, view, projection
uniform mat4 MVP;

out vec2 UV;

void main()
{
	gl_Position = MVP * vec4(vertexPositions, 1.0);
	UV = textureCoordinates;
}