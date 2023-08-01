#ifndef KVector_H
#define KVector_H

#include <iostream>

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
    KVec3 operator*(float factor) { return KVec3(x * factor, y * factor, z * factor); }
};

#endif