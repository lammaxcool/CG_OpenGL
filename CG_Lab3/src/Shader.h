//
// Created by max on 10.12.20.
//

#ifndef PROJECT_SHADER_H
#define PROJECT_SHADER_H

#include <string>
#include "ErrorChecker.h"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader {
private:
    unsigned int mID;
    struct ShaderProgramSource source;
public:
    Shader(const std::string &path);
    ~Shader();
    inline const void Use() { GLCall( glUseProgram(this->mID); ); }
    inline const void NotUse() { GLCall( glUseProgram(0); ); }
    inline const unsigned int getID() { return this->mID; }

    void setMat4f(const std::string &name, float *data);
    void setVec3f(const std::string &name, float *data);
};


#endif //PROJECT_SHADER_H
