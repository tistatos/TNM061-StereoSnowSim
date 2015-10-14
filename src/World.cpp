#include <stdlib.h>
#include "World.h"

World::World(sgct::Engine* engine)
{
	mEngine = engine;
	mSphere = nullptr;
	mMatrixLocation = -1;
	mSize = 100;
	mName = "sky";
	mTextureFile = "img/skybox_texture_1_dev.jpg";
}

void World::setBoxSize(float boxSize)
{
	mSize = boxSize;
}

void World::createSkyBox()
{
	//create a box with size and texturemapping mode
	mSphere = new sgct_utils::SGCTBox(mSize, sgct_utils::SGCTBox::SkyBox);
}


void World::setTexture(string name, string textureFile)
{
	mName = name;
	mTextureFile = textureFile;
}

void World::loadTexture()
{
	//NOTE: missing a t in loadTexure
	sgct::TextureManager::instance()->loadTexure(mName, mTextureFile, true);
}

void World::initializeWorld()
{
	createSkyBox();
	loadTexture();

	//add shaders
	sgct::ShaderManager::instance()->addShaderProgram("world", "shaders/World.vert", "shaders/World.frag");

	//retrieve matrix location
	mMatrixLocation = sgct::ShaderManager::instance()->getShaderProgram("world").getUniformLocation("MVP");
	//mTextureLocation = sgct::ShaderManager::instance()->getShaderProgram("banan").getUniformLocation("tex");
	//glUniform1i(mTextureLocation, 0);

	sgct::ShaderManager::instance()->unBindShaderProgram();
}

void World::drawWorld()
{
	//do depth comparisons and pdate the depth buffer
	//cull polygons not shown in window
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glFrontFace(GL_CW);

	//create a scene matrix incase we want movement
	glm::mat4 sceneMatrix = glm::mat4(1.0f);

	glm::mat4 MVP = mEngine->getActiveModelViewProjectionMatrix() * sceneMatrix;

	//select active texture unit
	glActiveTexture(GL_TEXTURE0);
	//bind a named texture to a texturing target
	glBindTexture(GL_TEXTURE_2D, sgct::TextureManager::instance()->getTextureId(mName));

	sgct::ShaderManager::instance()->bindShaderProgram("world");

	glUniformMatrix4fv(mMatrixLocation, 1, GL_FALSE, &MVP[0][0]);

	mSphere->draw();

	sgct::ShaderManager::instance()->unBindShaderProgram();

	glDisable(GL_CULL_FACE);
}

void World::cleanUpWorld()
{
	if(mSphere != nullptr)
		delete mSphere;
}
