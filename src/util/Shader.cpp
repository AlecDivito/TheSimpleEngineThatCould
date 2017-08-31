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
#include <fstream>
#include <iostream>

Shader::Shader(std::string path, GLenum shaderType)
{
	source = getFileSource(path);
	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (status != GL_TRUE) {
		char buffer[512];
		glGetShaderInfoLog(shader, 512, NULL, buffer);
        std::cout << "| ERROR::SHADER: Compile-time error: Type: " << shaderType << "\n"
            << buffer << "\n -- --------------------------------------------------- -- "
            << std::endl;
    }
}


Shader::~Shader()
{
    glDeleteShader(shader);
    delete[] source;
}

const char * Shader::getFileSource(std::string path)
{
	std::ifstream file;

	file.open(path);
	if (!file) {
		std::cout << "Unable to open file: " << path << std::endl;
	}

	std::string output;
	std::string line;
	while (!file.eof()) {
		getline(file, line);
		output.append(line + "\n");
	}
	file.close();
	return output.c_str();
}
