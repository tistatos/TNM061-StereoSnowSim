#include "ObjectParticle.h"

ObjectParticle::ObjectParticle(sgct::Engine* engine) : ParticleSystem(engine)
{
	mObject = new Object(engine);
}

bool ObjectParticle::initialize()
{
	mObject->loadObj("objects/cube.obj", "objects/tree.png");
	mTexture.mTextureName = "objtest";
	mTexture.mTextureFile = "objects/tree.png";
	setTexture(mTexture.mTextureName, mTexture.mTextureFile);
	mShader.mShaderName = "ObjectParticle";
	mShader.mVertexFile = "shaders/particle.vert";
	mShader.mFragmentFile = "shaders/particle.frag";

	for (int i = 0; i < mParticlesAmount; ++i)
	{
		mParticles[i].mLife = 0.0f;
		mParticles[i].mDistance = 1000.0f;
		mParticles[i].mIsReset = false;
	}

	//Billboard that all particles share
	int vertexCount = mObject->getVertexCount();
	GLuint indexBufferLoc = mObject->getIndexBuffer();

	GLfloat vertexBufferData[vertexCount];
	GLfloat* vertexData = mObject->getVertexList();

	for (int i = 0; i < vertexCount; ++i)
	{
		vertexBufferData[i] = *(vertexData+sizeof(GLfloat)*i);
	}

    //Fix buffers
	glGenVertexArrays(1, &mVertexArray);
	glBindVertexArray(mVertexArray);

	//add billboard, its static since it wont change
	glGenBuffers(1, &mBillBoardVB);
	glBindBuffer(GL_ARRAY_BUFFER, mBillBoardVB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData),
					vertexBufferData, GL_STATIC_DRAW);

	GLuint indexBuffer;

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, indexBuffer);
	glCopyBufferSubData(indexBufferLoc, indexBuffer, 0,0,30);


	//Prepare for position buffers
	glGenBuffers(1, &mParticlePositionBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
	glBufferData(GL_ARRAY_BUFFER, mParticlesAmount*4*4*sizeof(GLfloat),
				 NULL, GL_STREAM_DRAW);

	//Prepare for position buffers
	glGenBuffers(1, &mParticleLifeBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mParticleLifeBuffer);
	glBufferData(GL_ARRAY_BUFFER, mParticlesAmount*sizeof(GLfloat),
				 NULL, GL_STREAM_DRAW);

	glBindVertexArray(0);

	size_t handle;

	//add texture for snowflake
	sgct::TextureManager::instance()->setAnisotropicFilterSize(8.0f);
	sgct::TextureManager::instance()->setCompression(sgct::TextureManager::S3TC_DXT);
	sgct::TextureManager::instance()->loadTexure(handle, mTexture.mTextureName, mTexture.mTextureFile, true);


	//Create shader
	bool shaderExists = sgct::ShaderManager::instance()->shaderProgramExists(mShader.mShaderName);
	if(!shaderExists)
	{
		bool shaderResult = sgct::ShaderManager::instance()->addShaderProgram(mShader.mShaderName, mShader.mVertexFile, mShader.mFragmentFile);
		if(shaderResult == false)
		{
			return false;
		}
	}
	//Bind shader and get location of MVP matrix
	sgct::ShaderManager::instance()->bindShaderProgram(mShader.mShaderName);

	mViewProjectionLoc = sgct::ShaderManager::instance()->getShaderProgram(mShader.mShaderName).getUniformLocation( "VP" );

	//Unbind shader
	sgct::ShaderManager::instance()->unBindShaderProgram();

    //Particle shader is now initialized
	mInitialized = true;

	return true;


}

void ObjectParticle::move(double delta)
{
	ParticleSystem::move(delta);
}

