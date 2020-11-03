//
// Created by max on 01.11.20.
//

#include "VertexArray.h"
#include "ErrorChecker.h"

VertexArray::VertexArray() {
    GLCall( glGenVertexArrays(1, &m_ID) );
    Bind();
}

VertexArray::~VertexArray() {
    GLCall( glDeleteVertexArrays(1, &m_ID) );
}

void VertexArray::Bind() const
{
    GLCall( glBindVertexArray(m_ID) );
}

void VertexArray::Unbind() const
{
    GLCall( glBindVertexArray(0) );
};
