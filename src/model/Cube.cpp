/******************************************************************************
 *
 * Cube.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Wed Sep  6 20:46:13 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "model/Cube.h"

Cube::Cube(Texture * texture) : _sprite(texture)
{
    Build();
}


Cube::~Cube()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Cube::Build()
{
    // create the buffer on the graphics card
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    // upload data to the card
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(_vertices), _vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indices), _indices, GL_STATIC_DRAW);

    // set position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*) (sizeof(GLfloat) * 3));
    glEnableVertexAttribArray(1);

    // unbind the vertex array object
    glBindVertexArray(0);
}

void Cube::Bind(ShaderProgram program)
{
    if (_sprite != nullptr)
    {
        _sprite->Bind();
        program.SetInteger("isSpriteNull", 0, true);
    }
    else
    {
        program.SetInteger("isSpriteNull", 1, true);
    }
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void Cube::Draw(ShaderProgram program)
{
    Bind(program);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, NULL);
}
