#include "HelperFunctions.h"
#include <iostream>
#include <time.h>


std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec) {
    out << "{"
        << vec.x << " " << vec.y << " "<< vec.z
        << "}";

    return out;
}

std::ostream &operator<< (std::ostream &out, const glm::vec2 &vec) {
    out << "{"
        << vec.x << " " << vec.y
        << "}";

    return out;
}

void initRandom()
{
	srand (time(NULL));
}

float getRandom()
{
	return rand();
}


float getRandom(float a, float b)
{
	return ((b-a) * rand()/RAND_MAX) + a;
}
