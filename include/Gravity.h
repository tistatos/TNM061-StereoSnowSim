#ifndef __FIELD_H__
#define __GRATIVY_H__


#include <iostream>
#include "sgct.h"
#include "Field.h"

using namespace std;

class Gravity : public Field
{
	public:
		Gravity();
		Gravity(float speed);
		glm::vec3 getVelocity(double delta);
	private:
		glm::vec3 velocity;
};

#endif
