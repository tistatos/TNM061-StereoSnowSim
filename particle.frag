#version 330 core


uniform sampler2D tex;

in vec2 UV;
// Ouput data
out vec4 color;


void main(){
	// Output color = color of the texture at the specified UV
	color = texture(tex, UV.st);
}