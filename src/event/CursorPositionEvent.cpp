/******************************************************************************
 *
 * CursorPositionEvent.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:31:10 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/CursorPositionEvent.h"
#include <GL/glew.h>
#include <iostream>

/* Null, because _instance will be initialized on demand. */
CursorPositionEvent * CursorPositionEvent::_instance = 0;

void CursorPositionEvent::CreateInstance(Window * window)
{
    if (_instance == 0)
    {
        _instance = new CursorPositionEvent(window);
    }
}

CursorPositionEvent * CursorPositionEvent::GetInstance()
{
    if (_instance == 0)
    {
        throw "You must create a CursorPositionEvent _instance first before you can get it! ";
    }

    return _instance;
}

CursorPositionEvent::CursorPositionEvent(Window * window)
{
    glfwSetCursorPosCallback(window->context, cursor_pos_callback);
    LastXPos = (double)window->Width / 2.0;
    LastYPos = window->Height / 2.0;
    _hasMouseMovementStarted = false;
}


CursorPositionEvent::~CursorPositionEvent()
{
    delete _instance;
}

void CursorPositionEvent::cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
    _instance->XPos = xpos;
    _instance->YPos = ypos;

    if ( ! _instance->_hasMouseMovementStarted)
    {
        _instance->LastXPos = xpos;
        _instance->LastYPos = ypos;
        _instance->_hasMouseMovementStarted = true;
    }

    _instance->XOffset = xpos - _instance->LastXPos;
    _instance->YOffset = _instance->LastYPos - ypos;

    _instance->LastXPos = xpos;
    _instance->LastYPos = ypos;

    _instance->Notify();
}