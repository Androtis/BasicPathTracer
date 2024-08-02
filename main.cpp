#include <iostream>

#include <vec3.h>
#include <color.h>

//File outputs a basic ppm file

int main() {
    //Image Parameters

    int img_width = 1000;
    int img_height = 1000;

    const float FULLBRIGHTNESS = 255.999;

    //Rendering & Outputing the image

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n1000\n";
    
    for (int j = 0; j < img_height; j++){
        std::clog << "\rScanlines remaining: " << (img_height - j) << ' ' << std::flush;
        for (int i = 0; i < img_width; i++){
            auto pixel_color = color(double(i)/(img_width-1), double(j)/(img_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                  \n";

    return 0;
}
