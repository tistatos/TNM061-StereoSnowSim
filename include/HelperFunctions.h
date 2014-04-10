#ifndef __HELPERFUNCTIONS_H__
#define __HELPETFUNCTIONS_H__

#include "sgct.h"
#include <iostream>

std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec);

void initRandom();

float getRandom();

float getRandom(float a, float b);

#endif