/******************************************************************************
 *
 * MouseInputEvent.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:50 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/MouseInputEvent.h"
#include <iostream>

/* Null, because _instance will be initialized on demand. */
MouseInputEvent * MouseInputEvent::_instance = nullptr;

void MouseInputEvent::CreateInstance(Window * window)
{
    if (_instance == nullptr)
    {
        _instance = new MouseInputEvent(window);
    }
}

MouseInputEvent * MouseInputEvent::GetInstance()
{
    if (_instance == nullptr)
    {
        throw "You must create a MouseInputEvent _instance first before you can get it! ";
    }

    return _instance;
}

MouseInputEvent::MouseInputEvent(Window * window)
{
    glfwSetMouseButtonCallback(window->context, mouse_button_callback);
}


MouseInputEvent::~MouseInputEvent()
{
    delete _instance;
}

void MouseInputEvent::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
    _instance->Button = button;
    _instance->Action = action;
    _instance->Mods = mods;
    _instance->Notify();
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
        std::cout << "Right mouse button was pressed" << std::endl;
}
