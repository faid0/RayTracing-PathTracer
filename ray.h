//
// Created by faidr on 06.03.2024.
//

#pragma once

#include "vector3.h"
class ray {
public:
    ray(){};
    ray(const point3& origin, const vector3& direction): orig(origin), dir(direction){};
    point3 origin() const;
    vector3 direction() const;
    vector3 at(double t) const;
private:
    point3 orig;
    vector3 dir;
};
