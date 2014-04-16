#include "sgct.h"
#include "ParticleSystem.h"
#include "Snow.h"
#include "World.h"
#include "HelperFunctions.h"
#include "Field.h"
#include "Gravity.h"
#include "Wind.h"

sgct::Engine* gEngine;
Snow* gParticles;
World* gWorld;


void initialize();
void draw();

int main(int argc, char *argv[])
{
	initRandom();

	gEngine = new sgct::Engine(argc, argv);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);

	gParticles = new Snow(gEngine);
	gWorld = new World(gEngine);

	Gravity* grav = new Gravity();
	grav->init(-0.1f);
	gParticles->addField(grav);

	Wind* wind = new Wind();
	wind->init(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	gParticles->addField(wind);

	cout << "Wind direction: " << wind->getAcceleration() << endl;

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	gEngine->render();

	gParticles->destroy();

	delete gEngine;
	delete gParticles;

	exit(EXIT_SUCCESS);
}

void initialize()
{
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
