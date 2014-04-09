#ifndef __GRAVITY_H__
#define __GRAVITY_H__


#include <iostream>
#include "sgct.h"
#include "Field.h"

using namespace std;

class Gravity : public Field
{
	public:
		Gravity(){};
		void init(float speed = -9.81);
		glm::vec3 getVelocity(double delta);
	private:
		glm::vec3 velocity;
};

#endif
