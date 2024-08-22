#include <hittable.h>
#include <hittablelist.h>
#include <sphere.h>
#include <camera.h>
#include <constants.h>



//File outputs a basic ppm file
int main() {
    hittable_list world;

    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,01), 100));

    camera cam;

    cam.aspect_ratio = 16.0/9.0;
    cam.img_width = 2000;

    cam.render(world);

    return 0;
}
