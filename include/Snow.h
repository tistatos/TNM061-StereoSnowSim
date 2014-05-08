#ifndef __SNOW_H__
#define __SNOW_H__

#include <string.h>

#include "ParticleSystem.h"
#include "sgct.h"


using namespace std;

class Snow : public ParticleSystem
{
public:
	Snow(sgct::Engine* engine);
	bool initialize();

	void reset(Particle& p);
	void draw(double delta);

	void move(double delta);
	void destroy();
private:
	void calculateLife(Particle& p, double delta);

};

#endif