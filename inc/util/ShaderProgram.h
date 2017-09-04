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
        void SetFloat    (const GLchar *, GLfloat, GLboolean = true);
        void SetInteger  (const GLchar *, GLint,   GLboolean = true);
        void SetVector2f (const GLchar *, GLfloat, GLfloat, GLboolean = true);
        void SetVector3f (const GLchar *, GLfloat, GLfloat, GLfloat, GLboolean = true);
        void SetVector4f (const GLchar *, GLfloat, GLfloat, GLfloat, GLfloat, GLboolean = true);
        void SetVector2f (const GLchar *, const glm::vec2 &, GLboolean = true);
        void SetVector3f (const GLchar *, const glm::vec3 &, GLboolean = true);
        void SetVector4f (const GLchar *, const glm::vec4 &, GLboolean = true);
        void SetMatrix4  (const GLchar *, const glm::mat4 &, GLboolean = true);

    protected:
    private:
       GLuint program;
};
