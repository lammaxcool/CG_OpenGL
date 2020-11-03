//
// Created by max on 01.11.20.
//

#ifndef PROJECT_INDEXBUFFER_H
#define PROJECT_INDEXBUFFER_H

#include <glad/glad.h>


class IndexBuffer {
private:
    unsigned int m_ID;
    unsigned int m_count;
public:
    IndexBuffer(unsigned int *data, unsigned int size);
    ~IndexBuffer();
    void Bind() const;
    void Unbind() const;
};


#endif //PROJECT_INDEXBUFFER_H
