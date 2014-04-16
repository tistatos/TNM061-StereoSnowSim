#ifndef __OBJ_SYSTEM_H__
#define __OBJ_SYSTEM_H__

#include <vector>
#include "sgct.h"

using namespace std;

class Object
{
	public:
		Object(sgct::Engine* engine);
		void initialize();
		void loadObj(char* filename);
		void deleteObject();
		void draw();
	private:
		sgct::Engine* mEngine;
		std::vector<glm::vec3>* vertices;
		std::vector<glm::vec2>* uvs;
		std::vector<glm::vec3>* normals;
		//GLint mMatrixLoc; /// matrix loc in shader
		//GLuint mVertexArray; /// pointer for vertex array on GPU
		GLuint vertexArrayObject; //för Nvidia-kort
		int nVertices; //number of vertices in the vertex array
		int nTriangles; //number of triangles in the index array
		GLfloat *vertexList; //vertex array: x y z nx ny nz s t
		GLuint *triangleList; //index array
		GLuint vertexBuffer; //buffer id to bind to GL_ARRAY_BUFFER
		GLuint indexBuffer; //buffer id to bind to GL_ELEMENT_ARRAY_BUFFER
		GLint mMatrixLocation;
};

#endif