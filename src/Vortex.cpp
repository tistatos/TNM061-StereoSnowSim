#include "Vortex.h"

glm::vec3 Vortex::getVelocity(double delta, Particle& p)
{
	float ndistance = calcParticleDistance(p) / mRadius;
	if(ndistance < 1)
	{
		std::cout << "Normalized distance to center: " << ndistance << std::endl;
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

float Vortex::calcParticleDistance(const Particle& p)
{
	float deltax, deltaz;
	deltax = mPosition.x - p.mPosition.x;
	deltaz = mPosition.z - p.mPosition.z;

	return sqrt(pow(deltax, 2) + pow(deltaz, 2));
}
