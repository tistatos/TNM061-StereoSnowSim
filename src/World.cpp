#include <stdlib.h>
#include "World.h"

World::World(sgct::Engine* engine)
{
	mEngine = engine;
	mSphere = nullptr;
	mRadius = 0;
	mSegments = 0;
	mName = "";
	mTextureFile = "";
}

void World::setRadius(float radius)
{
	mRadius = radius;
}

void World::setSegments(unsigned int segments)
{
	mSegments = segments;
}

void World::createSphere()
{
	mSphere = new sgct_utils::SGCTSphere(mRadius, mSegments);
}


void World::setTexture(string name, string textureFile)
{
	mName = name;
	mTextureFile = textureFile;
}

void World::loadTexture()
{
	//NOTE: missing a t in loadTexure
	//sgct::TextureManager::instance()->loadTexure(mTextureHandle, mName, mTextureFile, true);
	sgct::TextureManager::instance()->loadTexure(mTextureHandle, "night", "night.png", true);
}

void World::initialize()
{
	createSphere();
	loadTexture();
}
