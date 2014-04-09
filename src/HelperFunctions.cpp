#include "HelperFunctions.h"
#include <iostream>

std::ostream &operator<< (std::ostream &out, const glm::vec3 &vec) {
    out << "{"
        << vec.x << " " << vec.y << " "<< vec.z
        << "}";

    return out;
}
