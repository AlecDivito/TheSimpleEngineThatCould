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

Rectangle::Rectangle(std::shared_ptr<Texture> texture)
{
    Sprite = texture;
    Build();
}

Rectangle::~Rectangle()
{

}

void Rectangle::Build()
{
    VBOObj = Buffer::allocateImmutableStorage(Target::Array, sizeof(vertices), vertices, Flags::MapRead, sizeof(vertices) / sizeof(vertices[0]), 5);
    EBOObj = Buffer::allocateImmutableStorage(Target::ElementArray, sizeof(indices), indices, Flags::MapRead, sizeof(indices) / sizeof(indices[0]), 1);
    std::vector<BufferHelper> helper;
    helper.push_back({3, 0}); // pos coords
    helper.push_back({2, 3}); // tex coords
    VAOObj = std::make_shared<VertexArray>(VBOObj, EBOObj, helper);
}

void Rectangle::Draw(ShaderProgram program)
{
    // Bind(program);
    if (Sprite != nullptr)
    {
        Sprite->Bind();
        program.SetInteger("isSpriteNull", 0, true);
    }
    else
    {
        program.SetInteger("isSpriteNull", 1, true);
    }

    VAOObj->Draw(EBOObj);
}
