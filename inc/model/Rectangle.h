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

class Rectangle
{
    public:
       // variables
       GLuint VBO;
       GLuint VAO;

       Rectangle();
       virtual ~Rectangle();

       void Bind();
       void Draw();
    protected:
    private:
        const float vertices[6] = {
	         0.0f,  0.5f,
	         0.5f, -0.5f,
	        -0.5f, -0.5f
        };
};
