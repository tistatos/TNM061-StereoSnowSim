#ifndef __PARTICLE_H__
#define __PARTICLE_H__

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mVelocity;

	float mSize;
	float mLife;
};

#endif
