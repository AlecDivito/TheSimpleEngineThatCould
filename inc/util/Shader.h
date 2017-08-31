#pragma once

/******************************************************************************
 *
 * Shader.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 11:09:43 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>

class Shader
{
    public:
       GLuint Id;
       GLenum Type;
       const char * Path;
       Shader(const char *, GLenum);
       virtual ~Shader();
    protected:
    private:
       void CreateShader(const char *);
       void Compile(const GLchar * source);
};
