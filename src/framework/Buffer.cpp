/******************************************************************************
 *
 * Buffer.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Sun Nov 26 10:50:16 EST 2017
 * {description}
 *
 *****************************************************************************/

#include "framework/Buffer.h"

Buffer::Buffer(Target target, GLuint dataSize, GLuint totalStride) : _target(target)
{
    _createBuffer();
    _dataSize = dataSize;
    _totalStride = totalStride;
}

Buffer::Buffer(Target target, Flags flags) : _target(target), _flags(flags)
{ 
    _createBuffer();
}

Buffer::~Buffer()
{
    glDeleteBuffers(1, &_id);
}

std::shared_ptr<Buffer> Buffer::allocateImmutableStorage(Target target, GLsizeiptr size, const void *data, Flags flag, GLuint dataSize, GLuint totalStride)
{
    auto buffer = std::make_shared<Buffer>(target, dataSize, totalStride);
    buffer->bindBuffer();
    glBufferStorage(buffer->_target, size, data, flag);
    return buffer;
}

std::shared_ptr<Buffer> Buffer::allocateBuffer(Target target, GLsizeiptr size, const GLvoid *data, Usage usage, GLuint dataSize, GLuint totalStride)
{
    auto buffer = std::make_shared<Buffer>(target, dataSize, totalStride);
    buffer->bindBuffer();
    glBufferData(buffer->_target, size, data, usage);
    return nullptr;
}

std::shared_ptr<Buffer> Buffer::allocateMapRangeBuffer(Target target, GLintptr size, GLsizeiptr length, Flags flags, GLuint dataSize, GLuint totalStride)
{
    auto buffer = std::make_shared<Buffer>(target, dataSize, totalStride);
    buffer->bindBuffer();
    glMapBufferRange(buffer->_target, size, length, flags);
    return nullptr;
}

void Buffer::allocateBufferSubData(Target target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
{
    bindBuffer();
    glBufferSubData(target, offset, size, data);
}

void Buffer::getBufferSubData(Target target, GLintptr offset, GLsizeiptr size, GLvoid *data)
{
    glGetBufferSubData(target, offset, size, data);
}

void Buffer::getBufferParameter(Target target, Parameter parameter, GLint *data)
{
    glGetBufferParameteriv(target, parameter, data);
}

GLuint Buffer::getId() const
{
    return _id;
}

GLuint Buffer::getDataSize() const
{
    return _dataSize;
}

GLuint Buffer::getTotalStride() const
{
    return _totalStride;
}

void Buffer::_createBuffer()
{
    glCreateBuffers(1, &_id);
}

void Buffer::bindBuffer()
{
    glBindBuffer(_target, _id);
}