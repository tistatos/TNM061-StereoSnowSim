#include "Gravity.h"

Gravity::Gravity()
{
	velocity = glm::vec3(0.0f, -9.81f, 0.0f);
}

Gravity::Gravity(float speed)
{
	velocity = glm::vec3(0.0f, speed, 0.0f);
}

glm::vec3 Gravity::getVelocity(double delta)
{
	return velocity * (float)delta;
}
