#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "Octree.hpp"

using namespace KOctree;

// Used for testing
std::vector<KVec3> points;
Octree *octree;
OctreePoint *octreePoints;
KVec3 qmin, qmax;

float rand11() // Random number between [-1,1]
{
	return -1.f + (2.f * rand()) * (1.f / RAND_MAX);
}

KVec3 randVec3() // Random vector with components in the range [-1,1]
{
	return KVec3(rand11(), rand11(), rand11());
}

void init()
{
	// Create a new Octree centered at the origin
	// with physical dimension 2x2x2
	octree = new Octree(KVec3(0, 0, 0), KVec3(1, 1, 1));

	// Create a bunch of random points
	const int nPoints = 1 * 1000 * 1000;
	for (int i = 0; i < nPoints; ++i)
	{
		points.push_back(randVec3());
	}
	printf("Created %ld points\n", points.size());
	fflush(stdout);

	// Insert the points into the octree
	octreePoints = new OctreePoint[nPoints];
	for (int i = 0; i < nPoints; ++i)
	{
		octreePoints[i].setOctreePoint(points[i]);
		octree->insert(octreePoints + i);
		// std::cout << octreePoints[i] << std::endl;
	}
	printf("Inserted points to octree\n");
	fflush(stdout);

	// Create a very small query box. The smaller this box is
	// the less work the octree will need to do. This may seem
	// like it is exagerating the benefits, but often, we only
	// need to know very nearby objects.
	qmin = KVec3(-.5, -.5, -.5);
	qmax = KVec3(.5, .5, .5);

	// Remember: In the case where the query is relatively close
	// to the size of the whole octree space, the octree will
	// actually be a good bit slower than brute forcing every point!
}

// Query using Octree
void testOctree()
{
	std::vector<OctreePoint *> results;
	octree->getPointsInsideBox(qmin, qmax, results);
	printf("testOctree found %ld points.\n", results.size());
}

int main(int argc, char **argv)
{
	init();
	testOctree();

	return 0;
}