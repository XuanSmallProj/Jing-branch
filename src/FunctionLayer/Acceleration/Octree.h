#pragma once
#include "Acceleration.h"
class Octree : public Acceleration {
public:
    Octree() = default;
    void build() override;
    bool rayIntersect(Ray &ray, int *geomID, int *primID, float *u,
                      float *v) const override;

protected:
    struct OctreeNode;
    static constexpr int ocLeafMaxSize = 24;
    OctreeNode *recursiveBuild(const AABB &aabb,
                               const std::vector<int> &primIdxBuffer);

    bool node_rayIntersect(const OctreeNode *node, Ray &ray, int *geomID,
                           int *primID, float *u, float *v) const;
    OctreeNode *root;
};
