/******************************************************************************
 *
 * Shader.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 11:09:43 EDT 2017
 * shaderType can be = (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER )
 *
 *****************************************************************************/

#include "util/Shader.h"
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>

Shader::Shader(const char * path, GLenum shaderType)
{
    Path = path;
    Type = shaderType;
    CreateShader(path);
}


Shader::~Shader()
{
    glDeleteShader(Id);
}

void Shader::CreateShader(const char * path)
{
    std::string fileSource;

    try
    {
        std::ifstream file(path);
        std::stringstream stream;

        stream << file.rdbuf();

        file.close();

        fileSource = stream.str();
    }
    catch(std::exception e)
    {
        std::cout << "ERROR::SHADER: Failed to read Id files" << std::endl;
    }

    const GLchar * temp = fileSource.c_str();
    Compile(temp);
}

void Shader::Compile(const GLchar * source)
{
    Id = glCreateShader(Type);
    glShaderSource(Id, 1, &source, NULL);
    glCompileShader(Id);

    GLint status;
    glGetShaderiv(Id, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(Id, 512, NULL, buffer);
        std::cout << "| ERROR::SHADER: Compile-time error: Type: " << Type << "\n"
            << buffer << "\n -- --------------------------------------------------- -- "
            << std::endl;
    }

}
