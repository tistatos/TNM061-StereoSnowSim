#include "sgct.h"
#include "ParticleSystem.h"
#include "Snow.h"
#include "World.h"
#include "HelperFunctions.h"
#include "Field.h"
#include "DebugField.h"
#include "Gravity.h"
#include "Wind.h"
#include "ObjSystem.h"
#include "SoapBubble.h"
#include "Vortex.h"
#include <iostream>
#include "SimplexNoise.h"

//our beautiful global variables
sgct::Engine* gEngine;
Snow* gParticles;
World* gWorld;
DebugField* gDebugField;
Object* gObject;
Object* tree;
SoapBubble* gBubble;
Wind* gWind;
Gravity* gGrav;
Vortex* gTurbine;

sgct::SharedDouble curr_time(0.0);

void initialize();
void draw();
void myPreSyncFun();
void statsDrawFun();
void externalControlCallback(const char * receivedChars, int size, int clientId);
void sendMessageToExternalControl(void * data, int length);


int main(int argc, char *argv[])
{
	initRandom();

	gEngine = new sgct::Engine(argc, argv);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);
	gEngine->setPreSyncFunction(myPreSyncFun);
	gEngine->setPostSyncPreDrawFunction(statsDrawFun);
	gEngine->setExternalControlCallback(externalControlCallback);

	gParticles = new Snow(gEngine);
	gWorld = new World(gEngine);
	gDebugField = new DebugField(gEngine);

	gBubble = new SoapBubble(gEngine);

	gObject = new Object(gEngine);
	tree = new Object(gEngine);

	gGrav = new Gravity();
	gGrav->init(-9.81f);
	//gParticles->addField(gGrav);


	gWind = new Wind();
	//wind->init(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	gWind->setAcceleration(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	//gParticles->addField(gWind);

	gTurbine = new Vortex();
	gTurbine->init(0.0f, 0.0f, 0.0f);
	gParticles->addField(gTurbine);


	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	//Not working yet... :(
	SimplexNoise* noise = new SimplexNoise();
	noise->init(glm::vec3(0), glm::vec3(0), gEngine->getTime());

	gParticles->addField(noise);

	cout << "---- Fields active on gParticles ----" << endl;
	gParticles->printFields();
	cout << "---------------" << endl << endl;

	gEngine->render();

	gParticles->destroy();
	gObject->deleteObject();
	delete gObject;
	delete gEngine;
	delete gParticles;
	delete gWorld;
	delete gBubble;
	delete gWind;
	delete gTurbine;

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

	gDebugField->init();

	gObject->loadObj("road/road.obj", "road/road.png");
	gObject->scale(0.2f,0.2f,0.2f);
	gObject->translate(0.0f, -2.0f, 5.0f);

	tree->loadObj("road/tree.obj","road/tree.png");
	tree->scale(0.05f,0.05f,0.05f);
	tree->translate(0.0f, -1.0f, -6.0f);

	gBubble->createSphere(1.5f, 100);
}

void draw()
{
	double delta = gEngine->getDt();
	gWorld->drawWorld();
	gBubble->drawBubble();
	//gObject->draw();
	//tree->draw();
	gParticles->move(delta);
	gParticles->draw(delta);
}

//Checking the time since the program started, not sure if we need this either.
void myPreSyncFun()
{
	//Checks so the gEnginenode is actually the master.
	if( gEngine->isMaster() )
	{
		//Sets the current time since the program started
		curr_time.setVal(sgct::Engine::getTime());
	}
}

//Shows stats and graph depending on if the variables are true or not. Dont know if we need this? Currently set to false.
void statsDrawFun()
{
	gEngine->setDisplayInfoVisibility(false);
	gEngine->setStatsGraphVisibility(false);
	gEngine->setWireframe(false);
}

//Used to alter certain values when sent from GUI. This way we can alter the fields or change gravity in realtime!
void externalControlCallback(const char * receivedChars, int size, int clientId)
{
	//Checks so the gEnginenode is actually the master.
	if(gEngine->isMaster())
	{
		if(size >= 6 && strncmp(receivedChars, "winX", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gWind->setAcceleration((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "winY", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gWind->setAcceleration((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "winZ", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gWind->setAcceleration((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}
		else if(size >= 6 && strncmp(receivedChars, "vorX", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gTurbine->setForce((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "vorY", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gTurbine->setForce((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "vorZ", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gTurbine->setForce((tmpVal*0.01f), (tmpVal*0.01f), (tmpVal*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "grav", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gGrav->init(-tmpVal);
		}
	}
}
