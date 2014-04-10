#ifndef __FIELD_H__
#define __FIELD_H__

#include <iostream>
#include <vector>
#include "sgct.h"
#include "Particle.h"

using namespace std;

/**
 * Strictly virutal class
 */
class Field
{
	public:
		Field(){};
		virtual glm::vec3 getVelocity(double delta, Particle& p) = 0;
};

#endif
