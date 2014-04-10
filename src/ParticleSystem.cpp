#include "ParticleSystem.h"
#include <iostream>
#include "HelperFunctions.h"

/**
 * Constructor for particle field
 *
 * @param engine pointer to SGCT engine
 */
ParticleSystem::ParticleSystem(sgct::Engine* engine)
{
	mEngine = engine;
	mInitialized = false;

	mVertexArray = 0;

	mLastUsedParticle = 0;

	mBillBoardVB = 0;
	mParticlePositionBuffer = 0;
	mParticlePositionData = new GLfloat[MAX_PARTICLES * 4];
}

/**
 * Initialize Particle system
 *
 */
void ParticleSystem::initialize()
{
	//Billboard that all particles share
	static const GLfloat vertexBufferData[] =
	{
		-1 * PARTICLE_SIZE, -1 * PARTICLE_SIZE, 0.0f,
		PARTICLE_SIZE, -1 * PARTICLE_SIZE, 0.0f,
		-1 * PARTICLE_SIZE, PARTICLE_SIZE, 0.0f,
		PARTICLE_SIZE, PARTICLE_SIZE, 0.0f
	};

	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    //Fix buffers
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);
	//add billboard, its static since it wont change
	glGenBuffers(1, &mBillBoardVB);
	glBindBuffer(GL_ARRAY_BUFFER, mBillBoardVB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData),
				 vertexBufferData, GL_STATIC_DRAW);

	//Prepare for position buffers
	glGenBuffers(1, &mParticlePositionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
	glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES*4*sizeof(GLfloat),
				 NULL, GL_STREAM_DRAW);

	glBindVertexArray(0);

	//Create shader
	sgct::ShaderManager::instance()->addShaderProgram("particle", "particle.vert", "particle.frag");

	//Bind shader and get location of MVP matrix
	sgct::ShaderManager::instance()->bindShaderProgram( "particle" );

	mMatrixLoc = sgct::ShaderManager::instance()->getShaderProgram("particle").getUniformLocation( "VP" );
	//Unbind shader
	sgct::ShaderManager::instance()->unBindShaderProgram();

	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    //Particle shader is now initialized
	mInitialized = true;

}
/**
 * Get the particle that isn't alive
 * @return index of particle
 */
int ParticleSystem::findLastParticle()
{
	for (int i = mLastUsedParticle; i < MAX_PARTICLES; ++i)
	{
		if(mParticles[i].mLife <= 0)
		{
			mLastUsedParticle = i;
			return i;
		}
	}

	for (int i = 0; i < MAX_PARTICLES; ++i)
	{
		if(mParticles[i].mLife <= 0)
		{
			mLastUsedParticle = i;
			return i;
		}
	}

	return 0;
}

/**
 * Draw Particle
 *
 * @param delta time delta
 */
void ParticleSystem::draw(double delta)
{
	if(mInitialized)
	{

		//limit the amount of particles created each frame
		int newParticles = (int)(delta*10000.0);
		if(newParticles > (int)(0.001f*10000.0))
		{
			newParticles = (int)(0.001f*10000.0);
		}

		//std::cout << "Creating " << newParticles << " new particles" << std::endl;

		for (int i = 0; i < newParticles; ++i)
		{
			int particleIndex = findLastParticle();

			reset(particleIndex);
		}

		int particleCount = 0;
		for(int i=0; i< MAX_PARTICLES; i++)
		{
			Particle &p = mParticles[i];

			if(p.mLife > 0.0f)
			{
				mParticlePositionData[4*particleCount+0] = p.mPosition.x;
                mParticlePositionData[4*particleCount+1] = p.mPosition.y;
                mParticlePositionData[4*particleCount+2] = p.mPosition.z;

                mParticlePositionData[4*particleCount+3] = p.mSize;
			}
			particleCount++;
		}

		glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
        glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, particleCount * sizeof(GLfloat) * 4, mParticlePositionData);

		glEnable(GL_BLEND);
		glDisable(GL_CULL_FACE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		sgct::ShaderManager::instance()->bindShaderProgram("particle");

		glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix();
		glUniformMatrix4fv(mMatrixLoc, 1, GL_FALSE, &MVP[0][0]);

		glBindVertexArray(mVertexArray);

        glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, mBillBoardVB);
		glVertexAttribPointer(
                    0,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    reinterpret_cast<void*>(0) // array buffer offset
            );
       	glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);

		glVertexAttribPointer(
                        1,
                        4,
                        GL_FLOAT,
                        GL_FALSE,
                        0,
						reinterpret_cast<void*>(0) // array buffer offset
                );
        // Draw the particules !
        // This draws many times a small triangle_strip (which looks like a quad).
        // This is equivalent to :
        // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4),
        // but faster.

        //FIXME
		glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
        glVertexAttribDivisor(1, 1); // positions : one per quad (its center)                 -> 1

        glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, particleCount);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

		glBindVertexArray(0);

		sgct::ShaderManager::instance()->unBindShaderProgram();
		// std::cout << "Drawing all them pritty particles\n";
	}
}

void ParticleSystem::destroy()
{
	if(mInitialized)
	{
		glDeleteBuffers(1, &mBillBoardVB);
		glDeleteBuffers(1, &mParticlePositionBuffer);

		glDeleteVertexArrays(1, &mVertexArray);

		mInitialized = false;

		delete[] mParticlePositionData;
	}
}

void ParticleSystem::move(double delta)
{
	// do gravity and shit on every particle
	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		// get ref to current particle
		Particle& p = mParticles[i];

		if(p.mLife > 0.0f)
		{
			glm::vec3 tempVelo;
			// loop through the fields, and sum the fields' velocity
			for(std::vector<Field*>::iterator f = fields.begin(); f != fields.end(); ++f)
			{
				tempVelo += (*f)->getVelocity(delta, p.mVelocity);
			}

			p.mVelocity = tempVelo;

			// reduce life? Has it passed some sort of boundary?
			if(p.mPosition.y < -2)
			{
				p.mLife -= delta; // reduce life
				p.mVelocity.y = 0; // stop vertical speed!
			}

			// apply the velocity
			p.mPosition += p.mVelocity*(float)delta;
		}
		else
		{
			reset(p); // reset particle
		}
	}
}

/**
 * reset the particle at index index
 * @param index the index
 */
void ParticleSystem::reset(int index)
{
	reset(mParticles[index]);
}

/**
 * reset particle p
 * @param p
 */
void ParticleSystem::reset(Particle& p)
{
	p.mLife = 5.0f;
	float xval = getRandom(-10.0f, 10.0f);
	float yval = getRandom(2.0f, 10.0f);
	float zval = getRandom(-10.0f, 10.0f);

	// std::cout << xval << " " << yval << std::endl;
	p.mPosition = glm::vec3(xval,yval,zval);
	xval = getRandom(-0.3f, 0.3f);
	yval = getRandom(-0.3f, 0.3f);
	zval = getRandom(-0.3f, 0.3f);

	p.mVelocity = glm::vec3(xval,yval,zval);

    p.mSize = 0.3f;
}

void ParticleSystem::addField(Field *f)
{
	fields.push_back(f);
}
