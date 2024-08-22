#ifndef CAMERA_H
#define CAMERA_H

#include "constants.h"

#include "hittable.h"

class camera {
    public:
    float aspect_ratio = 16.0 / 9.0;
    int img_width = 2000;

    void render (const hittable& world) {
        initialize();

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
    }

    private:
    int    img_height;   
    point3 cam_center;         
    point3 pixel00_loc;    
    vec3   pixel_delta_u;  
    vec3   pixel_delta_v;  

    void initialize() {
        img_height = static_cast<int>(img_width / aspect_ratio);
        img_height = (img_height < 1) ? 1 : img_height;

        cam_center = point3(0,0,0);

        float focal_len = static_cast<float>(1.0);
        float view_height = 2.0;
        float view_width = view_height * (double(img_width)/img_height);

        vec3 view_u = vec3(view_width, 0, 0);
        vec3 view_v = vec3(0, -view_height, 0);

        pixel_delta_u = view_u / img_width;
        pixel_delta_v = view_v / img_height;

        vec3 view_up_left = cam_center - vec3(0,0,focal_len) - view_u/2 - view_v/2;

        pixel00_loc = view_up_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    color ray_color(const ray& r, const hittable& world) const {
        hit_record rec;
        if(world.hit(r, interval(0,infinity),rec)){
            return 0.5 * (rec.normal + color(1,1,1));
        } else {
            vec3 unit_direction = unit_vector(r.direction());
            float a = 0.5*(unit_direction.y() + 1.0);
            return (1.0-a)*color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
        }
    } 
}

#endif
;
