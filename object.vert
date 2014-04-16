#version 330 core

layout(location = 0) in vec3 vertexPositions;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec2 textureCoordinates;

//model, view, projection
uniform mat4 MVP;
uniform mat4 P;

out vec2 UV;

void main()
{
	gl_Position = ( P * MVP ) * vec4(vertexPositions, 1.0);
	UV = textureCoordinates;
}