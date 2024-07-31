#include <iostream>

//File outputs a basic ppm file

int main() {
    //Image Parameters

    int img_width = 1000;
    int img_height = 1000;

    const float FULLBRIGHTNESS = 255.999;

    //Rendering & Outputing the image

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n1000\n";
    
    for (int j = 0; j < img_height; j++){
        for (int i = 0; i < img_width; i++){
            auto r = double(i) / (img_width-1);
            auto g = double(j) / (img_height-1);
            auto b = 0.0;

            int ir = int(FULLBRIGHTNESS * r);
            int ig = int(FULLBRIGHTNESS * g);
            int ib = int(FULLBRIGHTNESS * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    return 0;
}
