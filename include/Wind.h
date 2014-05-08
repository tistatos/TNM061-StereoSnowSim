#ifndef __WIND_H__
#define __WIND_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"

using namespace std;

class Wind : public Field
{
	public:
		Wind(){};
		void setAcceleration(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		glm::vec3 getVelocity(double delta, Particle& p);
		glm::vec3 getAcceleration();
		void printInfo();
	private:
		glm::vec3 acceleration;
};

#endif
