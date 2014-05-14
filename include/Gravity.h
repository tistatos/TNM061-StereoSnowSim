#ifndef __GRAVITY_H__
#define __GRAVITY_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"

using namespace std;

const float DAMPENING = 0.02f;

class Gravity : public Field
{
	public:
		Gravity(){};
		void init(float acc = -9.81);
		glm::vec3 getVelocity(double delta, Particle& p);
		void printInfo();
		void showField() {};
	private:
		glm::vec3 acceleration;
};

#endif
