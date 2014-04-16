#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include <vector>
#include <string>
#include "sgct.h"
#include "Particle.h"
#include "Shader.h"
#include "Texture.h"

class Field;

const int MAX_PARTICLES = 5000;
const float PARTICLE_SIZE = 0.1f;

using namespace std;

class ParticleSystem
{
public:
	ParticleSystem(sgct::Engine* engine);
	virtual void initialize();
	virtual void draw(double delta);
	virtual void destroy();
	virtual void move(double delta);

	void addField(Field *f);
	void printFields();
	void setTexture(string name, string file);
	void setShader(string name, string vertFile, string fragFile);

protected:
	virtual void sortParticles();
	int findLastParticle();
	void reset(int index);
	virtual void calculateLife(Particle& p, double delta);
	virtual void reset(Particle& p);

	bool mInitialized; /// Is the particle system initalized?

	Shader mShader; //Struct with shader data
	Texture mTexture; //Strcut with Texture data
	sgct::Engine* mEngine; /// Pointer to SGCT engine

	Particle mParticles[MAX_PARTICLES]; /// array of particles

	int mLastUsedParticle; /// used for quicker update in particle system

	GLuint mVertexArray; /// pointer for vertex array on GPU
	GLuint mBillBoardVB; /// Vertex buffer for billboard
	GLuint mParticlePositionBuffer; /// Buffer for particle's position data
	GLfloat* mParticlePositionData; /// temp storage to move data from particles to buffer
	std::vector<Field*> fields; /// the fields that affect the particles

	GLint mViewProjectionLoc; /// matrix loc in shader

};


#endif
