#ifndef __PARTICLE_H__
#define __PARTICLE_H__
#include "sgct.h"

struct Particle
{
	glm::mat4 mMatrix;
	glm::vec3 mVelocity;


	float mSize;
	float mLife;
};

#endif
