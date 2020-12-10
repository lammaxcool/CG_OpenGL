//
// Created by max on 10.12.20.
//

#include "Sphere.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define PI 3.14159265359f

Sphere::Sphere(int iStacks, int iSlices) {
    this->iStacks = iStacks;
    this->iSlices = iSlices;

    float radius = 1.0f;
    float x, y, z, xy;                              // vertex position
    float nx, ny, nz, lengthInv = 1.0f / radius;    // vertex normal
    float s, t;                                     // vertex texCoord

    float sectorStep = 2 * PI / float(iSlices);
    float stackStep = PI / float(iStacks);
    float sectorAngle, stackAngle;

    for(int i = 0; i <= iStacks; ++i)
    {
        stackAngle = PI / 2 - float(i) * stackStep;        // starting from pi/2 to -pi/2
        xy = radius * cosf(stackAngle);             // r * cos(u)
        z = radius * sinf(stackAngle);              // r * sin(u)

        // add (iSlices+1) vertices per stack
        // the first and last vertices have same position and normal, but different tex coords
        for(int j = 0; j <= iSlices; ++j)
        {
            sectorAngle = float(j) * sectorStep;           // starting from 0 to 2pi

            // vertex position (x, y, z)
            x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
            y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
            this->mPositions.push_back(x);
            this->mPositions.push_back(y);
            this->mPositions.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            nx = x * lengthInv;
            ny = y * lengthInv;
            nz = z * lengthInv;
            this->mNormals.push_back(nx);
            this->mNormals.push_back(ny);
            this->mNormals.push_back(nz);

            // vertex tex coord (s, t) range between [0, 1]
            s = (float)j / float(iSlices);
            t = (float)i / float(iStacks);
            this->mTexCoord.push_back(s);
            this->mTexCoord.push_back(t);
        }
    }
}

void Sphere::GenerateIndices() {
    int k1, k2;
    for(int i = 0; i < this->iStacks; ++i)
    {
        k1 = i * (this->iSlices + 1);     // beginning of current stack
        k2 = k1 + this->iSlices + 1;      // beginning of next stack

        for(int j = 0; j < this->iSlices; ++j, ++k1, ++k2)
        {
            // 2 triangles per sector excluding first and last stacks
            // k1 => k2 => k1+1
            if(i != 0)
            {
                this->mIndices.push_back(k1);
                this->mIndices.push_back(k2);
                this->mIndices.push_back(k1 + 1);
            }

            // k1+1 => k2 => k2+1
            if(i != (this->iStacks-1))
            {
                this->mIndices.push_back(k1 + 1);
                this->mIndices.push_back(k2);
                this->mIndices.push_back(k2 + 1);
            }
        }
    }
}
