/******************************************************************************
 *
 * Texture.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 18:43:05 EDT 2017
 * Wrapping:
 *    GL_REPEAT: coordinates will be ignored, repeating pattern is formed.
 *    GL_MIRRORED_REPEAT: Same as GL_REPEAT, just images are mirrored
 *    GL_CLAMP_TO_EDGE: Streach edge pixels out as a border.
 *    GL_CLAMP_TO_BORDER: Set Border around image.
 *        To Set the border color: glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, float[4]);
 * Filtering:
 *    GL_NEAREST: make the texture look blocky
 *    GL_LINEAR: make the texture blurry
 * Mipmaps values:
 *    GL_NEAREST_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_NEAREST_MIPMAP_LINEAR,
 *        GL_LINEAR_MIPMAP_LINEAR: Sample from mipmaps instead.
 * Scaling:
 *    GL_TEXTURE_MIN_FILTER: Scale image down
 *    GL_TEXTURE_MAG_FILTER: Scale image up
 *****************************************************************************/

#include "util/Texture.h"
#include <SOIL.h>


Texture::Texture()
{
    glGenTextures(1, &Id);
}


Texture::~Texture()
{
    glDeleteTextures(1, &Id);
}

void Texture::Generate(GLuint width,GLuint height)
{
    Width = width;
    height = height;

    glBindTexture(GL_TEXTURE_2D, Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Black/white checkerboard
    unsigned char* image = SOIL_load_image("/home/divitoa/Program/c++/projects/game/texture/sample.png",
     &Width, &Height, 0, /*texture.Image_Format == GL_RGBA ? SOIL_LOAD_RGBA :*/ SOIL_LOAD_RGB);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glBindTexture(GL_TEXTURE_2D, Id);
    //glGenerateMipmap(GL_TEXTURE_2D);
    //
    SOIL_free_image_data(image);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, Id);
}