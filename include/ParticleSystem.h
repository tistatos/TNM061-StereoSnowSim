#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "sgct.h"
#include "Particle.h"
#include "Shader.h"
#include "Texture.h"
#include "Field.h"
#include "DebugField.h"
#include "HelperFunctions.h"

class Field;
class DebugField;

const int MAX_PARTICLES = 10000;
const float PARTICLE_SIZE = 0.1f;

using namespace std;

class ParticleSystem
{
public:
	ParticleSystem(sgct::Engine* engine);
	virtual bool initialize();
	virtual void draw(double delta);
	virtual void destroy();
	virtual void move(double delta);

	void addField(Field *f);
	void printFields();
	void setTexture(string name, string file);
	void setShader(string name, string vertFile, string fragFile);
	void toggleDebug();
	void setFadeDistance(float d);
	void enableFieldDebug();
	void toggleFieldDebug();
	void pauseControl(bool status);
	void togglePause();
	void setAmount(int amount);

	std::vector<Field*> getFields() {return mFields;};

protected:
	virtual void sortParticles();
	int findLastParticle();
	void reset(int index);
	virtual void calculateLife(Particle& p, double delta);
	virtual void reset(Particle& p);

	float mFadeDistance; /// Distance from camera when particles should fade away to not create crossedeye effect
	bool mInitialized; /// Is the particle system initalized?
	bool mPaused;

	int mParticlesAmount; /// the number of particles we want

	DebugField* mDebugField; /// the debug field stuff

	Shader mShader; //Struct with shader data
	Texture mTexture; //Strcut with Texture data
	sgct::Engine* mEngine; /// Pointer to SGCT engine

	Particle mParticles[MAX_PARTICLES]; /// array of particles

	int mLastUsedParticle; /// used for quicker update in particle system

	GLuint mVertexArray; /// pointer for vertex array on GPU
	GLuint mBillBoardVB; /// Vertex buffer for billboard
	GLuint mParticlePositionBuffer; /// Buffer for particle's position data
	GLuint mParticleLifeBuffer; /// Buffer for particle's position data
	GLfloat* mParticlePositionData; /// temp storage to move data from particles to buffer
	GLfloat* mParticleLifeData; /// temp storage to move data from particles to buffer
	std::vector<Field*> mFields; /// the fields that affect the particles

	GLint mViewProjectionLoc; /// matrix loc in shader

	bool mFirstDraw; //Ugly as fuck solution

};


#endif
