#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(sgct::Engine* engine)
{
	mEngine = engine;
	mInitialized = false;
	mBillBoardVB = 0;
	mParticlePositionBuffer = 0;
}

void ParticleSystem::initialize()
{
	static const GLfloat vertexBufferData[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f
	};

	glGenBuffers(1, &mBillBoardVB);
	glBindBuffer(GL_ARRAY_BUFFER, mBillBoardVB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), 
				 vertexBufferData, GL_STATIC_DRAW);

	glGenBuffers(1, &mParticlePositionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
	glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES*4*sizeof(GLubyte),
				 NULL, GL_STREAM_DRAW);

	mInitialized = true;
}

void ParticleSystem::draw()
{
	if(mInitialized)
	{

	}
}

void ParticleSystem::destroy()
{
	if(mInitialized)
	{
		glDeleteBuffers(1, &mBillBoardVB);
		glDeleteBuffers(1, &mParticlePositionBuffer);
		mInitialized = false;
	}
}
