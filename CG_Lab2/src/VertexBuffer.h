//
// Created by max on 01.11.20.
//

#ifndef PROJECT_VERTEXBUFFER_H
#define PROJECT_VERTEXBUFFER_H


class VertexBuffer {
private:
    unsigned int m_ID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();
    void Bind() const;
    void Unbind() const;
};


#endif //PROJECT_VERTEXBUFFER_H
