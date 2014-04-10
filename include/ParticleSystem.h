#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include <vector>
#include "sgct.h"

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mVelocity;

	float mSize = 1.0f;
	float mLife;
};

const int MAX_PARTICLES = 100;

class ParticleSystem
{
	public:
		ParticleSystem(sgct::Engine* engine);
		void initialize();
		void draw(double delta);
		void destroy();
		void move(double delta);
		void reset(int index);
		void reset(Particle& p);
	private:
		int findLastParticle();


		bool mInitialized;
		sgct::Engine* mEngine;
		Particle mParticles[MAX_PARTICLES];
		int mLastUsedParticle;
		GLuint mVertexArray;
		GLuint mBillBoardVB;
		GLuint mParticlePositionBuffer;
		GLuint mParticleColorBuffer;
		GLint mMatrixLoc;
		GLfloat* mParticlePositionData;
};


#endif
