#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>



//C++ std Usings

using std::make_shared;
using std::shared_ptr;

//Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//Utility Functions

inline double degrees_to_rads(double degrees){
    return degrees * pi / 180.0;
}

//Common Headers
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"

#endif // !CONSTANTS_H
