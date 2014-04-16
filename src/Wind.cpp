#include "Wind.h"

/**
 * initialize the wind field, sets acc to -9.81 by default
 * @param acc
 */
void Wind::init(float x, float y, float z)
{
	acceleration = glm::vec3(x, y, z);
}

/**
 * returns the speed effect from the field (velocity = v0 + a*t)
 * @param  delta 		the time delta function, such as gEngines getDt();
 * @return glm::vec3 	the speed!
 */
glm::vec3 Wind::getVelocity(double delta, Particle& p)
{
	return (acceleration * (float)delta);
}

glm::vec3 Wind::getAcceleration()
{
	return acceleration;
}

void Wind::printInfo()
{
	std::cout << "Wind direction: " << getAcceleration() << std::endl;
}
