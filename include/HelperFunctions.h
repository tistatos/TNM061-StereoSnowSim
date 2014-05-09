#ifndef __HELPERFUNCTIONS_H__
#define __HELPERFUNCTIONS_H__

#include "sgct.h"
#include <iostream>
#include "glm/gtx/vector_angle.hpp"

std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec);
std::ostream &operator<< (std::ostream &out, const glm::vec2 &vec);
std::ostream &operator<< (std::ostream &out, const glm::mat4 &mat);

void initRandom();
float getRandom();
float getRandom(float a, float b);

void drawArrow(float length);
void drawArrow(const glm::vec3& start, const glm::vec3& stop);
void drawLines(glm::vec3 &start, glm::vec3 &stop);

#endif
