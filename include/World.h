#ifndef __WORLD_H__
#define __WORLD_H__

#include "sgct.h"

using namespace std;

class World
{
	public:
		World(sgct::Engine* engine);
		void setBoxSize(float boxSize);
		void createSkyBox();
		void setTexture(string name, string textureFile);
		void loadTexture();
		void initializeWorld();
		void drawWorld();
		void cleanUpWorld();
	private:
		sgct::Engine* mEngine;
		sgct_utils::SGCTBox* mSphere;
		GLint mMatrixLocation;
		GLint mTextureLocation;
		float mSize;
		size_t mTextureHandle; //holds the texture handle
		string mName;
		string mTextureFile;
};

#endif