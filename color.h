#ifndef COLOR_H
#define COLOR_H

#include <vec3.h>

#include <iostream>

using color = vec3;

const float FULL_BRIGHTNESS = 255.999;

void write_color(std::ostream& out, const color& pixel_color){
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    int rbyte = int(FULL_BRIGHTNESS * r);
    int gbyte = int(FULL_BRIGHTNESS * g);
    int bbyte = int(FULL_BRIGHTNESS * b);

    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}
#endif // !COLOR_H
