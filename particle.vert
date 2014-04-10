#version 330 core

layout(location = 0) in vec3 squareVertices; // Data from billboard
layout(location = 1) in vec4 xyzs; //Particle position and
//layout(location = 2) in vec4 color; // Position of the center of the particule and size of the square

// Values that stay constant for the whole mesh.
uniform mat4 VP; // Model-View-Projection matrix, but without the Model (the position is in BillboardPos; the orientation depends on the camera)

void main()
{
	float particleSize = xyzs.w; // because we encoded it this way.

	vec3 particleCenter_wordspace = xyzs.xyz;
	vec3 CameraRight_worldspace = vec3(1,0,0);
	vec3 CameraUp_worldspace = vec3(0,1,0);

	vec3 vertexPosition_worldspace =
		particleCenter_wordspace
		+ CameraRight_worldspace * squareVertices.x * particleSize
		+ CameraUp_worldspace * squareVertices.y * particleSize;
	// Output position of the vertex
	gl_Position = VP * vec4(vertexPosition_worldspace, 1.0f);

	// UV of the vertex. No special space for this one.
}