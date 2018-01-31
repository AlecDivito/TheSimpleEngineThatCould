#pragma once

/******************************************************************************
 *
 * Cube.h
 * Alec Divito
 * divito.alec@gmail.com
 * Wed Sep  6 20:46:13 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>
#include <memory>
#include "util/Texture.h"
#include "util/ShaderProgram.h"

class Cube
{
    public:
        // variables
        GLuint EBO;
        GLuint VBO;
        GLuint VAO;

        Cube(std::shared_ptr<Texture> texture = nullptr);
        virtual ~Cube();

        void Build();
        void Bind(ShaderProgram);
        void Draw(ShaderProgram);
    protected:
    private:
        std::shared_ptr<Texture> _sprite;

        const GLfloat _vertices[40] = 
        {
            // position        // Texture
             0.5f,  0.5f, 0.5f, 0.0f, 0.0f,            
            -0.5f,  0.5f, 0.5f, 1.0f, 0.0f,
             0.5f, -0.5f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 1.0f, 1.0f,

             0.5f,  0.5f, -0.5f, 0.0f, 0.0f,            
            -0.5f,  0.5f, -0.5f, -1.0f, 0.0f,
             0.5f, -0.5f, -0.5f, 0.0f, -1.0f,
            -0.5f, -0.5f, -0.5f, -1.0f, -1.0f,
        };

        const GLint _indices[36] = 
        {
            // rect front
            0,1,2, 1,2,3,
            // right side
            0,2,4, 2,4,6,
            // left side
            3,2,7, 2,7,1,
            // top
            0,1,4, 1,4,5,
            // bottom
            2,3,6, 3,6,7,
            // back
            4,5,6, 5,6,7
        };
};
