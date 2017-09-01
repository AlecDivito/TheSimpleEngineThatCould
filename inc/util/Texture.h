#pragma once

/******************************************************************************
 *
 * Texture.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 18:43:05 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>

class Texture
{
    public:
        GLuint Id;

        GLint Width;
        GLint Height;

        GLint Internal_Format; // Format of texture object
        GLint Image_Format; // Format of loaded image

        GLuint Wrap_S;
        GLuint Wrap_T;
        GLuint Filter_Min;
        GLuint Filter_Max;

        const char * Path;

        Texture(const char *);
        virtual ~Texture();
        void Generate();
        void Bind();
    protected:
    private:
        GLint SoilRGBType();
};
