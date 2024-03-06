//
// Created by faidr on 06.03.2024.
//

#include "vector3.h"
vector3::vector3() : e{0, 0, 0} {};

vector3::vector3(double e0, double e1, double e2) : e{e0, e1, e2} {};


double vector3::x() const { return e[0]; }

double vector3::y() const { return e[1]; }

double vector3::z() const { return e[2]; }

vector3 vector3::operator-() const{return {-e[0], -e[1], -e[2]};}
double vector3::operator[](int i)  const{return e[i];};
double& vector3::operator[](int i){return e[i];}

vector3& vector3::operator+=(const vector3 &v){
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}
vector3& vector3::operator*=(double t){
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vector3& vector3::operator/=(double t){
    return *this*= 1/t;
}
double vector3::length() const{
    return sqrt(length_squared());
}
double vector3::length_squared() const{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

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