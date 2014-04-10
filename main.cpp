#include <iostream>
#include "sgct.h"
#include "ParticleSystem.h"
#include "World.h"
#include "HelperFunctions.h"
#include "Gravity.h"
#include <iostream>

sgct::Engine* gEngine;
ParticleSystem* gParticles;
World* gWorld;

using namespace std;

void initialize();
void draw();

int main(int argc, char *argv[])
{
	gEngine = new sgct::Engine(argc, argv);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);

	gParticles = new ParticleSystem(gEngine);
	gWorld = new World(gEngine);

	Gravity* grav = new Gravity();
	grav->init(-0.08f);
	gParticles->addField(grav);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}
	sgct::SGCTSettings::instance()->setSwapInterval(1);
	gEngine->render();
	gParticles->destroy();
	delete gEngine;
	delete gParticles;
	exit(EXIT_SUCCESS);
}

void initialize()
{
	initRandom();

	gParticles->initialize();
	gWorld->initializeWorld();
}

void draw()
{
	double delta = gEngine->getDt();

	gWorld->drawWorld();

	gParticles->move(delta);
	gParticles->draw(delta);
}
