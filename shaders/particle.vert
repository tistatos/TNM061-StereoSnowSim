#version 330 core

layout(location = 0) in vec3 squareVertices; // Data from billboard
//layout(location = 1) in vec4 xyzs; //Particle Matrix
layout(location = 1) in mat4 transformmatrix;

out vec2 UV;
out float camDistance;
uniform mat4 VP; // Model-View-Projection matrix, but without the Model (the position is in BillboardPos; the orientation depends on the camera)

void main()
{
	mat4 M = transformmatrix;
	float particleSize = .2;
	vec4 xyzs = transformmatrix[3];
	vec3 particleCenter_wordspace = xyzs.xyz;
	vec3 CameraRight_worldspace = vec3(1.0f,0.0,0.0);
	vec3 CameraUp_worldspace = vec3(0.0f,1.0f,0.0f);

	vec3 vertexPosition_worldspace =
		squareVertices * particleSize;
	// Output position of the vertex
	gl_Position = VP * M * vec4(vertexPosition_worldspace, 1.0f);
	camDistance = length(vec3(xyzs));
	// UV of the vertex. No special space for this one.
	UV = squareVertices.xy + vec2(0.5, 0.5);
}