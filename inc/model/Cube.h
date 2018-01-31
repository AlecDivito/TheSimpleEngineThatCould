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
#include "framework/Buffer.h"
#include "framework/VertexArray.h"

class Cube
{
    public:
        Cube(std::shared_ptr<Texture> texture = nullptr);
        virtual ~Cube();

        void Build();
        void Bind(ShaderProgram);
        void Draw(ShaderProgram);
    protected:
    private:
        std::shared_ptr<Buffer> EBO;
        std::shared_ptr<Buffer> VBO;
        std::shared_ptr<VertexArray> VAO;
        std::shared_ptr<Texture> _sprite;

        const GLfloat _vertices[40] = 
        {
            // position        // Texture
            -0.5f, -0.5f, 0.5f, 1.0f, 1.0f,
             0.5f, -0.5f, 0.5f, 0.0f, 1.0f,
             0.5f,  0.5f, 0.5f, 0.0f, 0.0f,            
            -0.5f,  0.5f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, -1.0f, -1.0f,
             0.5f, -0.5f, -0.5f, 0.0f, -1.0f,
             0.5f,  0.5f, -0.5f, 0.0f, 0.0f,            
            -0.5f,  0.5f, -0.5f, -1.0f, 0.0f,
        };

        const GLint _indices[36] =
        {
            // front
            0, 1, 2, 2, 3, 0, 
            // top
            1, 5, 6, 6, 2, 1, 
            // back
            7, 6, 5, 5, 4, 7,
            // bottom
            4, 0, 3, 3, 7, 4, 
            // left
            4, 5, 1, 1, 0, 4, 
            // right
            3, 2, 6, 6, 7, 3
        };
};
