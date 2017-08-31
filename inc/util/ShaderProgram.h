#pragma once

/******************************************************************************
 *
 * ShaderProgram.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 11:38:17 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Shader.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class ShaderProgram
{
    public:
        ShaderProgram(Shader, Shader);
        virtual ~ShaderProgram();
        ShaderProgram & Use();
        // uniform
        void SetFloat    (const GLchar *, GLfloat, GLboolean);
        void SetInteger  (const GLchar *, GLint,   GLboolean);
        void SetVector2f (const GLchar *, GLfloat, GLfloat, GLboolean);
        void SetVector3f (const GLchar *, GLfloat, GLfloat, GLfloat, GLboolean);
        void SetVector4f (const GLchar *, GLfloat, GLfloat, GLfloat, GLfloat, GLboolean);
        void SetVector2f (const GLchar *, const glm::vec2 &, GLboolean);
        void SetVector3f (const GLchar *, const glm::vec3 &, GLboolean);
        void SetVector4f (const GLchar *, const glm::vec4 &, GLboolean);
        void SetMatrix4  (const GLchar *, const glm::mat4 &, GLboolean);

    protected:
    private:
       GLuint program;
};
