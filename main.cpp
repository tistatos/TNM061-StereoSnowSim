#include "sgct.h"
#include "ParticleSystem.h"
#include "Snow.h"
#include "World.h"
#include "HelperFunctions.h"
#include "Field.h"
#include "Gravity.h"
#include "Wind.h"
#include "ObjSystem.h"
#include "SoapBubble.h"
#include "Vortex.h"
#include <iostream>


//our beautiful global variables
sgct::Engine* gEngine;
Snow* gParticles;
World* gWorld;
Object* gObject;
SoapBubble* gBubble;


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
	gObject = new Object(gEngine);
	gBubble = new SoapBubble(gEngine);

	Gravity* grav = new Gravity();
	grav->init(-9.81f);
	gParticles->addField(grav);

	Wind* wind = new Wind();
	//wind->init(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	gParticles->addField(wind);

	Vortex* turbine = new Vortex();
	turbine->init(0.0f, -4.0f, 2.0f);
	turbine->setForce(-10.0f, 0.0f, -1.0f);
	gParticles->addField(turbine);

	cout << "---- Fields active on gParticles ----" << endl;
	gParticles->printFields();
	cout << "---------------" << endl << endl;

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	gEngine->render();


	gParticles->destroy();
	gObject->deleteObject();
	delete gObject;
	delete gEngine;
	delete gParticles;
	delete gWorld;
	delete gBubble;

	exit(EXIT_SUCCESS);
}

void initialize()
{
	if(!gParticles->initialize())
	{
		std::cout << "Error Initialzing Particle System:" << std::endl;
		exit(EXIT_FAILURE);
	}
	gWorld->initializeWorld();

	//gObject->initialize();
	gObject->loadObj("cube.obj");

	gBubble->createSphere(1.5f, 100);
}

void draw()
{
	double delta = gEngine->getDt();

	//gWorld->drawWorld();
	//gBubble->drawBubble();

	gParticles->move(delta);
	//gParticles->draw(delta);

	gObject->draw();
}
