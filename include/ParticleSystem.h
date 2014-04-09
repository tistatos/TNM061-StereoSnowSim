#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "sgct.h"

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mVelocity;

	float mSize;
	float mLife;
};

const int MAX_PARTICLES = 1000;

class ParticleSystem
{
	public:
		ParticleSystem(sgct::Engine* engine);
		void initialize();
		void draw(double delta);
		void destroy();
		void move(double delta);
	private:
		int findLastParticle();


		bool mInitialized;
		sgct::Engine* mEngine;
		Particle mParticles[MAX_PARTICLES];
		int mLastUsedParticle;
		GLuint mVertexArray;
		GLint mMatrixLoc;
		GLfloat* g_particule_position_size_data;
		GLuint mBillBoardVB;
		GLuint mParticlePositionBuffer;
		GLuint mParticleColorBuffer;
};

#endif
