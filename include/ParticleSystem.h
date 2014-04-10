#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include "sgct.h"
#include "Field.h"

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mVelocity;

	float mSize;
	float mLife;
};

const int MAX_PARTICLES = 100;

class ParticleSystem
{
	public:
		ParticleSystem(sgct::Engine* engine);
		void initialize();
		void draw(double delta);
		void destroy();
		void move(double delta);
		void reset(int index);
		void reset(Particle& p);
		void addField(Field *f);
	private:
		int findLastParticle();


		bool mInitialized;
		sgct::Engine* mEngine;
		Particle mParticles[MAX_PARTICLES];
		int mLastUsedParticle;
		GLuint mVertexArray;
		GLint mMatrixLoc;
		GLuint mBillBoardVB;
		GLuint mParticlePositionBuffer;
		GLuint mParticleColorBuffer;
		GLfloat* mParticlePositionData;
		std::vector<Field*> fields;

};


#endif
