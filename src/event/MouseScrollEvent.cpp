/******************************************************************************
 *
 * MouseScrollEvent.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:55 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/MouseScrollEvent.h"
#include <GL/glew.h>
#include <iostream>

/* Null, because _instance will be initialized on demand. */
MouseScrollEvent * MouseScrollEvent::_instance = nullptr;

void MouseScrollEvent::CreateInstance(Window * window)
{
    if (_instance == nullptr)
    {
        MouseScrollEvent::_instance = new MouseScrollEvent(window);
    }
}

MouseScrollEvent * MouseScrollEvent::GetInstance()
{
    if (_instance == nullptr)
    {
        throw "You must create a MouseScrollEvent _instance first before you can get it! ";
    }

    return _instance;
}

MouseScrollEvent::MouseScrollEvent(Window * window)
{
    glfwSetScrollCallback(window->context, scroll_callback);
}


MouseScrollEvent::~MouseScrollEvent()
{
    delete _instance;
}

void MouseScrollEvent::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
    // may recive 2 inputs but most of the time it will be vertical..so yoffset
    _instance->XOffset = xoffset;
    _instance->YOffset = yoffset;
    _instance->Notify();
    std::cout << "Scroll: " << yoffset << std::endl;
}
