//
// Created by max on 01.11.20.
//

#include "ElementBuffer.h"
#include "ErrorChecker.h"


ElementBuffer::ElementBuffer(const void *data, unsigned int size) {
    GLCall(glGenBuffers(1, &m_ID));
    Bind();
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

ElementBuffer::~ElementBuffer() {
    GLCall(glDeleteBuffers(1, &m_ID));
}

void ElementBuffer::Bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID));
}

void ElementBuffer::Unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}