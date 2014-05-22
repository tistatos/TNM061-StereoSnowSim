#ifndef __PARTICLE_H__
#define __PARTICLE_H__
#include "sgct.h"

struct Particle
{
	glm::mat4 mMatrix;
	glm::vec3 mVelocity;

	float mDistance; /// Distance from camera
	float mLife; /// life remaining of particle

	glm::vec3 position() { return glm::vec3(mMatrix[3][0],mMatrix[3][1],mMatrix[3][2]);}

    bool operator<(const Particle& that) const
    {
        // Sort in reverse order : far particles drawn first.
        return this->mDistance > that.mDistance;
    }

};

#endif
