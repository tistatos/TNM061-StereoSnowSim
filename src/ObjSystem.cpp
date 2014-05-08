#include <iostream>
#include <stdio.h>
#include "ObjSystem.h"
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>

Object::Object(sgct::Engine* engine)
{
	mEngine = engine;
	nVertices = 0;
	nTriangles = 0;
	vertexList = nullptr;
	triangleList = nullptr;
	vertexBuffer = 0;
	indexBuffer = 0;
	mMatrixLocation = -1;
	transMatrix = glm::mat4(1.0f);
}

/* 
	Taken from https://code.google.com/p/opengl-tutorial-org/source/browse/common/objloader.cpp
	and from   https://code.google.com/p/opengl-tutorial-org/source/browse/tutorial07_model_loading/tutorial07.cpp
	Inputs:
		filename, the obj-file.
*/
void Object::loadObj(char* filename)
{
	FILE *objfile;

	int numverts = 0;
	int numnormals = 0;
	int numtexcoords = 0;
	int numfaces = 0;
	int i_v = 0;
	int i_n = 0;
	int i_t = 0;
	int i_f = 0;
	float *verts, *normals, *texcoords;

	char line[256];
	char tag[3];
	int v1,v2,v3,n1,n2,n3,t1,t2,t3;
	int numargs, readerror, currentv;

	readerror = 0;

	objfile = fopen(filename, "r");

	if(!objfile) {
        cout << "File not found" << filename;
		readerror = 1;
	}

	// Scan through the file to count the number of data elements
	while(fgets(line, 256, objfile)) {
		sscanf(line, "%2s ", tag);
		if(!strcmp(tag, "v")) numverts++;
		else if(!strcmp(tag, "vn")) numnormals++;
		else if(!strcmp(tag, "vt")) numtexcoords++;
		else if(!strcmp(tag, "f")) numfaces++;
		//else printf("Ignoring line starting with \"%s\"\n", tag);
	}

	printf("loadObj(\"%s\"): found %d vertices, %d normals, %d texcoords, %d faces.\n",
		filename, numverts, numnormals, numtexcoords, numfaces);

	verts = (float*)malloc(3*numverts*sizeof(float));
	normals = (float*)malloc(3*numnormals*sizeof(float));
	texcoords = (float*)malloc(2*numtexcoords*sizeof(float));

	vertexList = (float*)malloc(8*3*numfaces*sizeof(float));
	triangleList = (unsigned int*)malloc(3*numfaces*sizeof(unsigned int));
	nVertices = 3*numfaces;
	nTriangles = numfaces;

	rewind(objfile); // Start from the top again to read data

	while(fgets(line, 256, objfile)) {
		tag[0] = '\0';
		sscanf(line, "%2s ", tag);
		if(!strcmp(tag, "v")) {
//			printf("Reading vertex %d\n", i_v+1);
			numargs = sscanf(line, "v %f %f %f",
				&verts[3*i_v], &verts[3*i_v+1], &verts[3*i_v+2]);
			if(numargs != 3) {
				printf("Malformed vertex data found at vertex %d.\n", i_v+1);
				printf("Aborting.\n");
				readerror = 1;
				break;
			}
//			printf("Read vertex coord %d: %8.2f %8.2f %8.2f\n",
//			i_v, verts[3*i_v], verts[3*i_v+1], verts[3*i_v+2]);
			i_v++;
		}
		else if(!strcmp(tag, "vn")) {
//			printf("Reading normal %d\n", i_n+1);
			numargs = sscanf(line, "vn %f %f %f",
				&normals[3*i_n], &normals[3*i_n+1], &normals[3*i_n+2]);
			if(numargs != 3) {
				printf("Malformed normal data found at normal %d.\n", i_n+1);
				printf("Aborting.\n");
				readerror = 1;
				break;
			}
			i_n++;
		}
		else if(!strcmp(tag, "vt"))  {
//          printf("Reading texcoord %d\n", i_t+1);
			numargs = sscanf(line, "vt %f %f",
				&texcoords[2*i_t], &texcoords[2*i_t+1]);
			if(numargs != 2) {
				printf("Malformed texcoord data found at texcoord %d.\n", i_t+1);
				printf("Aborting.\n");
				readerror = 1;
				break;
			}
			i_t++;
		}
		else if(!strcmp(tag, "f")) {
//			printf("Reading face %d\n", i_f+1);
			numargs = sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d",
				&v1, &t1, &n1, &v2, &t2, &n2, &v3, &t3, &n3);
			if(numargs != 9) {
				printf("Malformed face data found at face %d.\n", i_f+1);
				printf("Aborting.\n");
				readerror = 1;
				break;
			}
//			printf("Read vertex data %d/%d/%d %d/%d/%d %d/%d/%d\n",
//			v1, t1, n1, v2, t2, n2, v3, t3, n3);
			v1--; v2--; v3--; n1--; n2--; n3--; t1--; t2--; t3--;
			currentv = 8*3*i_f;
			vertexList[currentv] = verts[3*v1];
			vertexList[currentv+1] = verts[3*v1+1];
			vertexList[currentv+2] = verts[3*v1+2];
			vertexList[currentv+3] = normals[3*n1];
			vertexList[currentv+4] = normals[3*n1+1];
			vertexList[currentv+5] = normals[3*n1+2];
			vertexList[currentv+6] = texcoords[2*t1];
			vertexList[currentv+7] = texcoords[2*t1+1];
			vertexList[currentv+8] = verts[3*v2];
			vertexList[currentv+9] = verts[3*v2+1];
			vertexList[currentv+10] = verts[3*v2+2];
			vertexList[currentv+11] = normals[3*n2];
			vertexList[currentv+12] = normals[3*n2+1];
			vertexList[currentv+13] = normals[3*n2+2];
			vertexList[currentv+14] = texcoords[2*t2];
			vertexList[currentv+15] = texcoords[2*t2+1];
			vertexList[currentv+16] = verts[3*v3];
			vertexList[currentv+17] = verts[3*v3+1];
			vertexList[currentv+18] = verts[3*v3+2];
			vertexList[currentv+19] = normals[3*n3];
			vertexList[currentv+20] = normals[3*n3+1];
			vertexList[currentv+21] = normals[3*n3+2];
			vertexList[currentv+22] = texcoords[2*t3];
			vertexList[currentv+23] = texcoords[2*t3+1];
			triangleList[3*i_f] = 3*i_f;
			triangleList[3*i_f+1] = 3*i_f+1;
			triangleList[3*i_f+2] = 3*i_f+2;
			i_f++;
		};
	}

	// Free the temporary arrays we created
	free(verts);
	free(normals);
	free(texcoords);
	fclose(objfile);

	if(readerror) { // Delete corrupt data and bail out if a read error occured
        cout << "Mesh read error. No mesh data generated";
		return;
	}
	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

	// Generate one vertex array object (VAO) and bind it
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	// Generate two buffer IDs
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

 	// Activate the vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
 	// Present our vertex coordinates to OpenGL
	glBufferData(GL_ARRAY_BUFFER,
		8*nVertices * sizeof(GLfloat), vertexList, GL_STATIC_DRAW);

	// Specify how many attribute arrays we have in our VAO
	glEnableVertexAttribArray(0); // Vertex coordinates
	glEnableVertexAttribArray(1); // Normals
	glEnableVertexAttribArray(2); // Texture coordinates
	// Specify how OpenGL should interpret the vertex buffer data:
	// Attributes 0, 1, 2 (must match the lines above and the layout in the shader)
	// Number of dimensions (3 means vec3 in the shader, 2 means vec2)
	// Type GL_FLOAT
	// Not normalized (GL_FALSE)
	// Stride 8 (interleaved array with 8 floats per vertex)
	// Array buffer offset 0, 3, 6 (offset into first vertex)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
		8*sizeof(GLfloat), (void*)0); // xyz coordinates
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
		8*sizeof(GLfloat), (void*)(3*sizeof(GLfloat))); // normals
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
		8*sizeof(GLfloat), (void*)(6*sizeof(GLfloat))); // texcoords

 	// Activate the index buffer
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
 	// Present our vertex indices to OpenGL
 	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
	 	3*nTriangles*sizeof(GLuint), triangleList, GL_STATIC_DRAW);

	// Deactivate (unbind) the VAO and the buffers again.
	// Do NOT unbind the buffers while the VAO is still bound.
	// The index buffer is an essential part of the VAO state.
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

 	//set up backface culling
	glCullFace(GL_BACK);
	//define frontfacing polygons
	glFrontFace(GL_CW);

	sgct::TextureManager::instance()->setAnisotropicFilterSize(8.0f);
	sgct::TextureManager::instance()->setCompression(sgct::TextureManager::S3TC_DXT);
	sgct::TextureManager::instance()->loadTexure(mTextureHandle, "object", "road/road.png", true);

	//Create shader
	sgct::ShaderManager::instance()->addShaderProgram("object", "object.vert", "object.frag");

	mMatrixLocation = sgct::ShaderManager::instance()->getShaderProgram( "object").getUniformLocation( "MVP" );
	mTransformLocation = sgct::ShaderManager::instance()->getShaderProgram("object").getUniformLocation( "P" );

	//Unbind shader
	sgct::ShaderManager::instance()->unBindShaderProgram();

	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);	

	return;
}

