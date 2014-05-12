#version 330 core

uniform sampler2D tex;

in vec4 UV;

out vec4 color;

void main()
{
	vec2 longitudeLatitude = vec2((atan(UV.y, UV.x) / 3.1415926 + 1.0) * 0.5, (asin(UV.z) / 3.1415926 + 0.5));
	color = texture(tex, longitudeLatitude);
	color.a = 0.7;
}
