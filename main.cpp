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
Object* road;
Object* tree;
SoapBubble* gBubble;
Wind* gWind;
Gravity* gGrav;
Vortex* gTurbine;

bool gDisplayInfo;
bool gStatsGraph;
bool gWireframe;

sgct::SharedDouble curr_time(0.0);
sgct::SharedDouble sizeFactorX(0.0);
sgct::SharedDouble sizeFactorY(0.0);
sgct::SharedDouble sizeFactorZ(0.0);
sgct::SharedDouble vortFactorX(0.0);
sgct::SharedDouble vortFactorY(0.0);
sgct::SharedDouble vortFactorZ(0.0);
sgct::SharedDouble positionX(0.0);
sgct::SharedDouble positionZ(0.0);
sgct::SharedDouble radius(0.0);
sgct::SharedDouble fadeDistance(0.0);


void initialize();
void draw();
void myPreSyncFun();
void statsDrawFun();
void myEncodeFun();
void myDecodeFun();
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
	sgct::SharedData::instance()->setEncodeFunction(myEncodeFun);
	sgct::SharedData::instance()->setDecodeFunction(myDecodeFun);

	gParticles = new Snow(gEngine);
	gWorld = new World(gEngine);

	gBubble = new SoapBubble(gEngine);

	road = new Object(gEngine);
	tree = new Object(gEngine);

	gGrav = new Gravity();
	gGrav->init(-9.81f);
	gParticles->addField(gGrav);


	gWind = new Wind();
	//wind->init(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	gWind->setAcceleration(getRandom(-0.2, 0.2), 0.0f, getRandom(-0.2, 0.2));
	//gParticles->addField(gWind);

	gTurbine = new Vortex();
	gTurbine->init(0.0f, 0.0f, 0.0f);
	// gParticles->addField(gTurbine);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	//Not working yet... :(
	SimplexNoise* noise = new SimplexNoise();
	noise->init(glm::vec3(0), glm::vec3(0), gEngine->getTime());

	// gParticles->addField(noise);

	cout << "---- Fields active on gParticles ----" << endl;
	gParticles->printFields();
	cout << "---------------" << endl << endl;

	gEngine->render();

	gParticles->destroy();
	road->deleteObject();
	delete road;
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

	road->loadObj("road/road.obj", "road/road.png");
	road->scale(0.2f,0.2f,0.2f);
	road->translate(0.0f, -2.0f, 5.0f);

	tree->loadObj("road/tree.obj","road/tree.png");
	tree->scale(0.05f,0.05f,0.05f);
	tree->translate(0.0f, -1.0f, -6.0f);

	gBubble->createSphere(1.5f, 100);


	gDisplayInfo = false;
	gStatsGraph = false;
	gWireframe = false;
}

void draw()
{
	double delta = gEngine->getDt();
	gWorld->drawWorld();
	gBubble->drawBubble();
	road->draw();
	tree->draw();
	gParticles->move(delta);
	gParticles->draw(delta);

	//if(gEngine->isExternalControlConnected())
	//	cout << "Connectad is very nice";
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

void myEncodeFun()
{
	sgct::SharedData::instance()->writeDouble(&curr_time);
 	sgct::SharedData::instance()->writeDouble(&sizeFactorX);
 	sgct::SharedData::instance()->writeDouble(&sizeFactorY);
 	sgct::SharedData::instance()->writeDouble(&sizeFactorZ);
 	sgct::SharedData::instance()->writeDouble(&vortFactorX);
 	sgct::SharedData::instance()->writeDouble(&vortFactorY);
 	sgct::SharedData::instance()->writeDouble(&vortFactorZ);
 	sgct::SharedData::instance()->writeDouble(&positionX);
 	sgct::SharedData::instance()->writeDouble(&positionZ);
 	sgct::SharedData::instance()->writeDouble(&radius);
 	sgct::SharedData::instance()->writeDouble(&fadeDistance);

}


void myDecodeFun()
{
	sgct::SharedData::instance()->readDouble(&curr_time);
	sgct::SharedData::instance()->readDouble(&sizeFactorX);
	sgct::SharedData::instance()->readDouble(&sizeFactorY);
	sgct::SharedData::instance()->readDouble(&sizeFactorZ);
	sgct::SharedData::instance()->readDouble(&vortFactorX);
	sgct::SharedData::instance()->readDouble(&vortFactorY);
	sgct::SharedData::instance()->readDouble(&vortFactorZ);
	sgct::SharedData::instance()->readDouble(&positionX);
	sgct::SharedData::instance()->readDouble(&positionZ);
	sgct::SharedData::instance()->readDouble(&radius);
	sgct::SharedData::instance()->readDouble(&fadeDistance);
}

//Shows stats and graph depending on if the variables are true or not. Dont know if we need this? Currently set to false.
void statsDrawFun()
{
	gEngine->setDisplayInfoVisibility(gDisplayInfo);
	gEngine->setStatsGraphVisibility(gStatsGraph);
	gEngine->setWireframe(gWireframe);
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
 			sizeFactorX.setVal(tmpVal);
			gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));

		}

		else if(size >= 6 && strncmp(receivedChars, "winY", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
 			sizeFactorY.setVal(tmpVal);
			gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "winZ", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
 			sizeFactorZ.setVal(tmpVal);
			gWind->setAcceleration((sizeFactorX.getVal()*0.01f), (sizeFactorY.getVal()*0.01f), (sizeFactorZ.getVal()*0.01f));
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
			vortFactorY.setVal(tmpVal);
			gTurbine->setForce((vortFactorX.getVal()*0.01f), (vortFactorY.getVal()*0.01f), (vortFactorZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "vorZ", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			vortFactorZ.setVal(tmpVal);
			gTurbine->setForce((vortFactorX.getVal()*0.01f), (vortFactorY.getVal()*0.01f), (vortFactorZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "posX", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			positionX.setVal(tmpVal);
			gTurbine->setPosition((positionX.getVal()*0.01f),(positionZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "posZ", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			positionZ.setVal(tmpVal);
			gTurbine->setPosition((positionX.getVal()*0.01f),(positionZ.getVal()*0.01f));
		}

		else if(size >= 6 && strncmp(receivedChars, "radi", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			radius.setVal(tmpVal);
			gTurbine->setRadius(radius.getVal());
		}

		else if(size >= 6 && strncmp(receivedChars, "paus", 4) == 0)
		{
			gParticles->togglePause();
		}

		else if(size >= 6 && strncmp(receivedChars, "grav", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			gGrav->init(-tmpVal);
		}

		else if(strncmp(receivedChars, "fade", 1) == 0)
		{
			float tmpVal = atof(receivedChars + 5);
			fadeDistance.setVal(tmpVal);
			gParticles->setFadeDistance(fadeDistance.getVal());
		}

		else if(size >= 6 && strncmp(receivedChars, "disp", 4) == 0)
		{
			//gDisplayInfo = !gDisplayInfo;
		}

		else if(size >= 6 && strncmp(receivedChars, "stat", 4) == 0)
		{
			//gStatsGraph = !gStatsGraph;
		}

		else if(size >= 6 && strncmp(receivedChars, "wire", 4) == 0)
		{
			//gWireframe = !gWireframe;
		}
	}
}
