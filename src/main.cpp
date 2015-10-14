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
#include "Vortex.h"
#include <iostream>
#include "SimplexNoise.h"
#include <sgct/FontManager.h>
//our beautiful global variables
sgct::Engine* gEngine;
Snow* gParticles;
World* gWorld;
Object* road;
Object* tree;
Object* gGround;
Wind* gWind;
Gravity* gGrav;
Vortex* gTurbine;

sgct::SharedDouble masterDelta(0.0);
sgct::SharedFloat windDirX(0.0);
sgct::SharedFloat windDirY(0.0);
sgct::SharedFloat windDirZ(0.0);
sgct::SharedFloat vortFactorX(0.0);
sgct::SharedFloat vortFactorY(0.0);
sgct::SharedFloat vortFactorZ(0.0);
sgct::SharedFloat gravFactor(0.0);
sgct::SharedFloat positionX(0.0);
sgct::SharedFloat positionZ(-1.0);
sgct::SharedInt radius(1.0);
sgct::SharedFloat particleSize(40.0);
sgct::SharedFloat fadeDistance(20.0);
sgct::SharedBool sharedPause(false);
sgct::SharedBool showStats(false);
sgct::SharedBool showGraph(false);
sgct::SharedBool showObject(false);


void initialize();
void draw();
void myPreSyncFun();
void myPostSyncPreDrawFun();
void myEncodeFun();
void myDecodeFun();
void externalControlCallback(const char * receivedChars, int size);
void sendMessageToExternalControl(void * data, int length);


int main(int argc, char *argv[])
{
	initRandom();
	gEngine = new sgct::Engine(argc, argv);

	// sgct setup and preparation
	gEngine->setInitOGLFunction(initialize);
	gEngine->setDrawFunction(draw);
	gEngine->setPreSyncFunction(myPreSyncFun);
	gEngine->setPostSyncPreDrawFunction(myPostSyncPreDrawFun);
	gEngine->setExternalControlCallback(externalControlCallback);
	sgct::SharedData::instance()->setEncodeFunction(myEncodeFun);
	sgct::SharedData::instance()->setDecodeFunction(myDecodeFun);

	gParticles = new Snow(gEngine);
	gWorld = new World(gEngine);

	// add some nice objects
	road = new Object(gEngine);
	tree = new Object(gEngine);
	gGround = new Object(gEngine);

    float gravityValue = -9.81f;
    float windValues[] = {getRandom(-0.05, 0.05), 0.0f, getRandom(-0.05, 0.05)}; 
    float turbineValues[] = { 0.0, 0.0, 0.0,};

    if(argc > 0)
    {
        for(int i = 0; i < argc; i++)
        {
            
            if(std::string(argv[i]) == "-h")
            {
                std::cout << "Snow simulation command line usage: \n"
                          << "-g [GRAVITY CONSTANT] \t\t set value of gravity \n"
                          << "   (default -9.81) \n"
                          << "-w [VALUEX] [VALUEY] [VALUEZ] \t set wind direction and strenght\n"
                          << "   (default random[-0.05, 0.05] 0.0 random[-0.05, 0.05]) \n"
                          << "-t [VALUEX] [VALUEZ] [RADIUS] \t set turbine values\n"
                          << "   (default 0.0 0.0 0.0) \n";

                return(EXIT_SUCCESS);
            }
            if(std::string(argv[i]) == "-g" && i+1 < argc)
            {
                gravityValue = atof(argv[++i]);
            }
            
            if(std::string(argv[i]) == "-w" && i+3 < argc)
            {
                windValues[0] = atof(argv[++i]);
                windValues[1] = atof(argv[++i]);
                windValues[2] = atof(argv[++i]);
            }

            if(std::string(argv[i]) == "-w" && i+3 < argc)
            {
                turbineValues[0] = atof(argv[++i]);
                turbineValues[1] = atof(argv[++i]);
                turbineValues[2] = atof(argv[++i]);
            }
        }
    }
    
    
    // dem fields
	gGrav = new Gravity();
	gGrav->init(gravityValue);
	gParticles->addField(gGrav);

	gWind = new Wind();
	gWind->setAcceleration(windValues);
	gParticles->addField(gWind);

	gTurbine = new Vortex();
	gTurbine->init(turbineValues);
	gParticles->addField(gTurbine);

	//Not working yet... :(
	SimplexNoise* noise = new SimplexNoise();
	noise->init(glm::vec3(0), glm::vec3(0), gEngine->getTime());
	//gParticles->addField(noise);

	if(!gEngine->init(sgct::Engine::OpenGL_3_3_Core_Profile))
	{
		delete gEngine;
		return EXIT_FAILURE;
	}

	// tell user what field's are active
	cout << "---- Fields active on gParticles ----" << endl;
	gParticles->printFields();
	cout << "---------------" << endl << endl;
    
    // set proper sync values
    gravFactor.setVal(gravityValue);
    
    windDirX.setVal(windValues[0]);
    windDirY.setVal(windValues[1]);
    windDirZ.setVal(windValues[2]);

    vortFactorX.setVal(turbineValues[0]);    
    vortFactorY.setVal(turbineValues[1]);
    vortFactorZ.setVal(turbineValues[2]);

	// Let's get ready to rendeeeeeer!
	gEngine->render();

	// destroy everything and exit
	gParticles->destroy();
	road->deleteObject();
	delete road;
	delete gEngine;
	delete gParticles;
	delete gWorld;
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
    sgct_text::FontManager::instance()->addFont("font", "FreeMono.ttf");
}

