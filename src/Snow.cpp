#include "ParticleSystem.h"
#include "Snow.h"
#include "HelperFunctions.h"


Snow::Snow(sgct::Engine* engine) : ParticleSystem(engine)
{
	mShader.mShaderName = "snow";
	mShader.mVertexFile = "shaders/particle.vert";
	mShader.mFragmentFile = "shaders/particle.frag";

	mTexture.mTextureName = "snow";
	mTexture.mTextureFile = "img/flaky.png";
}

bool Snow::initialize()
{
	return ParticleSystem::initialize();
}

void Snow::move(double delta)
{
	ParticleSystem::move(delta);
}

void Snow::draw(double delta)
{
	ParticleSystem::draw(delta);
}

void Snow::destroy()
{
	ParticleSystem::destroy();
}

void Snow::calculateLife(Particle& p, double delta)
{
	glm::vec3 pos = p.position();
	if(pos.y < -2.0f || abs(pos.x) > 15.0f || abs(pos.z) > 15.0f || abs(pos.y) > 25.0f)
	{
		p.mLife -= delta;
		p.mIsReset = false;
	}
}

void Snow::increaseLife(Particle& p, double delta)
{
	p.mLife += delta;

	// std::cout << "increasing life: " << p.mLife << std::endl;
}

/**
 * reset particle p
 * @param p
 */
void Snow::reset(Particle& p)
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
