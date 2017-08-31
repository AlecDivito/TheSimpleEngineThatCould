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

#include <string>
#include <GL/glew.h>

class Shader
{
    public:
       GLuint shader;
       Shader(std::string, GLenum);
       virtual ~Shader();
    protected:
    private:
       const GLchar * source;
       const char * getFileSource(std::string);
};