void draw()
{
	glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
	double delta = masterDelta.getVal();

	gWorld->drawWorld();

	if (showObject.getVal())
	{
		road->draw();
		gGround->draw();
		tree->draw();
	}
   
    string credit = "Snomys";
    string creditText = "Ett projekt av \n Erik Sandren Carl Englund Klas Eskilson\n Therese Komstadius Daniel Ronnkvist";
    glm::mat4 textMat = glm::translate(glm::mat4(1.0f), glm::vec3(-3,1,-3));
    textMat = glm::scale(textMat,glm::vec3(0.4,0.4,0.4));
    sgct_text::print3d( sgct_text::FontManager::instance()->getFont("font", 24), gEngine->getActiveModelViewProjectionMatrix() * textMat, credit.c_str());
    
    textMat = glm::translate(glm::scale(textMat, glm::vec3(0.5,0.5,0.5)), glm::vec3(0,-3,0));
    
    sgct_text::print3d( sgct_text::FontManager::instance()->getFont("font", 24), gEngine->getActiveModelViewProjectionMatrix() * textMat, creditText.c_str());

	gParticles->move(delta);
	gParticles->draw(delta);
	glDisable(GL_DEPTH_TEST);

}

//Checking the time since the program started, not sure if we need this either.
void myPreSyncFun()
{
	//Checks so the gEnginenode is actually the master.
	if( gEngine->isMaster() )
	{
		//Sets the current time since the program started
		masterDelta.setVal(gEngine->getDt());
	}
}
//We need this to sync the variables trough the cluster
void myEncodeFun()
{
	sgct::SharedData::instance()->writeDouble(&masterDelta);
 	sgct::SharedData::instance()->writeFloat(&windDirX);
 	sgct::SharedData::instance()->writeFloat(&windDirY);
 	sgct::SharedData::instance()->writeFloat(&windDirZ);
 	sgct::SharedData::instance()->writeFloat(&vortFactorX);
 	sgct::SharedData::instance()->writeFloat(&vortFactorY);
 	sgct::SharedData::instance()->writeFloat(&vortFactorZ);
	sgct::SharedData::instance()->writeFloat(&gravFactor);
 	sgct::SharedData::instance()->writeFloat(&positionX);
 	sgct::SharedData::instance()->writeFloat(&positionZ);
	sgct::SharedData::instance()->writeFloat(&particleSize);
 	sgct::SharedData::instance()->writeInt(&radius);
 	sgct::SharedData::instance()->writeFloat(&fadeDistance);
	sgct::SharedData::instance()->writeBool(&sharedPause);
	sgct::SharedData::instance()->writeBool(&showGraph);
	sgct::SharedData::instance()->writeBool(&showStats);
	sgct::SharedData::instance()->writeBool(&showObject);
}