void Object::scale(float sx, float sy, float sz)
{
	glm::mat4 s = glm::scale(sx,sy,sz);
	transMatrix = s * transMatrix;

	cout << "Scaled object" << endl;
}

void Object::translate(float tx, float ty, float tz)
{
	glm::mat4 t = glm::translate(tx,ty,tz);
	transMatrix = t * transMatrix;
}

void Object::draw()
{
	//do depth comparisons and pdate the depth buffer
	glEnable(GL_DEPTH_TEST);
	//cull polygons not shown in window
	glEnable(GL_CULL_FACE);
	//Draws in other direction
	glFrontFace(GL_CCW);

	//create a scene matrix incase we want movement
	glm::mat4 sceneMatrix = glm::mat4(1.0f);
	
	glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix() * sceneMatrix;
	
	glm::mat4 T = glm::translate(0.0f, -7.0f, -0.0f);
	glm::mat4 S = glm::scale(0.2f,0.2f,0.2f);

	glm::mat4 P = S * T;

	//select active texture unit
	glActiveTexture(GL_TEXTURE0);
	//bind a named texture to a texturing target
	glBindTexture(GL_TEXTURE_2D, sgct::TextureManager::instance()->getTextureByHandle(mTextureHandle));
	
	sgct::ShaderManager::instance()->bindShaderProgram( "object" );
	
	glUniformMatrix4fv(mMatrixLocation, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(mTransformLocation, 1, GL_FALSE, &transMatrix[0][0]);
	glBindVertexArray(vertexArrayObject);
	glDrawElements(GL_TRIANGLES, 3 * nTriangles, GL_UNSIGNED_INT, (void*)0);
	// (mode, vertex count, type, element array buffer offset)
	glBindVertexArray(0);
	
	sgct::ShaderManager::instance()->unBindShaderProgram();

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

void Object::deleteObject()
{
	//returns GL_TRUE if GLuint object is currently the name of a render object
	if(glIsVertexArray(vertexArrayObject))
	{
		//the number of objects to be deleted from a specified array
		glDeleteVertexArrays(1, &vertexArrayObject);
	}

	vertexArrayObject = 0;

	//returns GL_TRUE if GLuint object is currently the name of a buffer object
	if(glIsBuffer(vertexBuffer))
	{
		//the number of objects to be deleted from a specified array
		glDeleteBuffers(1, &vertexBuffer);
	}

	vertexBuffer = 0;

	//returns GL_TRUE if GLuint object is currently the name of a buffer object
	if(glIsBuffer(indexBuffer))
	{
		//the number of objects to be deleted from a specified array
		glDeleteBuffers(1, &indexBuffer);
	}

	indexBuffer = 0;

	if(vertexList)
	{
		delete[] vertexList;
	}

	if(triangleList)
	{
		delete[] triangleList;
	}

	nVertices = 0;
	nTriangles = 0;
}