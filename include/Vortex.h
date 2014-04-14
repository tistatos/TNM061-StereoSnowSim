#ifndef __VORTEX_H__
#define __VORTEX_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"
#include "glm/gtx/vector_angle.hpp"

class Vortex : public Field
{
	public:
		Vortex(){};
		glm::vec3 getVelocity(double delta, Particle& p);
		void init(float x, float z, float r);
		void setPosition(float x, float z);
		void setRadius(float r);
		void setForce(float x, float y, float z);
	private:
		float calcDistance(const Particle& p); /// calc distance from p to center of cylinder

		glm::vec3 mPosition; /// center of cylinder
		glm::vec3 mForce; /// force at center of cylinder
		float mRadius; /// radius of cylinder
};

#endif // __VORTEX_H__
