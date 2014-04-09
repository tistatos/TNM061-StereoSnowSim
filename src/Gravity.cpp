#include "Gravity.h"

void Gravity::init(float speed)
{
	velocity = glm::vec3(0.0f, speed, 0.0f);
}

glm::vec3 Gravity::getVelocity(double delta)
{
	return (velocity * (float)delta);
}
