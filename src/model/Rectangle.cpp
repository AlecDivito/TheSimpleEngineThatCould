/******************************************************************************
 *
 * Rectangle.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Aug 18 22:43:21 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "model/Rectangle.h"

Rectangle::Rectangle() : Sprite(nullptr)
{
    Build();
}

Rectangle::Rectangle(Texture * texture)
{
    Sprite = texture;
    Build();
}

Rectangle::~Rectangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::Build()
{
    // create the buffer on the graphics card
    glGenBuffers(1, &EBO);
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    // upload data to the card
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // set position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*) (sizeof(GLfloat) * 3));
    glEnableVertexAttribArray(1);

    // unbind the vertex array object
    glBindVertexArray(0);
}

void Rectangle::Bind(ShaderProgram program)
{
    if (Sprite != nullptr)
    {
        Sprite->Bind();
        program.SetInteger("isSpriteNull", 0, true);
    }
    else
    {
        program.SetInteger("isSpriteNull", 1, true);
    }
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void Rectangle::Draw(ShaderProgram program)
{
    Bind(program);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
}
