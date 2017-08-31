/******************************************************************************
 *
 * ShaderProgram.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 11:38:17 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/ShaderProgram.h"
#include <iostream>

ShaderProgram::ShaderProgram(Shader vertex, Shader fragment)
{
	program = glCreateProgram();

	glAttachShader(program, vertex.shader);
	glAttachShader(program, fragment.shader);
	glLinkProgram(program);

    GLint status;
    glGetShaderiv(program, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(program, 512, NULL, buffer);
        std::cout << "| ERROR::SHADERPROGRAM: Compile-time error: Type: PROGRAM" << "\n"
            << buffer << "\n -- --------------------------------------------------- -- "
            << std::endl;
    }
}


ShaderProgram::~ShaderProgram()
{
	glDeleteShader(program);
}

ShaderProgram & ShaderProgram::Use()
{
	glUseProgram(program);
    return *this;
}

void ShaderProgram::SetFloat(const GLchar* name, GLfloat value, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform1f(glGetUniformLocation(program, name), value);
}

void ShaderProgram::SetInteger(const GLchar* name, GLint value, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform1i(glGetUniformLocation(program, name), value);
}

void ShaderProgram::SetVector2f(const GLchar* name, GLfloat x, GLfloat y, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform2f(glGetUniformLocation(program, name), x, y);
}

void ShaderProgram::SetVector2f (const GLchar* name, const glm::vec2 &value, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform2f(glGetUniformLocation(program, name), value.x, value.y);
}

void ShaderProgram::SetVector3f (const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform3f(glGetUniformLocation(program, name), x, y, z);
}

void ShaderProgram::SetVector3f (const GLchar* name, const glm::vec3 &value, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform3f(glGetUniformLocation(program, name), value.x, value.y, value.z);
}

void ShaderProgram::SetVector4f (const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform4f(glGetUniformLocation(program, name), x, y, z, w);
}

void ShaderProgram::SetVector4f (const GLchar* name, const glm::vec4 &value, GLboolean useShader)
{
    if (useShader) {
        Use();
    }
    glUniform4f(glGetUniformLocation(program, name), value.x, value.y, value.z, value.w);
}

void ShaderProgram::SetMatrix4  (const GLchar* name, const glm::mat4 &matrix, GLboolean useShader)
{
    if(useShader) {
        Use();
    }
    glUniformMatrix4fv(glGetUniformLocation(program, name), 1, GL_FALSE, glm::value_ptr(matrix));
}