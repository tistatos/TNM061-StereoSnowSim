#include "Vortex.h"

glm::vec3 Vortex::getVelocity(double delta, Particle& p)
{
	float nDistance = calcDistance(p) / mRadius;
	if(nDistance < 1)
	{
		// get position as vector
		glm::vec3 particlePosition = glm::vec3(p.mMatrix[3].x, p.mMatrix[3].y, p.mMatrix[3].z);
		// normalize vectors
		glm::vec3 nPosition = (particlePosition - mPosition) / mRadius;
		// calc angle between vectors
		// glm::vec3 nAnglevec = glm::cross(glm::vec3(0.0f, 1.0f, 0.0f), nPosition);
		float angle = glm::angle(glm::vec2(1.0f, 0.0f),
								 glm::vec2(particlePosition.x, particlePosition.z)/mRadius);
		// rotate vector
		glm::vec2 direction = glm::rotate(glm::vec2(mForce.x, mForce.z), angle);
		// create new vector from what we got
		glm::vec3 nAnglevec = glm::vec3(direction.x, mForce.y, direction.y);

		// std::cout << "Normalized distance to center: " << nDistance << std::endl;
		// std::cout << "Position is " << glm::vec2(particlePosition.x, particlePosition.z)/mRadius << std::endl;
		// std::cout << "Angle " << angle << " results in " << direction << std::endl << std::endl;
		return nAnglevec * (1 - nDistance) * (float)delta;
	}

	return glm::vec3(0.0f);
}

void Vortex::init(float x, float z, float r)
{
	mPosition = glm::vec3(x, 0.0f, z);
	mRadius = r;
}

void Vortex::setPosition(float x, float z)
{
	mPosition.x = x;
	mPosition.z = z;
}

void Vortex::setRadius(float r)
{
	mRadius = r;
}

void Vortex::setForce(float x, float y, float z)
{
	mForce = glm::vec3(x, y, z);
}

float Vortex::calcDistance(const Particle& p)
{
	float deltax, deltaz;
	deltax = mPosition.x - p.mMatrix[3].x;
	deltaz = mPosition.z - p.mMatrix[3].z;

	return sqrt(deltax*deltax + deltaz*deltaz);
}

void Vortex::printInfo()
{
	std::cout << "Vortex with force " << mForce << " at " << mPosition << " with radius " << mRadius << std::endl;
}
