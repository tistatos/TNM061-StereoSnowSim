#include "Gravity.h"

void Gravity::init(float acceleration)
{
	velocity = glm::vec3(0.0f, acceleration, 0.0f);
}

//velocity = v0 + at
glm::vec3 Gravity::getVelocity(double delta)
{
	return (velocity * (float)delta);
}
