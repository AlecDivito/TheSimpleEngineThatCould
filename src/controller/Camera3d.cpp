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
}


Camera3d::~Camera3d()
{
    _cursor->Detach(this);
}

void Camera3d::Update(Event * eventTriggered)
{
    if (eventTriggered == _cursor)
    {
        std::cout << "the fuck" << std::endl;
    }
}
