#ifndef Octree_H
#define Octree_H

#include "OctreePoint.hpp"
#include "KVector.hpp"
#include <iostream>
#include <vector>

namespace KOctree
{
    using UINT = unsigned int;

    class Octree
    {
        KVec3 origin, halfDepth;
        Octree *childTrees[8] = {nullptr};
        OctreePoint *data = nullptr;

    public:
        Octree() = delete;
        Octree(const KVec3 &org, const KVec3 &depth) : origin(org), halfDepth(depth){};
        // Octree(const Octree &copyTree) : origin(copyTree.origin), depth(copyTree.depth), data(copyTree.data){};
        Octree(const Octree &copyTree) = delete;

    protected:
        inline bool isLeafNode() const { return childTrees[0] == nullptr; };
        UINT getPointInChildBoxIndex(const OctreePoint &point)
        {
            UINT index = 0;
            auto pos = point.getOctreePoint();
            if (pos.x >= origin.x)
                index |= 4;
            if (pos.y >= origin.y)
                index |= 2;
            if (pos.z >= origin.z)
                index |= 1;
            return index;
        };

    public:
        void insert(OctreePoint *point)
        {
            if (isLeafNode())
            {
                if (data == nullptr)
                {
                    data = point;
                    return;
                }

                auto oldData = data;
                data = nullptr;
                for (auto index = 0; index < 8; index++)
                {
                    KVec3 newOrg = origin;
                    newOrg.x += index & 4 ? halfDepth.x * .5f : halfDepth.x * -.5f;
                    newOrg.y += index & 2 ? halfDepth.y * .5f : halfDepth.y * -.5f;
                    newOrg.z += index & 1 ? halfDepth.z * .5f : halfDepth.z * -.5f;
                    childTrees[index] = new Octree(newOrg, halfDepth * .5f);
                }
                childTrees[getPointInChildBoxIndex(*oldData)]->insert(oldData);
                childTrees[getPointInChildBoxIndex(*point)]->insert(point);

                return;
            }

            childTrees[getPointInChildBoxIndex(*point)]->insert(point);
        };

        void getPointsInsideBox(const KVec3 &rangeMin, const KVec3 &rangeMax, std::vector<OctreePoint> results){};
    };
}
#endif