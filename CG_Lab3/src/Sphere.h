//
// Created by max on 10.12.20.
//

#ifndef PROJECT_SPHERE_H
#define PROJECT_SPHERE_H

#include <vector>


class Sphere {
private:
    int iStacks;
    int iSlices;
    std::vector<float> mVertices;
    std::vector<unsigned int> mIndices;
public:
    Sphere(int iStacks, int iSlices);
    ~Sphere();
    inline const std::vector<float> getVertices() { return this->mVertices; };
    inline const std::vector<unsigned int> getIndices() { return this->mIndices; };

    inline void setPositions(std::vector<float> &Positions) { this->mVertices = Positions; };
    inline void setIndices(std::vector<unsigned int> &Indices) { this->mIndices = Indices; };

    void GenerateIndices();
};


#endif //PROJECT_SPHERE_H
