/******************************************************************************
 *
 * VertexArray.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Sun Nov 26 13:21:01 EST 2017
 * {description}
 *
 *****************************************************************************/
#include <iostream>
#include "framework/VertexArray.h"

VertexArray::VertexArray(std::shared_ptr<Buffer> buffer, std::shared_ptr<Buffer> indices, std::vector<BufferHelper> bufferValues)
    : _buffer(buffer), _indices(indices)
{
    _location = 0;
    _bindingIndex = 0;
    glGenVertexArrays(1, &_id);
    glBindVertexArray(_id);
    for (unsigned int i = 0; i < bufferValues.size(); i++)
    {
        glVertexArrayAttribFormat(_id, _location, bufferValues[i].bufferSize, GL_FLOAT, GL_FALSE, (sizeof(GLfloat)) * bufferValues[i].offset);
        glVertexArrayAttribBinding(_id, _location, _bindingIndex);
        glEnableVertexArrayAttrib(_id, _location);
        _location++;
    }
    glVertexArrayElementBuffer(_id, indices->getId());
    glVertexArrayVertexBuffer(_id, _bindingIndex, buffer->getId(), 0, sizeof(GLfloat) * buffer->getTotalStride());
    glBindVertexArray(0);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &_id);
}

void VertexArray::Draw()
{
    glBindVertexArray(_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indices->getId());
    glDrawElements(GL_TRIANGLES, _buffer->getDataSize(), GL_UNSIGNED_INT, NULL);
}