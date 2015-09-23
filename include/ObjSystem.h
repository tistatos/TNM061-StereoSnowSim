#ifndef __OBJ_SYSTEM_H__
#define __OBJ_SYSTEM_H__

#include <vector>
#include "sgct.h"
#include "Texture.h"

using namespace std;

class Object
{
	public:
		Object(sgct::Engine* engine);
		void initialize();
		void loadObj(char* filename, string texture);
		void deleteObject();
		void draw();

		void scale(float sx, float sy, float sz);
		void translate(float tx, float ty, float tz);
		void rotate(float ang, float rx, float ry, float rz);

		GLfloat* getVertexList();
		int getVertexCount();
		GLuint getIndexBuffer();
		GLuint getVertexBuffer();

	private:
		sgct::Engine* mEngine;
		Texture mTexture; //Strcut with Texture data

		GLuint vertexArrayObject; //för Nvidia-kort
		int nVertices; //number of vertices in the vertex array
		int nTriangles; //number of triangles in the index array
		GLfloat *vertexList; //vertex array: x y z nx ny nz s t
		GLuint *triangleList; //index array
		GLuint vertexBuffer; //buffer id to bind to GL_ARRAY_BUFFER
		GLuint indexBuffer; //buffer id to bind to GL_ELEMENT_ARRAY_BUFFER
		GLint mMatrixLocation;
		GLint mTransformLocation; // Location of transformation matrix
		size_t mTextureHandle;

		glm::mat4 transMatrix;
};

#endif