#include <iostream>

#include <vec3.h>
#include <ray.h>
#include <color.h>

//File outputs a basic ppm file

double hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant)) / (2.0*a);
    }
}

//Gets the rays color
color ray_color(const ray& r, double offset) {
    auto t = hit_sphere(point3(0,0,-offset), 0.5, r);
    if (t > 0.0) {
        vec3 N = unit_vector(r.at(t) - vec3(0,0,-offset));
        return 0.5*color(N.x()+offset, N.y()+offset, N.z()+offset);
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}

int main() {
    //Camera Params
    auto aspect_ratio = 16.0 / 9.0;
    auto view_height = 2.0;
    auto focal_len = 1.0;
    auto cam_center = point3(0,0,0);


    //Image Parameters

    int img_width = 1000;
    int img_height = int(img_width / aspect_ratio);
    
    img_height = (img_height < 1) ? 1 : img_height;

    //viewport width based off the img
    auto view_width = view_height * (double(img_width)/img_height);
    
    //the horizontal and vertical viewport edges as vectors
    auto view_u = vec3(view_width, 0, 0);
    auto view_v = vec3(0, -view_height, 0);

    //Change in pixel over the viewport
    auto pixel_delta_u = view_u / img_width;
    auto pixel_delta_v = view_v / img_height;

    //calculating the top-left pixel
    auto view_up_left = cam_center - vec3(0,0,focal_len) - view_u/2 - view_v/2;
    auto pixel00_loc = view_up_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    //Rendering & Outputing the image

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";
    
    for (int j = 0; j < img_height; j++){
        std::clog << "\rScanlines remaining: " << (img_height - j) << ' ' << std::flush;
        for (int i = 0; i < img_width; i++){
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            auto ray_dir = pixel_center - cam_center;

            ray r(cam_center, ray_dir);

            color color_pixel = ray_color(r,1);
            write_color(std::cout, color_pixel);
        }
    }

    std::clog << "\rDone.                  \n";

    return 0;
}
