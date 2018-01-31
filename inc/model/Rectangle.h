#pragma once

/******************************************************************************
 *
 * Rectangle.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Aug 18 22:43:21 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>
#include <memory>

#include "framework/Buffer.h"
#include "framework/VertexArray.h"
#include "util/Texture.h"
#include "util/ShaderProgram.h"

class Rectangle
{
    public:
        // variables
        std::shared_ptr<Buffer> EBOObj;
        std::shared_ptr<Buffer> VBOObj;
        std::shared_ptr<VertexArray> VAOObj;

        Rectangle();
        Rectangle(std::shared_ptr<Texture> texture);
        virtual ~Rectangle();

        void Build();
        void Draw(ShaderProgram);
    protected:
    private:
        std::shared_ptr<Texture> Sprite;

        const GLfloat vertices[20] = {
            // position         // texture
             0.5f,  0.5f, 1.0f, 0.0f, 0.0f,
	        -0.5f,  0.5f, 1.0f, 1.0f, 0.0f,
	         0.5f, -0.5f, 1.0f, 0.0f, 1.0f,
	        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f
        };

        const GLint indices[6] = {
          0,1,2,1,2,3
        };
};
