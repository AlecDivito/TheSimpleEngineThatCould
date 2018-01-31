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

Cube::Cube(std::shared_ptr<Texture> texture) : _sprite(texture)
{
    VBO = Buffer::allocateImmutableStorage(Target::Array, sizeof(_vertices), _vertices, Flags::MapRead, sizeof(_vertices)/sizeof(_vertices[0]), 5);
    EBO = Buffer::allocateImmutableStorage(Target::ElementArray, sizeof(_indices), _indices, Flags::MapRead, sizeof(_indices) / sizeof(_indices[0]), 1);
    std::vector<BufferHelper> helper;
    helper.push_back({3, 0}); // pos coords
    helper.push_back({2, 3}); // tex coords
    VAO = std::make_shared<VertexArray>(VBO, EBO, helper);
}

Cube::~Cube()
{

}

void Cube::Draw(ShaderProgram program)
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
    VAO->Draw();
}
