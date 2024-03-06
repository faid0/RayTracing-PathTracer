//
// Created by faidr on 06.03.2024.
//

#pragma once

#include <cmath>
#include <iostream>
using std::sqrt;

class vector3 {
public:
    double e[3];
    vector3();
    vector3(double e0, double e1, double e2);

    double x() const;
    double y() const;
    double z() const;
    vector3 operator-() const;
    double operator[](int i)  const;
    double& operator[](int i);
    vector3& operator+=(const vector3 &v);
    vector3& operator*=(double t);
    vector3& operator/=(double t);
    double length() const;
    double length_squared() const;
};