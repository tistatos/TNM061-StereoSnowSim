#version 330 core

// uniform sampler2D tex;

in vec2 UV;

out vec4 color;

void main()
{
	vec4 nice = vec4(1.0,0.5,0.5,1.0);
	color = nice;
}