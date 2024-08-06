#ifndef SPHERE_H
#define SPHERE_H

#include <hittable.h>
#include <constants.h>

class sphere : public hittable {
    public:
        sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)){}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            float a = r.direction().length_squared();
            float h = dot(r.direction(), oc);
            float c = oc.length_squared() - radius*radius;

            float discriminant = h*h - a*c;
            if (discriminant < 0)
                return false;

            float sqrtd = std::sqrt(discriminant);

            float root = (h - sqrtd) / a;
            if(!ray_t.surronds(root)) {
                root = (h + sqrtd) / a;
                if (!ray_t.surronds(root))
                    return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }
    private:
        point3 center;
        double radius;
};

#endif // !SPHERE_H
