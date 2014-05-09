#include "ParticleSystem.h"
#include <iostream>
#include <algorithm>
#include "HelperFunctions.h"
#include "Field.h"

/**
 * Constructor for particle field
 *
 * @param engine pointer to SGCT engine
 */
ParticleSystem::ParticleSystem(sgct::Engine* engine)
{
	mEngine = engine;
	mInitialized = false;

	mShowFields = false; // do not show fields by default

	mVertexArray = 0;

	mLastUsedParticle = 0;

	mBillBoardVB = 0;
	mParticlePositionBuffer = 0;
	mParticlePositionData = new GLfloat[MAX_PARTICLES * 4 * 4];
}

/**
 * Initialize Particle system
 *
 */
bool ParticleSystem::initialize()
{
	//Billboard that all particles share
	static const GLfloat vertexBufferData[] =
	{
		-1.0f , -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f,

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
	glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES*4*4*sizeof(GLfloat),
				 NULL, GL_STREAM_DRAW);

	glBindVertexArray(0);


	size_t handle;

	//add texture for snowflake
	sgct::TextureManager::instance()->setAnisotropicFilterSize(8.0f);
	sgct::TextureManager::instance()->setCompression(sgct::TextureManager::S3TC_DXT);
	sgct::TextureManager::instance()->loadTexure(handle, mTexture.mTextureName, mTexture.mTextureFile, true);


	//Create shader
	bool shaderResult = sgct::ShaderManager::instance()->addShaderProgram(mShader.mShaderName, mShader.mVertexFile, mShader.mFragmentFile);
	if(shaderResult == false)
	{
		return false;
	}
	//Bind shader and get location of MVP matrix
	sgct::ShaderManager::instance()->bindShaderProgram( mShader.mShaderName );

	mViewProjectionLoc = sgct::ShaderManager::instance()->getShaderProgram( mShader.mShaderName ).getUniformLocation( "VP" );

	//Unbind shader
	sgct::ShaderManager::instance()->unBindShaderProgram();

	// Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);



    //Particle shader is now initialized
	mInitialized = true;

	return true;
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

	return -1;
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

		for (int i = 0; i < newParticles; ++i)
		{
			int particleIndex = findLastParticle();
			if(particleIndex >= 0)
				reset(particleIndex);
		}

		// show fields if mShowFields is true
		showFields();

		sortParticles();
		int particleCount = 0;
		for(int i=0; i< MAX_PARTICLES; i++)
		{
			Particle &p = mParticles[i];

			if(p.mLife > 0.0f)
			{
				// mParticlePositionData[4*particleCount+0] = p.mMatrix[3][0];
				// mParticlePositionData[4*particleCount+1] = p.mMatrix[3][1];
				// mParticlePositionData[4*particleCount+2] = p.mMatrix[3][2];
				// mParticlePositionData[4*particleCount+3] = p.mSize;

				mParticlePositionData[16*particleCount+0] = p.mMatrix[0][0];
				mParticlePositionData[16*particleCount+1] = p.mMatrix[0][1];
				mParticlePositionData[16*particleCount+2] = p.mMatrix[0][2];
				mParticlePositionData[16*particleCount+3] = p.mMatrix[0][3];
				mParticlePositionData[16*particleCount+4] = p.mMatrix[1][0];
				mParticlePositionData[16*particleCount+5] = p.mMatrix[1][1];
				mParticlePositionData[16*particleCount+6] = p.mMatrix[1][2];
				mParticlePositionData[16*particleCount+7] = p.mMatrix[1][3];
				mParticlePositionData[16*particleCount+8] = p.mMatrix[2][0];
				mParticlePositionData[16*particleCount+9] = p.mMatrix[2][1];
				mParticlePositionData[16*particleCount+10] = p.mMatrix[2][2];
				mParticlePositionData[16*particleCount+11] = p.mMatrix[2][3];
				mParticlePositionData[16*particleCount+12] = p.mMatrix[3][0];
				mParticlePositionData[16*particleCount+13] = p.mMatrix[3][1];
				mParticlePositionData[16*particleCount+14] = p.mMatrix[3][2];
				mParticlePositionData[16*particleCount+15] = p.mMatrix[3][3];

				particleCount++;
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
        glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * 4 * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, particleCount * sizeof(GLfloat) * 4 * 4, mParticlePositionData);

		glEnable(GL_BLEND);
		glDisable(GL_CULL_FACE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		sgct::ShaderManager::instance()->bindShaderProgram( mShader.mShaderName );

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sgct::TextureManager::instance()->getTextureByName(mTexture.mTextureName));

		glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix();

		glUniformMatrix4fv(mViewProjectionLoc, 1, GL_FALSE, &MVP[0][0]);

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
		int pos  = sgct::ShaderManager::instance()->getShaderProgram(mShader.mShaderName).getAttribLocation("transformmatrix");
		glEnableVertexAttribArray(pos);
		glEnableVertexAttribArray(pos + 1);
		glEnableVertexAttribArray(pos + 2);
		glEnableVertexAttribArray(pos + 3);
		glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);

		glVertexAttribPointer(pos, 4, GL_FLOAT,  GL_FALSE, sizeof(GLfloat) * 4 * 4, (void*)(0));
		glVertexAttribPointer(pos + 1, 4, GL_FLOAT, GL_FALSE,  sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float)*4));
		glVertexAttribPointer(pos + 2, 4, GL_FLOAT, GL_FALSE,  sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float)*8));
		glVertexAttribPointer(pos + 3, 4, GL_FLOAT, GL_FALSE,  sizeof(GLfloat) * 4 * 4, (void*)(sizeof(float)*12));

		//only position attribs
       	// glEnableVertexAttribArray(1);

		// glVertexAttribPointer(
  //                       1,
  //                       4,
  //                       GL_FLOAT,
  //                       GL_FALSE,
  //                       0,
		// 				reinterpret_cast<void*>(0) // array buffer offset
  //               );

        // Draw the particules !
        // This draws many times a small triangle_strip (which looks like a quad).
        // This is equivalent to :
        // for(i in ParticlesCount) : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4),
        // but faster.

        //FIXME
		glVertexAttribDivisor(0, 0); // particles vertices : always reuse the same 4 vertices -> 0
        glVertexAttribDivisor(pos, 1);
		glVertexAttribDivisor(pos + 1, 1);
		glVertexAttribDivisor(pos + 2, 1);
		glVertexAttribDivisor(pos + 3, 1);
        //glVertexAttribDivisor(1, 1); // positions : one per quad (its center)                 -> 1

        glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, particleCount);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(pos);
		glDisableVertexAttribArray(pos + 1);
		glDisableVertexAttribArray(pos + 2);
		glDisableVertexAttribArray(pos + 3);

		glBindVertexArray(0);

		sgct::ShaderManager::instance()->unBindShaderProgram();

		//std::cout << "Drawing all them pritty particles\n";
	}
}