void ObjectParticle::draw(double delta)
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
				reset(mParticles[particleIndex]);
		}

		// this lovely row is broken
		// mDebugField->draw(this);

		sortParticles();
		int particleCount = 0;
		for(int i=0; i< mParticlesAmount; i++)
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

				mParticleLifeData[particleCount] = p.mLife;

				particleCount++;
			}
		}

		glBindBuffer(GL_ARRAY_BUFFER, mParticlePositionBuffer);
        glBufferData(GL_ARRAY_BUFFER, mParticlesAmount * 4 * 4 * sizeof(GLfloat), NULL, GL_STREAM_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, particleCount * sizeof(GLfloat) * 4 * 4, mParticlePositionData);

        // life stuff
		glBindBuffer(GL_ARRAY_BUFFER, mParticleLifeBuffer);
        glBufferData(GL_ARRAY_BUFFER, mParticlesAmount * sizeof(GLfloat), NULL, GL_STREAM_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, particleCount * sizeof(GLfloat), mParticleLifeData);

		glEnable(GL_BLEND);
		glDisable(GL_CULL_FACE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		sgct::ShaderManager::instance()->bindShaderProgram( mShader.mShaderName );

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, sgct::TextureManager::instance()->getTextureByName(mTexture.mTextureName));
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


		glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix();
		int fadeDistanceLoc = sgct::ShaderManager::instance()->getShaderProgram(mShader.mShaderName).getUniformLocation("fadeDistanceIn");
		int particleSizeLoc = sgct::ShaderManager::instance()->getShaderProgram(mShader.mShaderName).getUniformLocation("particleSize");

		glUniformMatrix4fv(mViewProjectionLoc, 1, GL_FALSE, &MVP[0][0]);

		glUniform1f(fadeDistanceLoc,mFadeDistance);
		glUniform1f(particleSizeLoc,mParticleSize);

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

		glVertexAttribPointer(pos, 4, GL_FLOAT,  GL_FALSE, sizeof(GLfloat)*4*4, (void*)(0));
		glVertexAttribPointer(pos + 1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4*4, (void*)(sizeof(float)*4));
		glVertexAttribPointer(pos + 2, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4*4, (void*)(sizeof(float)*8));
		glVertexAttribPointer(pos + 3, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*4*4, (void*)(sizeof(float)*12));

		int lifePos  = sgct::ShaderManager::instance()->getShaderProgram(mShader.mShaderName).getAttribLocation("inLife");
		glEnableVertexAttribArray(lifePos);
		glBindBuffer(GL_ARRAY_BUFFER, mParticleLifeBuffer);
		glVertexAttribPointer(lifePos, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat), (void*)(0));

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
		glVertexAttribDivisor(lifePos, 1);

        glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 36, particleCount);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(pos);
		glDisableVertexAttribArray(pos + 1);
		glDisableVertexAttribArray(pos + 2);
		glDisableVertexAttribArray(pos + 3);
		glDisableVertexAttribArray(lifePos);

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D,0);

		sgct::ShaderManager::instance()->unBindShaderProgram();
		mFirstDraw = false;
		//std::cout << "Drawing all them pritty particles\n";
	}
}

void ObjectParticle::destroy()
{
	ParticleSystem::destroy();
}

void ObjectParticle::calculateLife(Particle& p, double delta)
{
	glm::vec3 pos = p.position();
	if(pos.y < -2.0f || abs(pos.x) > 15.0f || abs(pos.z) > 15.0f || abs(pos.y) > 25.0f)
	{
		p.mLife -= delta;
		p.mIsReset = false;
	}
}

void ObjectParticle::increaseLife(Particle& p, double delta)
{
	p.mLife += delta;

	// std::cout << "increasing life: " << p.mLife << std::endl;
}

/**
 * reset particle p
 * @param p
 */
void ObjectParticle::reset(Particle& p)
{
	if(mFirstDraw)
	{
		p.mLife = 5.0f; //mFirstDraw ? 0.1f : 5.0f;
	}

	float xval = getRandom(-10.0f, 10.0f);
	float yval = mFirstDraw ? getRandom(0.0f, 25.0f) : getRandom(10.0f, 17.0f);
	float zval = getRandom(-10.0f, 10.0f);

 	p.mMatrix[3][0] = xval; // x
	p.mMatrix[3][1] = yval; // y
	p.mMatrix[3][2] = zval; // z

	xval = getRandom(-1.0f, 0.0f);
	yval = getRandom(-1.0f, 1.0f);
	zval = getRandom(-1.0f, 1.0f);

	//Rotate particle around random vector
	glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), getRandom(-180.0f, 180.0f), glm::vec3(xval, yval, zval));

	p.mMatrix *= rotation;

	//Randomize initial velocity
	xval = getRandom(-0.1f, 0.1f);
	yval = getRandom(-0.1f, 0.1f);
	zval = getRandom(-0.1f, 0.1f);

	p.mVelocity = glm::vec3(xval,yval,zval);
	p.mIsReset = true;

}
