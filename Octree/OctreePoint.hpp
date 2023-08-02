#ifndef OctreePoint_H
#define OctreePoint_H

#include "KVector.hpp"

class OctreePoint
{
private:
    KVec3 pos;

public:
    OctreePoint() = default;
    OctreePoint(const KVec3 &initPos) : pos(initPos){};
    inline const KVec3 &getOctreePoint() const { return pos; };
    inline void setOctreePoint(const KVec3 &newPos) { pos = newPos; };
    friend std::ostream &operator<<(std::ostream &os, const OctreePoint &octreePoint)
    {
        return os << octreePoint.getOctreePoint() << std::endl;
    }
};

#endif