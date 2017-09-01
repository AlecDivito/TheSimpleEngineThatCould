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
#include "util/Texture.h"
#include "util/ShaderProgram.h"

class Rectangle
{
    public:
       // variables
       GLuint EBO;
       GLuint VBO;
       GLuint VAO;

       Rectangle();
       Rectangle(Texture*);
       virtual ~Rectangle();

       void Build();
       void Bind(ShaderProgram);
       void Draw(ShaderProgram);
    protected:
    private:
       Texture * Sprite;

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
