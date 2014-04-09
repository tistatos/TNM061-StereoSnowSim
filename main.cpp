#include <iostream>
#include "sgct.h"
#include "ParticleSystem.h"

#include <iostream>

sgct::Engine* gEngine;
ParticleSystem* gParticles;

using namespace std;

void initialize();
void draw();

int main(int argc, char *argv[])
{
	gEngine = new sgct::Engine(argc, argv);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);

	gParticles = new ParticleSystem(gEngine);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	gEngine->render();
	gParticles->destroy();
	delete gEngine;
	delete gParticles;
	exit( EXIT_SUCCESS);
}

void initialize()
{
	gParticles->initialize();
}

void draw()
{
	gParticles->move();
	gParticles->draw();
}
