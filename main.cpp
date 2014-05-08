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


sgct::SharedBool showStats(false);
sgct::SharedBool showGraph(false);
sgct::SharedDouble size_factor(0.5);
sgct::SharedDouble curr_time(0.0);


void initialize();
void draw();
void myPreSyncFun();
void myPostSyncPreDrawFun();
void myEncodeFun();
void myDecodeFun();
void externalControlCallback(const char * receivedChars, int size, int clientId);


int main(int argc, char *argv[])
{
	initRandom();

	gEngine = new sgct::Engine(argc, argv);

	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);
	gEngine->setPreSyncFunction(myPreSyncFun);
	gEngine->setPostSyncPreDrawFunction(myPostSyncPreDrawFun);
	gEngine->setExternalControlCallback(externalControlCallback);

	sgct::SharedData::instance()->setEncodeFunction(myEncodeFun);
	sgct::SharedData::instance()->setDecodeFunction(myDecodeFun);


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
	turbine->init(0.0f, -4.0f, 5.0f);
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
	gObject->loadObj("road/road.obj");

	gBubble->createSphere(1.5f, 100);
}

void draw()
{
	double delta = gEngine->getDt();

	gWorld->drawWorld();
	//gBubble->drawBubble();

	gParticles->move(delta);
	gParticles->draw(delta);

	gObject->draw();
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

//Shows stats and graph depending on if the variables are true or not. Dont know if we need this?
void myPostSyncPreDrawFun()
{
	gEngine->setDisplayInfoVisibility(&showStats);
	gEngine->setStatsGraphVisibility(&showGraph);
}

//Encodes the data sent from GUI
void myEncodeFun()
{
	sgct::SharedData::instance()->writeDouble(&curr_time);
	sgct::SharedData::instance()->writeDouble(&size_factor);
	sgct::SharedData::instance()->writeBool(&showStats);
	sgct::SharedData::instance()->writeBool(&showGraph);
}

//Decodes the data sent from GUI
void myDecodeFun()
{
	sgct::SharedData::instance()->readDouble(&curr_time);
	sgct::SharedData::instance()->readDouble(&size_factor);
	sgct::SharedData::instance()->readBool(&showStats);
	sgct::SharedData::instance()->readBool(&showGraph);
}

//Used to alter certain values when sent from GUI. This way we can alter the fields or change gravity in realtime! 
void externalControlCallback(const char * receivedChars, int size, int clientId)
{
	//Checks so the gEnginenode is actually the master.
	if(gEngine->isMaster())
	{
		//Compares the length of the strings so no weird runtime errors occur
		if(size == 7 &&  strncmp(receivedChars, "stats", 5) == 0)
		{
			showStats.setVal(true);
		}

		else if(size == 7 &&  strncmp(receivedChars, "graph", 5) == 0)
		{
			showGraph.setVal(true);
		}

		else if(size >= 6 && strncmp(receivedChars, "size", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);

			size_factor.setVal(tmpVal);
		}
	}
}