//We need this to sync the variables trough the cluster
void myDecodeFun()
{
	sgct::SharedData::instance()->readDouble(&masterDelta);
	sgct::SharedData::instance()->readFloat(&windDirX);
	sgct::SharedData::instance()->readFloat(&windDirY);
	sgct::SharedData::instance()->readFloat(&windDirZ);
	sgct::SharedData::instance()->readFloat(&vortFactorX);
	sgct::SharedData::instance()->readFloat(&vortFactorY);
	sgct::SharedData::instance()->readFloat(&vortFactorZ);
	sgct::SharedData::instance()->readFloat(&gravFactor);
	sgct::SharedData::instance()->readFloat(&positionX);
	sgct::SharedData::instance()->readFloat(&positionZ);
	sgct::SharedData::instance()->readFloat(&particleSize);
	sgct::SharedData::instance()->readInt(&radius);
	sgct::SharedData::instance()->readFloat(&fadeDistance);
	sgct::SharedData::instance()->readBool(&sharedPause);
	sgct::SharedData::instance()->readBool(&showGraph);
	sgct::SharedData::instance()->readBool(&showStats);
	sgct::SharedData::instance()->readBool(&showObject);
}

//Shows stats and graph depending on if the variables are true or not. Dont know if we need this? Currently set to false.
void myPostSyncPreDrawFun()
{
	gParticles->pauseControl(sharedPause.getVal());
	gWind->setAcceleration((windDirX.getVal()*0.01f), (windDirY.getVal()*0.01f), (windDirZ.getVal()*0.01f));
	gTurbine->setForce((vortFactorX.getVal()*0.1f), (vortFactorY.getVal()*0.1f), (vortFactorZ.getVal()*0.1f));
	gTurbine->setPosition((positionX.getVal()), (positionZ.getVal()));
	gTurbine->setRadius(radius.getVal());
	gGrav->init(gravFactor.getVal());
	gParticles->setFadeDistance(fadeDistance.getVal()*0.1f);
	gParticles->setParticleSize(particleSize.getVal()*0.001f);
}


//Used to alter certain values when sent from GUI. This way we can alter the fields or change gravity in realtime!
void externalControlCallback(const char * receivedChars, int size)
{
	//Checks so the gEnginenode is actually the master.
	if(gEngine->isMaster())
	{
		if(size >= 6 && strncmp(receivedChars, "winX", 4) == 0)
		{
			//We need an int.
 			float tmpVal = atof(receivedChars + 5);
 			windDirX.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "winY", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
 			windDirY.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "winZ", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
 			windDirZ.setVal(tmpVal);
		}
		else if(size >= 6 && strncmp(receivedChars, "vorX", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			vortFactorX.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "vorY", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			vortFactorY.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "vorZ", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			vortFactorZ.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "posX", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			positionX.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "posZ", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			positionZ.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "radi", 4) == 0)
		{
			//We need an int.
			int tmpVal = atoi(receivedChars + 5);
			radius.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "paus", 4) == 0)
		{
			int tmpVal = atoi(receivedChars + 5);
			sharedPause.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "grav", 4) == 0)
		{
			//We need an int.
			float tmpVal = atof(receivedChars + 5);
			gravFactor.setVal(-tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "fade", 4) == 0)
		{
			float tmpVal = atof(receivedChars + 5);
			fadeDistance.setVal(tmpVal);
		}

		else if(size >= 6 && strncmp(receivedChars, "stats", 5) == 0)
		{
			int tmpVal = atoi(receivedChars + 6);
			showGraph.setVal(tmpVal);
			gEngine->setDisplayInfoVisibility(showGraph.getVal());

		}

		else if(size >= 6 && strncmp(receivedChars, "graph", 5) == 0)
		{
			int tmpVal = atoi(receivedChars + 6);
			showStats.setVal(tmpVal);
			gEngine->setStatsGraphVisibility(showStats.getVal());

		}

		else if (size >= 6 && strncmp(receivedChars, "info", 4) == 0)
		{
			gParticles->printFields();
		}

		else if (size >= 6 && strncmp(receivedChars, "part", 4) == 0)
		{
			float tmpVal = atof(receivedChars + 5);
			particleSize.setVal(tmpVal);
		}

		else if (size >= 6 && strncmp(receivedChars, "obje", 4) == 0)
		{
			int tmpVal = atoi(receivedChars + 5);
			showObject.setVal(tmpVal);
			cout << showObject.getVal();
		}


	}
}
