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
        int Width;
        int Height;
        const char * Path;

        Texture();
        virtual ~Texture();
        void Generate(GLuint,GLuint);
        void Bind();
    protected:
    private:
};
