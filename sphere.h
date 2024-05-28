#ifndef RAYTRACING_PATHTRACER_SPHERE_H
#define RAYTRACING_PATHTRACER_SPHERE_H

#include "vector3.h"
#include "hittable.h"

class sphere : public hittable{
public:
    sphere(const point3& center, double radius);
    bool hit(const ray &r, double ray_tmin, double ray_tmax, hit_record &rec) const override;
private:
    point3 center;
    double radius;
};


#endif //RAYTRACING_PATHTRACER_SPHERE_H
