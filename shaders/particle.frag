#version 330 core

uniform sampler2D tex;

in vec2 UV;
in float camDistance;
in float fadeDistance;
in float life;
// Ouput data
out vec4 color;


void main(){
	// Output color = color of the texture at the specified UV
	color = texture(tex, UV.st);

	float alpha = (life / 5.0)*color.a;
	alpha = smoothstep(fadeDistance/4.0, fadeDistance, alpha-(1-camDistance)) * alpha;

	color.a = max(0, alpha);
	// color = vec4(life);
}
