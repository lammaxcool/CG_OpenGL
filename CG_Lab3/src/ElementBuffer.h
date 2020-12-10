//
// Created by max on 01.11.20.
//

#ifndef PROJECT_ELEMENTBUFFER_H
#define PROJECT_ELEMENTBUFFER_H

#include <glad/glad.h>


class ElementBuffer {
private:
    unsigned int m_ID;
public:
    ElementBuffer(const void *data, unsigned int size);
    ~ElementBuffer();
    void Bind() const;
    void Unbind() const;
};


#endif //PROJECT_ELEMENTBUFFER_H
