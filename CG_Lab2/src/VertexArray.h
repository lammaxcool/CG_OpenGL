//
// Created by max on 01.11.20.
//

#ifndef PROJECT_VERTEXARRAY_H
#define PROJECT_VERTEXARRAY_H


class VertexArray {
private:
    unsigned int m_ID;
public:
    VertexArray();
    ~VertexArray();
    void Bind() const;
    void Unbind() const;
};


#endif //PROJECT_VERTEXARRAY_H
