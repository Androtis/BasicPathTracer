#include <hittable.h>
#include <hittablelist.h>
#include <sphere.h>
#include <constants.h>

//Gets the rays color
color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if(world.hit(r, interval(0,infinity),rec)){
        return 0.5 * (rec.normal + color(1,1,1));
    } else {
        vec3 unit_direction = unit_vector(r.direction());
        float a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
    }
}


//File outputs a basic ppm file
int main() {
    //Camera Params
    float aspect_ratio = 16.0 / 9.0;
    float view_height = 2.0;
    float focal_len = static_cast<float>(1.0);
    point3 cam_center = point3(0,0,0);


    //Image Parameters

    const int img_width = 2000;
    int img_height = static_cast<int>(img_width / aspect_ratio);
    
    img_height = (img_height < 1) ? 1 : img_height;

    //World

    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,01), 100));

    //viewport width based off the img
    float view_width = view_height * (double(img_width)/img_height);
    
    //the horizontal and vertical viewport edges as vectors
    vec3 view_u = vec3(view_width, 0, 0);
    vec3 view_v = vec3(0, -view_height, 0);

    //Change in pixel over the viewport
    vec3 pixel_delta_u = view_u / img_width;
    vec3 pixel_delta_v = view_v / img_height;

    //calculating the top-left pixel
    vec3 view_up_left = cam_center - vec3(0,0,focal_len) - view_u/2 - view_v/2;
    point3 pixel00_loc = view_up_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    //Rendering & Outputing the image

    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";
    
    for (int j = 0; j < img_height; j++){
        std::clog << "\rScanlines remaining: " << (img_height - j) << ' ' << std::flush;
        for (int i = 0; i < img_width; i++){
            point3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            vec3 ray_dir = pixel_center - cam_center;

            ray r(cam_center, ray_dir);

            color color_pixel = ray_color(r, world);
            write_color(std::cout, color_pixel);
        }
    }

    std::clog << "\rDone.                  \n";

    return 0;
}
