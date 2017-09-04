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

Camera3d::Camera3d()
{
    _cursor = CursorPositionEvent::GetInstance();
    _cursor->Attach(this);
    _keys = KeyInputEvent::GetInstance();
    _keys->Attach(this);
}


Camera3d::~Camera3d()
{
    _cursor->Detach(this);
    _keys->Attach(this);
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
}

void Camera3d::_processMouseMovement()
{
    std::cout << "cursor move " << _cursor->XPos << std::endl;
}

void Camera3d::_updateCameraVectors()
{

}