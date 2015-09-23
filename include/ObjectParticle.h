#ifndef __OBJECTPARTICLE_H__
#define __OBJECTPARTICLE_H__

#include <string.h>

#include "ParticleSystem.h"
#include "sgct.h"
#include "HelperFunctions.h"
#include "ObjSystem.h"


using namespace std;

class ObjectParticle : public ParticleSystem
{
public:
	ObjectParticle(sgct::Engine* engine);
	bool initialize();

	void draw(double delta);

	void move(double delta);
	void destroy();
private:
	Object* mObject;
	void reset(Particle &p);
	void calculateLife(Particle& p, double delta);
	void increaseLife(Particle& p, double delta);




};


#endif


