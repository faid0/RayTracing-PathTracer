#ifndef RAYTRACING_PATHTRACER_HITTABLE_H
#define RAYTRACING_PATHTRACER_HITTABLE_H

#include "ray.h"

class hit_record{
public:
    point3 p;
    vector3 normal;
    double t;
};

class hittable {
public:
    ~hittable() = default;
    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;

};


#endif //RAYTRACING_PATHTRACER_HITTABLE_H
