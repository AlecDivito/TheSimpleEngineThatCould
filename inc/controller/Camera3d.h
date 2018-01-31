#pragma once

/******************************************************************************
 *
 * Camera3d.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 20:45:22 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/CursorPositionEvent.h"
#include "event/KeyInputEvent.h"
#include "event/Event.h"

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const GLfloat YAW        = -90.0f;
const GLfloat PITCH      =  0.0f;
const GLfloat SPEED      =  5.0f;
const GLfloat SENSITIVTY =  0.25f;

class Camera3d : public Observer
{
    public:
        // just some camera info
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // Eular angles
        GLfloat Yaw;
        GLfloat Pitch;
        // camera options
        GLfloat MovementSpeed;
        GLfloat MouseSensitivity;
        bool ConstrainPitch;
        // constructor
        // Camera3d();
        Camera3d(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
                 glm::vec3 up       = glm::vec3(0.0f, 1.0f, 0.0f),
                 GLfloat yaw = YAW, GLfloat pitch = PITCH);
        Camera3d(GLfloat posx,GLfloat posy, GLfloat posz,
                 GLfloat upx, GLfloat upy,  GLfloat upz,
                 GLfloat yaw, GLfloat pitch);
       virtual ~Camera3d();
        // View Matrix
        glm::mat4 ViewMatrix();
        // update camera
        virtual void Update(Event *);
        void ProcessKeyboard();
    protected:
    private:
        // events
        CursorPositionEvent * _cursor;
        KeyInputEvent * _keys;
        // process events
        void _processMouseMovement();
        // Calculate front vector
        void _updateCameraVectors();
};
