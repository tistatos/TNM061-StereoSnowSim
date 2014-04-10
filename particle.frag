#version 330 core

// Ouput data
out vec4 color;


void main(){
	// Output color = color of the texture at the specified UV
	color = vec4(1.0f,1.0,1.0,0.8f);
}