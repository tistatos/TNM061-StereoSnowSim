#include <stdlib.h>
#include <math.h>
#include "SoapBubble.h"

SoapBubble::SoapBubble(sgct::Engine* engine)
{
	mEngine = engine;
	vertexArrayObject = 0;
	nVertices = 0;
	nTriangles = 0;
	vertexList = nullptr;
	triangleList = nullptr;
	vertexBuffer = 0;
	indexBuffer = 0;
	mMatrixLocation = -1;
}

void SoapBubble::clean()
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

void SoapBubble::createSphere(float radius, int segments)
{
	float x, y, z, r;
	double theta, phi;
	int vSegments, hSegments;
	int stride = 8, base; //(x y z nx ny nz s t)

	clean();

	vSegments = segments;
	if(vSegments < 2)
	{
		vSegments = 2;
	}
	hSegments = vSegments * 2;
	nVertices = 1 + (vSegments - 1) * (hSegments + 1) + 1;
	nTriangles = hSegments + (vSegments - 2) * hSegments * 2 + hSegments;
	vertexList = new float[nVertices * stride];
	triangleList = new GLuint[nTriangles * 3];

	//first vertex: top pole, y is "up" (might be superduper wrong)
	vertexList[0] = 0.0f;
	vertexList[1] = radius;
	vertexList[2] = 0.0f;
	vertexList[3] = 0.0f;
	vertexList[4] = 1.0f;
	vertexList[5] = 0.0f;
	vertexList[6] = 0.5f;
	vertexList[7] = 1.0f;

	//last vertex: bottom pole
	base = (nVertices - 1) * stride;

	vertexList[base] = 0.0f;
	vertexList[base+1] = -radius;
	vertexList[base+2] = 0.0f;
	vertexList[base+3] = 0.0f;
	vertexList[base+4] = -1.0f;
	vertexList[base+5] = 0.0f;
	vertexList[base+6] = 0.5f;
	vertexList[base+7] = 0.0f;

	//all other vertices
	for(int i = 0; i < vSegments - 1; i++)
	{
		theta = (double)(i+1) / vSegments * PI;
		y = cos(theta);
		r = sin(theta);

		for(int j = 0; j <= hSegments; j++)
		{
			phi = (double)j / hSegments * 2.0 * PI;
			x = r * cos(phi);
			z = r * sin(phi);
			base = (1 + i * (hSegments + 1) + j) * stride;

			vertexList[base] = radius * x;
			vertexList[base+1] = radius * y;
			vertexList[base+2] = radius * z;
			vertexList[base+3] = x;
			vertexList[base+4] = y;
			vertexList[base+5] = z;
			vertexList[base+6] = (float)j/hSegments;
			vertexList[base+7] = 1.0f - (float)(i + 1) / vSegments;
		}

	}

	//index, top cap
	for(int i = 0; i < hSegments; i++)
	{
		triangleList[3*i] = 0;
		triangleList[3*i+1] = 1 + i;
		triangleList[3*i+2] = 2 + i;
	}

	//middle part
	for(int i = 0; i < vSegments - 2; i++)
	{
		for(int j = 0; j < hSegments; j++)
		{
			base = 3 * (hSegments + 2 * (i * hSegments + j));
			int i0 = 1 + i * (hSegments + 1) + j;

			triangleList[base] = i0;
			triangleList[base+1] = i0 + hSegments + 1;
			triangleList[base+2] = i0 + 1;
			triangleList[base+3] = i0 + 1;
			triangleList[base+4] = i0 + hSegments + 1;
			triangleList[base+5] = i0 + hSegments + 2;
		}
	}

	//bottom cap
	base = 3 * (hSegments + 2 * (vSegments - 2) * hSegments);
	for(int i = 0; i < hSegments; i++)
	{
		triangleList[base+3*i] = nVertices - 1;
		triangleList[base+3*i+1] = nVertices - 2 - i;
		triangleList[base+3*i+2] = nVertices - 3 - i;

	}


	//generate one vertex array object and bind it
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	//generate two buffer id:s
	glGenBuffers(1, &vertexBuffer);
	glGenBuffers(1, &indexBuffer);

	//activate the vertexbuffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	//present our vertexcoordinates to opengl
	glBufferData(GL_ARRAY_BUFFER, stride * nVertices * sizeof(GLfloat), vertexList, GL_STATIC_DRAW);
	//specify how many attribute arrays we have in our vertex array object
	glEnableVertexAttribArray(0); //vertex coordinates
	glEnableVertexAttribArray(1); //normals
	glEnableVertexAttribArray(2); //texture coordinates

	//attributes 0,1,2 must match the lines above and the layout in the shader
	//number of dimensions (3 equals a vec3 and 2 a vec2)
	//the typ is GLfloat and it is not normalized = GL_FALSE
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

	//activate the indexBuffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	//present our vertex indices to opengl
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * nTriangles * sizeof(GLuint), triangleList, GL_STATIC_DRAW);

	//unbind the vertex array object and buffers
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	sgct::TextureManager::instance()->setAnisotropicFilterSize(8.0f);
	sgct::TextureManager::instance()->setCompression(sgct::TextureManager::S3TC_DXT);
	sgct::TextureManager::instance()->loadTexure(mTextureHandle, "bubble", "bubble.png", true);

	//Create shader
	sgct::ShaderManager::instance()->addShaderProgram("bubble", "bubble.vert", "bubble.frag");

	//Bind shader and get location of MVP matrix
	sgct::ShaderManager::instance()->bindShaderProgram("bubble");

	mMatrixLocation = sgct::ShaderManager::instance()->getShaderProgram("bubble").getUniformLocation( "MVP" );

	//Unbind shader
	sgct::ShaderManager::instance()->unBindShaderProgram();

}

void SoapBubble::drawBubble()
{
	//do depth comparisons and pdate the depth buffer
	glEnable(GL_DEPTH_TEST);
	//cull polygons not shown in window
	glEnable(GL_CULL_FACE);
	//add opacity attributes
	glEnable(GL_BLEND);

	//create a scene matrix incase we want movement
	glm::mat4 sceneMatrix = glm::mat4(1.0f);
	sceneMatrix = glm::translate(sceneMatrix, glm::vec3(0.0f, 0.0f, -5.0f));

	glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix() * sceneMatrix;

	//select active texture unit
	glActiveTexture(GL_TEXTURE0);
	//bind a named texture to a texturing target
	glBindTexture(GL_TEXTURE_2D, sgct::TextureManager::instance()->getTextureByHandle(mTextureHandle));

	sgct::ShaderManager::instance()->bindShaderProgram("bubble");

	glUniformMatrix4fv(mMatrixLocation, 1, GL_FALSE, &MVP[0][0]);

	glBindVertexArray(vertexArrayObject);

	glDrawElements(GL_TRIANGLES, 3 * nTriangles, GL_UNSIGNED_INT, (void*)0);

	sgct::ShaderManager::instance()->unBindShaderProgram();

	glBindVertexArray(0);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	glDisable(GL_BLEND);
}

