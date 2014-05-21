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

std::ostream &operator<< (std::ostream &out, const glm::mat4 &mat)
{
    out << "["
        << mat[0].x << "\t" << mat[0].y << "\t" << mat[0].z << "\t" << mat[0].w << std::endl
        << mat[1].x << "\t" << mat[1].y << "\t" << mat[1].z << "\t" << mat[1].w << std::endl
        << mat[2].x << "\t" << mat[2].y << "\t" << mat[2].z << "\t" << mat[2].w << std::endl
        << mat[3].x << "\t" << mat[3].y << "\t" << mat[3].z << "\t" << mat[3].w << std::endl
        << "]" << std::endl;

    return out;
}

void initRandom()
{
    srand(1337691373);
}

float getRandom()
{
    return rand();
}

float getRandom(float a, float b)
{
    return ((b-a) * rand()/RAND_MAX) + a;
}
