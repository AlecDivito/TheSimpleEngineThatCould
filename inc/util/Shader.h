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
       Shader(std::string, GLenum);
       virtual ~Shader();
    protected:
    private:
       GLuint shader;
       const GLchar * source;
       const char * getFileSource(std::string);
};
