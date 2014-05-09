#ifndef __DEBUGFIELD_H__
#define __DEBUGFIELD_H__

#include <iostream>
#include "sgct.h"
#include "Field.h"
#include "HelperFunctions.h"

class DebugField
{
	public:
		DebugField(sgct::Engine* engine);
		void init();
		void draw(){};

	private:
		sgct::Engine* mEngine;
		GLint mMatrixLocation;
		GLint mTransformLocation;
		GLint arrowVA[];
};

#endif // __VORTEX_H__
