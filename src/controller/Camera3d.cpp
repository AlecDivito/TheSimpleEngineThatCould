/******************************************************************************
 *
 * Camera3d.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 20:45:22 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "controller/Camera3d.h"
#include <iostream>

// Camera3d::Camera3d() :  Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
//                MouseSensitivity(SENSITIVTY), ConstrainPitch(true)
// {
//     _cursor = CursorPositionEvent::GetInstance();
//     _cursor->Attach(this);
//     _keys = KeyInputEvent::GetInstance();
//     _keys->Attach(this);

//     Position = glm::vec3(0.0f, 0.0f, 0.0f);
//     WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
//     Yaw = YAW;
//     Pitch = PITCH;
//     _updateCameraVectors();
// }

Camera3d::Camera3d(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) :
               Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
               MouseSensitivity(SENSITIVTY), ConstrainPitch(true)
{
    _cursor = CursorPositionEvent::GetInstance();
    _cursor->Attach(this);
    _keys = KeyInputEvent::GetInstance();
    _keys->Attach(this);

    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    _updateCameraVectors();
}

Camera3d::Camera3d(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX,
       GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) :
       Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED),
       MouseSensitivity(SENSITIVTY), ConstrainPitch(true)
{
    _cursor = CursorPositionEvent::GetInstance();
    _cursor->Attach(this);
    _keys = KeyInputEvent::GetInstance();
    _keys->Attach(this);

    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    _updateCameraVectors();
}

Camera3d::~Camera3d()
{
    _cursor->Detach(this);
    _keys->Attach(this);
}

glm::mat4 Camera3d::ViewMatrix()
{
    // pos in world space, where we want the camerat to move, vector pointing up
    return glm::lookAt(Position, Position + Front, Up);
}

void Camera3d::Update(Event * eventTriggered)
{
    if (eventTriggered == _cursor)
    {
        _processMouseMovement();
    }
    if (eventTriggered == _keys)
    {
        _processKeyboard();
    }
}

void Camera3d::_processKeyboard()
{
    std::cout << "key press " << _keys->Key << std::endl;
    GLfloat velocity = MovementSpeed * 0.5;// * deltaTime;
    if(_keys->Keys[GLFW_KEY_W])
    {
        Position += Front * velocity;
    }
    if(_keys->Keys[GLFW_KEY_S])
    {
        Position -= Front * velocity;
    }
    if(_keys->Keys[GLFW_KEY_A])
    {
        Position -= Right * velocity;
    }
    if(_keys->Keys[GLFW_KEY_D])
    {
        Position += Right * velocity;
    }
    std::cout << Position.x << " "<< Position.y << " "<< Position.z << " " << std::endl;
}

void Camera3d::_processMouseMovement()
{
    std::cout << "cursor move " << _cursor->XPos << " " << _cursor->XOffset << std::endl;
    float xoffset = _cursor->XOffset * MouseSensitivity;
    float yoffset = _cursor->YOffset * MouseSensitivity;

    Yaw   += xoffset;
    Yaw   = glm::mod( Yaw + xoffset, 360.0f );
    Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (ConstrainPitch)
    {
        if (Pitch > 89.0f) {
            Pitch = 89.0f;
        }
        if (Pitch < -89.0f) {
            Pitch = -89.0f;
        }
    }

    // Update Front, Right and Up Vectors using the updated Eular angles
    _updateCameraVectors();
}

void Camera3d::_updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front   = glm::normalize(front);
    // Also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));
    // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up    = glm::normalize(glm::cross(Right, Front));
}