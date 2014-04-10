#ifndef __FIELD_H__
#define __FIELD_H__

#include <iostream>
#include <vector>
#include "sgct.h"

using namespace std;

/**
 * Strictly virutal class
 */
class Field
{
	public:
		Field(){};
		virtual glm::vec3 getVelocity(double delta) = 0;
		virtual void init(float speed) = 0;
};

#endif
