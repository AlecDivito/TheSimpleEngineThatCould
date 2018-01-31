#pragma once

/******************************************************************************
 *
 * Buffer.h
 * Alec Divito
 * divito.alec@gmail.com
 * Sun Nov 26 10:50:16 EST 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>
#include <memory>

enum Target : GLenum
{
    Array = GL_ARRAY_BUFFER,
    ElementArray = GL_ELEMENT_ARRAY_BUFFER,
    AtomicCounter = GL_ATOMIC_COUNTER_BUFFER,
    TransformFeedback = GL_TRANSFORM_FEEDBACK_BUFFER,
    UniformBuffer = GL_UNIFORM_BUFFER,
    ShaderStorage = GL_SHADER_STORAGE_BUFFER,
    CopyRead = GL_COPY_READ_BUFFER,
    CopyWrite = GL_COPY_WRITE_BUFFER,
    DrawIndirect = GL_DRAW_INDIRECT_BUFFER,
    DispatchIndirect = GL_DISPATCH_INDIRECT_BUFFER,
    PixelPack = GL_PIXEL_PACK_BUFFER,
    PixelUnpack = GL_PIXEL_UNPACK_BUFFER,
    Query = GL_QUERY_BUFFER,
    TextureBuffer = GL_TEXTURE_BUFFER,
};

enum Flags : GLenum
{
    DynamicStorage = GL_DYNAMIC_STORAGE_BIT,
      // Buffer contents can be updated directly
    MapRead = GL_MAP_READ_BIT,
      // Buffer data store will be mapped for reading
    MapWrite = GL_MAP_WRITE_BIT,
      // Buffer data store will be mapped for writing
    MapPersistent = GL_MAP_PERSISTENT_BIT,
      // Buffer dtat store can be mapped persistently
    MapCoherent = GL_MAP_COHERENT_BIT,
      // If all other conditions can be met
    ClientStorage = GL_CLIENT_STORAGE_BIT
      // if all other condition can be met, prefer storage 
      // local to client (CPU) then server (GPU)
};


enum Parameter : GLenum
{
    Access = GL_BUFFER_ACCESS,
    Mapped = GL_BUFFER_MAPPED,
    Size = GL_BUFFER_SIZE,
    PramUsage = GL_BUFFER_USAGE,
};

enum Usage : GLenum
{
    StreamDraw = GL_STREAM_DRAW,
    StreamRead = GL_STREAM_READ,
    StreamCopy = GL_STREAM_COPY,
    StaticDraw = GL_STATIC_DRAW,
    StaticRead = GL_STATIC_READ,
    StaticCopy = GL_STATIC_COPY,
    DynamicDraw = GL_DYNAMIC_DRAW,
    DynamicRead = GL_DYNAMIC_READ,
    DynamicCopy = GL_DYNAMIC_COPY
};

struct BufferHelper 
{
    GLuint bufferSize;
    GLuint offset;
};

class Buffer
{
    public:
        Buffer(Target target, GLuint dataSize, GLuint totalStride);
        Buffer(Target target, Flags flags);

        virtual ~Buffer();

        static std::shared_ptr<Buffer> allocateImmutableStorage(Target, GLsizeiptr size, const void *data, Flags flag, GLuint dataSize, GLuint totalStride);
        // Function to create buffer that is immutably

        static std::shared_ptr<Buffer> allocateBuffer(Target, GLsizeiptr, const GLvoid *, Usage, GLuint dataSize, GLuint totalStride);
        // Function to create buffer, can call multiple times, will orphan old memory and allocate new storage

        static std::shared_ptr<Buffer> allocateMapRangeBuffer(Target target, GLintptr size, GLsizeiptr length, Flags flags, GLuint dataSize, GLuint totalStride);
        // Function to create empty buffer

        // if this one is called data should have been created with allocatebuffer
        void allocateBufferSubData(Target, GLintptr, GLsizeiptr, const GLvoid *);

        void getBufferSubData(Target, GLintptr, GLsizeiptr, GLvoid * );
        void getBufferParameter(Target, Parameter, GLint *);
    
        void bindBuffer();

        GLuint getId() const;

        GLuint getDataSize() const;
    
        GLuint getTotalStride() const;
    protected:
    private:
        void _createBuffer();

        GLuint _dataSize;
        GLuint _totalStride;

        GLuint _id;
        Target _target;
        Flags _flags;
};
