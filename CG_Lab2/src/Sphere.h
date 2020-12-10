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
    std::vector<float> mPositions;
    std::vector<float> mIndices;
    std::vector<float> mNormals;
    std::vector<float> mTexCoord;
public:
    Sphere(int iStacks, int iSlices);
    ~Sphere();
    inline const std::vector<float> getPositions() { return this->mPositions; };
    inline const std::vector<float> getIndices() { return this->mIndices; };
    inline const std::vector<float> getNormals() { return this->mNormals; };
    inline const std::vector<float> getTexCoord() { return this->mTexCoord; };

    inline void setPositions(std::vector<float> &Positions) { this->mPositions = Positions; };
    inline void setIndices(std::vector<float> &Indices) { this->mIndices = Indices; };
    inline void setNormals(std::vector<float> &Normals) { this->mNormals = Normals; };
    inline void setTexCoord(std::vector<float> &TexCoord) { this->mTexCoord = TexCoord; };

    void GenerateIndices();
};


#endif //PROJECT_SPHERE_H
