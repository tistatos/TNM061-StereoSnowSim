#ifndef __WIND_H__
#define __WIND_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"

class Wind : public Field
{
	public:
		Wind(){};
		void setAcceleration(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		void setAcceleration(float vals[]);
		glm::vec3 getVelocity(double delta, Particle& p);
		glm::vec3 getAcceleration();
		void printInfo();
		void showField();
	private:
		glm::vec3 acceleration;
};

#endif
