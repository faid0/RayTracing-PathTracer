//
// Created by faidr on 06.03.2024.
//

#pragma once

#include <cmath>
#include <iostream>
using std::sqrt;

//a vector class containing 3 elements, used as points and colors
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

using point3 = vector3;

inline std::ostream& operator<<(std::ostream &out, const vector3 &v){
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vector3 operator+(const vector3 &u, const vector3 &v){
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}

inline vector3 operator-(const vector3 &u, const vector3 &v){
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}

inline vector3 operator*(const vector3 &u, const vector3 &v) {
    return { u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2] };
}

inline vector3 operator*(double t, const vector3 &v) {
    return {t * v.e[0], t * v.e[1], t * v.e[2]};
}

inline vector3 operator*(const vector3 &v, double t) {
    return t * v;
}

inline vector3 operator/(vector3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vector3 &u, const vector3 &v) {
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
}

inline vector3 cross(const vector3 &u, const vector3 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}

inline vector3 unit_vector(vector3 v) {
    return v / v.length();
}