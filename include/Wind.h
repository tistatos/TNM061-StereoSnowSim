#ifndef __WIND_H__
#define __WIND_H__

#include "sgct.h"
#include "Field.h"

using namespace std;

class Wind : public Field
{
	public:
		Wind(){};
		void init(float x = 0.0f, float y = 0.0f, float z = 0.0f);
		glm::vec3 getVelocity(double delta, glm::vec3 velocity);
		glm::vec3 getAcceleration();
	private:
		glm::vec3 acceleration;
};

#endif
