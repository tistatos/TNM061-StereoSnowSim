#ifndef __DEBUGFIELD_H__
#define __DEBUGFIELD_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"
#include "ParticleSystem.h"

class ParticleSystem;

class DebugField
{
	public:
		DebugField(sgct::Engine* engine);
		void init();
		void draw(Field* f);
		void draw(Field& f);
		void draw(ParticleSystem* p);
		void toggleDebug() { mShowDebug = !mShowDebug; };
		void enableDebug() { mShowDebug = true; };
		void disableDebug() { mShowDebug = false; };

	private:
		sgct::Engine* mEngine;
		GLint mMatrixLocation;
		GLint mTransformLocation;
		// GLint arrowVA[];
		bool mShowDebug;
};

#endif // __DEBUGFIELD_H__
