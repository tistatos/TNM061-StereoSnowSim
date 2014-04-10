#ifndef __WORLD_H__
#define __WORLD_H__

#include "sgct.h"

using namespace std;

class World
{
	public:
		World(sgct::Engine* engine);
		void setRadius(float radius);
		void setSegments(unsigned int segments);
		void createSphere();
		void setTexture(string name, string textureFile);
		void loadTexture();
		void initializeWorld();
		void drawWorld();
		void cleanUpWorld();
	private:
		sgct::Engine* mEngine;
		sgct_utils::SGCTSphere* mSphere;
		GLint mMatrixLocation;
		GLint mTextureLocation;
		float mRadius;
		unsigned int mSegments; //only non-negative integers
		size_t mTextureHandle; //holds the texture handle
		string mName;
		string mTextureFile;
};

#endif