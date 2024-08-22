#ifndef COLOR_H
#define COLOR_H

#include <vec3.h>
#include <interval.h>
#include <iostream>

using color = vec3;

const float FULL_BRIGHTNESS = 255;

void write_color(std::ostream& out, const color& pixel_color){
    float r = pixel_color.x();
    float g = pixel_color.y();
    float b = pixel_color.z();

    static const interval intensity(0.000, 0.999);
    int rbyte = int(FULL_BRIGHTNESS * r);
    int gbyte = int(FULL_BRIGHTNESS * g);
    int bbyte = int(FULL_BRIGHTNESS * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif // !COLOR_H
