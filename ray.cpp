//
// Created by faidr on 06.03.2024.
//

#include "ray.h"

point3 ray::origin() const{return orig;}
vector3 ray::direction() const{return dir;}
vector3 ray::at(double t) const{return orig + t*dir;}