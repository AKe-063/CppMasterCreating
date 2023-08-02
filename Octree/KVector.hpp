#ifndef KVector_H
#define KVector_H

#include <iostream>
#include <iomanip>

struct KVec3;

struct KVec3
{
    union
    {
        struct
        {
            float x, y, z;
        };
        float r[3];
    };

    KVec3(){};
    KVec3(float x, float y, float z) : x(x), y(y), z(z){};

    float &operator[](unsigned int index) { return r[index]; };
    const float &operator[](unsigned int index) const { return r[index]; };
    KVec3 operator*(float factor) { return KVec3(x * factor, y * factor, z * factor); };
    KVec3 operator+(const KVec3 &addend) { return KVec3(x + addend.x, y + addend.y, z + addend.z); };
    KVec3 operator-(const KVec3 &sunend) { return KVec3(x - sunend.x, y - sunend.y, z - sunend.z); };
    friend std::ostream &operator<<(std::ostream &os, const KVec3 &vec3)
    {
        return os << std::setprecision(6) << vec3.x << "\t" << vec3.y << "\t" << vec3.z;
    }
};

#endif