//
// Created by max on 01.11.20.
//

#include "IndexBuffer.h"
#include "ErrorChecker.h"


IndexBuffer::IndexBuffer(unsigned int *data, unsigned int count): m_count(count) {
    GLCall(glGenBuffers(1, &m_ID));
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1, &m_ID));
}

void IndexBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
}

void IndexBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}