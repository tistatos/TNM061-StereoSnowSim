#include "Gravity.h"

/**
 * initialize the gravity field, sets acc to -9.81 by default
 * @param acc
 */
void Gravity::init(float acc)
{
	acceleration = glm::vec3(0.0f, acc, 0.0f);
}

/**
 * returns the speed effect from the field
 * @param  delta 		the time delta function, such as gEngines getDt();
 * @return glm::vec3 	the speed!
 */
glm::vec3 Gravity::getVelocity(double delta)
{
	return (acceleration * (float)delta);
}
