#ifndef __PARTICLE_SYSTEM_H__
#define __PARTICLE_SYSTEM_H__

#include <vector>
#include "sgct.h"
#include "Field.h"

struct Particle
{
	glm::vec3 mPosition;
	glm::vec3 mVelocity;

	float mSize;
	float mLife;
};

const int MAX_PARTICLES = 1000;

class ParticleSystem
{
	public:
		ParticleSystem(sgct::Engine* engine);
		void initialize();
		void draw(double delta);
		void destroy();
		void move(double delta);
		void addField(Field *f);
	private:
		int findLastParticle();
		void reset(int index);
		void reset(Particle& p);

		bool mInitialized; /// Is the particle system initalized?
		sgct::Engine* mEngine; /// Pointer to SGCT engine
		Particle mParticles[MAX_PARTICLES]; /// array of particles
		int mLastUsedParticle; /// used for quicker update in particle system
		GLuint mVertexArray; /// pointer for vertex array on GPU
		GLint mMatrixLoc; /// matrix loc in shader
		GLuint mBillBoardVB; /// Vertex buffer for billboard
		GLuint mParticlePositionBuffer; /// Buffer for particle's position data
		GLfloat* mParticlePositionData; /// temp storage to move data from particles to buffer
		std::vector<Field*> fields; /// the fields that affect the particles
};


#endif
