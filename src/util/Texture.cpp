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


Texture::Texture(const char * path) : Width(0), Height(0), Internal_Format(GL_RGB),
    Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT),
    Filter_Min(GL_NEAREST), Filter_Max(GL_NEAREST), Path(path)
{
    glGenTextures(1, &Id);
}


Texture::~Texture()
{
    glDeleteTextures(1, &Id);
}

void Texture::Generate()
{
    glBindTexture(GL_TEXTURE_2D, Id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Wrap_S); // wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Wrap_T);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Filter_Min); // filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Filter_Max);

    unsigned char * image = SOIL_load_image(Path, &Width, &Height, 0, SoilRGBType());

    glTexImage2D(GL_TEXTURE_2D, 0, Internal_Format, Width, Height, 0, Image_Format,
        GL_UNSIGNED_BYTE, image);

    glBindTexture(GL_TEXTURE_2D, Id);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(image);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, Id);
}

GLint Texture::SoilRGBType()
{
    return (Image_Format == GL_RGBA) ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB;
}

