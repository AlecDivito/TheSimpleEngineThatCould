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

Rectangle::Rectangle()
{
    // create the buffer on the graphics card
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	// upload data to the card
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// set position attribute
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // unbind the vertex array object
    glBindVertexArray(0);
}


Rectangle::~Rectangle()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Rectangle::Bind()
{
	glBindVertexArray(VAO);
}

void Rectangle::Draw()
{
    Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
