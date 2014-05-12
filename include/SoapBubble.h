#ifndef __SOAP_BUBBLE_H__
#define __SOAP_BUBBLE_H__

#include "sgct.h"
#include "HelperFunctions.h"

class SoapBubble
{
	public:
		SoapBubble(sgct::Engine* engine);
		void clean();
		void createSphere(float radius, int segments);
		void drawBubble();
	private:
		sgct::Engine* mEngine;
		GLuint vertexArrayObject; //för Nvidia-kort
		int nVertices; //number of vertices in the vertex array
		int nTriangles; //number of triangles in the index array
		GLfloat *vertexList; //vertex array: x y z nx ny nz s t
		GLuint *triangleList; //index array
		GLuint vertexBuffer; //buffer id to bind to GL_ARRAY_BUFFER
		GLuint indexBuffer; //buffer id to bind to GL_ELEMENT_ARRAY_BUFFER
		GLint mMatrixLocation;
		size_t mTextureHandle;
};

#endif