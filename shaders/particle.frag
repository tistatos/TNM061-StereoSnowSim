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
	float alpha = smoothstep(fadeDistance/4.0,fadeDistance,color.a-(1-camDistance))*color.a;
	color.a = max(0, alpha);
	// color = vec4(life);
}
