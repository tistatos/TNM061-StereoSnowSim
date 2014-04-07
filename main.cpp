#include "sgct.h"
#include "ParticleSystem.h"

sgct::Engine* gEngine;
ParticleSystem* gParticles;


void initialize();
void draw();

int main(int argc, char *argv[])
{
	gEngine = new sgct::Engine(argc, argv);
	gParticles = new ParticleSystem(gEngine);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile));
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	gEngine->render();

	delete gEngine;
	exit( EXIT_SUCCESS);
}

void initialize()
{
	gParticles->initialize();
}

void draw()
{

}