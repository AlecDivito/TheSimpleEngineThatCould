#pragma once

/******************************************************************************
 *
 * VertexArray.h
 * Alec Divito
 * divito.alec@gmail.com
 * Sun Nov 26 13:21:01 EST 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>
#include <memory>
#include <vector>
#include <framework/Buffer.h>

class VertexArray
{
    public:
        VertexArray(std::shared_ptr<Buffer> buffer, std::shared_ptr<Buffer> indices, std::vector<BufferHelper> bufferHelper);

        virtual ~VertexArray();

        void Draw(std::shared_ptr<Buffer> i);

        GLuint id() { return _id;}

      protected:
      private:

        std::shared_ptr<Buffer> _buffer;
        std::shared_ptr<Buffer> _indices;

        GLuint _bindingIndex;
        GLuint _id;
        GLuint _location;
};
