#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include "sgct.h"
#include <iostream>
#define PI 3.14159265359

std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec);
std::ostream &operator<< (std::ostream &out, const glm::vec2 &vec);
std::ostream &operator<< (std::ostream &out, const glm::mat4 &mat);

void initRandom();

float getRandom();

float getRandom(float a, float b);

#endif