void ParticleSystem::destroy()
{
	if(mInitialized)
	{
		glDeleteBuffers(1, &mBillBoardVB);
		glDeleteBuffers(1, &mParticlePositionBuffer);

		glDeleteVertexArrays(1, &mVertexArray);

		delete[] mParticlePositionData;

		mInitialized = false;
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
			// loop through the fields, and sum the fields' velocities
			for(std::vector<Field*>::iterator f = fields.begin(); f != fields.end(); ++f)
			{
				tempVelo += (*f)->getVelocity(delta, p);
			}

			p.mVelocity = tempVelo;

			calculateLife(p, delta);
			// apply the velocity
			glm::mat4 tran = glm::translate(glm::mat4(1.0f), p.mVelocity*(float)delta);
			//glm::mat4 rot =  glm::rotate( glm::mat4(1.0f), static_cast<float>(delta) * 10, glm::vec3(0.5f, 1.0f, 0.0f));
			p.mMatrix = tran * p.mMatrix;

			//distance is positions magnitude since camera is in the
			p.mDistance = glm::dot(p.position(),p.position());

		}
		else
		{
			reset(p); // reset particle
		}
	}
}


void ParticleSystem::calculateLife(Particle& p, double delta)
{
	p.mLife -= delta;
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
}

void ParticleSystem::addField(Field *f)
{
	fields.push_back(f);
}

void ParticleSystem::printFields()
{
	// loop through the fields, and print the fields' info
	for(std::vector<Field*>::iterator f = fields.begin(); f != fields.end(); ++f)
	{
		(*f)->printInfo();
	}
}

void ParticleSystem::showFields()
{
	if(mShowFields)
	{
		// loop through the fields, and show their arrows
		for(std::vector<Field*>::iterator f = fields.begin(); f != fields.end(); ++f)
		{
			(*f)->showField();
		}
	}
}

void ParticleSystem::toggleFields()
{
	mShowFields = !mShowFields;
	std::cout << "Field view is " << (mShowFields ? "ON" : "OFF") << std::endl;
}

void ParticleSystem::sortParticles()
{
	std::sort(&mParticles[0], &mParticles[MAX_PARTICLES]);
}
