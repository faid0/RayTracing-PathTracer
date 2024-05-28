#include "sphere.h"

sphere::sphere(const point3 &center, double radius) : center{center}, radius{fmax(0,radius)} {
}

bool sphere::hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const {
    vector3 oc = center - r.origin();
    auto a = r.direction().length_squared();
    auto h = dot(r.direction(), oc);
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = h*h - a*c;
    if (discriminant < 0) {
        return false;
    }

    auto squared_discriminant = sqrt(discriminant);
    auto root = (h - squared_discriminant) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
        root = (h + squared_discriminant) / a;
        if (root <= ray_tmin || ray_tmax <= root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;

    return true;

}
