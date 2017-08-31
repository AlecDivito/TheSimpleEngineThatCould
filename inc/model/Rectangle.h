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
    protected:
    private:
       float vertices[] = {
	        0.0f,  0.5f, // Vertex 1 (X, Y)
	        0.5f, -0.5f,
	       -0.5f, -0.5f
       };
};
