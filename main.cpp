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
#include "SimplexNoise.h"

//our beautiful global variables
sgct::Engine* gEngine;
Snow* gParticles;
World* gWorld;
Object* gObject;
Object* tree;
SoapBubble* gBubble;
Wind* gWind;
Gravity* gGrav;
Vortex* gTurbine;


sgct::SharedBool windBox(false);
sgct::SharedBool vortexBox(false);
sgct::SharedDouble sizeFactorX(0.0);
sgct::SharedDouble sizeFactorY(0.0);
sgct::SharedDouble sizeFactorZ(0.0);
sgct::SharedDouble gravFactor(0.0);
sgct::SharedDouble vortexPosX(0.0);
sgct::SharedDouble vortexPosY(0.0);
sgct::SharedDouble vortexPosZ(0.0);
sgct::SharedDouble curr_time(0.0);


void initialize();
void draw();
void myPreSyncFun();
void statsDrawfun();
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
	gEngine->setPostSyncPreDrawFunction(statsDrawfun);
	gEngine->setExternalControlCallback(externalControlCallback);

	sgct::SharedData::instance()->setEncodeFunction(myEncodeFun);
	sgct::SharedData::instance()->setDecodeFunction(myDecodeFun);

	gParticles = new Snow(gEngine);
	gWorld = new World(gEngine);
	gBubble = new SoapBubble(gEngine);

	gObject = new Object(gEngine);
	tree = new Object(gEngine);

	gGrav = new Gravity();
	gGrav->init(-9.81f);
	gParticles->addField(gGrav);


	gWind = new Wind();
	//wind->init(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	gWind->setAcceleration(0.0f, 0.0f, 0.0f);
	gParticles->addField(gWind);

	gTurbine = new Vortex();
	gTurbine->init(0.0f, 0.0f, 0.0f);
	//turbine->setForce(-10.0f, 0.0f, -1.0f);
	//gParticles->addField(gTurbine);

	//Not working yet... :(
	SimplexNoise* noise = new SimplexNoise();
	noise->init(glm::vec3(0), glm::vec3(0));

	gParticles->addField(noise);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

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

//Shows stats and graph depending on if the variables are true or not. Dont know if we need this?
void statsDrawfun()
{
	//gEngine->setDisplayInfoVisibility(&windBox);
	//gEngine->setStatsGraphVisibility(&vortexBox);
}

//Encodes the data sent from GUI
void myEncodeFun()
{
	sgct::SharedData::instance()->writeBool(&windBox);
	sgct::SharedData::instance()->writeBool(&vortexBox);
	sgct::SharedData::instance()->writeDouble(&curr_time);
	sgct::SharedData::instance()->writeDouble(&sizeFactorX);
	sgct::SharedData::instance()->writeDouble(&sizeFactorY);
	sgct::SharedData::instance()->writeDouble(&sizeFactorZ);
	sgct::SharedData::instance()->writeDouble(&gravFactor);
	sgct::SharedData::instance()->writeBool(&windBox);
	sgct::SharedData::instance()->writeBool(&vortexBox);
}

//Decodes the data sent from GUI
void myDecodeFun()
{
	sgct::SharedData::instance()->readBool(&windBox);
	sgct::SharedData::instance()->readBool(&vortexBox);
	sgct::SharedData::instance()->readDouble(&curr_time);
	sgct::SharedData::instance()->readDouble(&sizeFactorX);
	sgct::SharedData::instance()->readDouble(&sizeFactorY);
	sgct::SharedData::instance()->readDouble(&sizeFactorZ);
	sgct::SharedData::instance()->readDouble(&gravFactor);
	sgct::SharedData::instance()->readBool(&windBox);
	sgct::SharedData::instance()->readBool(&vortexBox);
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
			windBox.setVal(true);
			vortexBox.setVal(false);
		}

		else if(size == 7 &&  strncmp(receivedChars, "graph", 5) == 0)
		{
			vortexBox.setVal(true);
			windBox.setVal(false);
		}

		else if(size >= 6 && strncmp(receivedChars, "winX", 4) == 0)
		{
			//We need an int.
			int tmpValX = atoi(receivedChars + 5);

			sizeFactorX.setVal(tmpValX);
			if(windBox.getVal())
				gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
			else
				gTurbine->setForce((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));

		}

		else if(size >= 6 && strncmp(receivedChars, "winY", 4) == 0)
		{
			//We need an int.
			int tmpValY = atoi(receivedChars + 5);

			sizeFactorY.setVal(tmpValY);
			if(windBox.getVal())
				gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
			else
				gTurbine->setForce((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));

		}

		else if(size >= 6 && strncmp(receivedChars, "winZ", 4) == 0)
		{
			//We need an int.
			int tmpValZ = atoi(receivedChars + 5);

			sizeFactorZ.setVal(tmpValZ);
			if(windBox.getVal())
				gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
			else
				gTurbine->setForce((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "grav", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gGrav->init(-tmpVal);

		}
	}
}
