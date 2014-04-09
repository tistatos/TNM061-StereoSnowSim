#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "sgct.h"

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mSpeed;

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
		bool mInitialized;
		sgct::Engine* mEngine;
		Particle mParticles[MAX_PARTICLES];
		GLuint mBillBoardVB;
		GLuint mParticlePositionBuffer;
};

#endif
