/******************************************************************************
 *
 * KeyInputEvent.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:43 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/KeyInputEvent.h"
#include <GL/glew.h>
#include <iostream>

/* Null, because _instance will be initialized on demand. */
KeyInputEvent * KeyInputEvent::_instance = 0;

void KeyInputEvent::CreateInstance(Window * window)
{
    if (_instance == 0)
    {
        _instance = new KeyInputEvent(window);
    }
}

KeyInputEvent * KeyInputEvent::GetInstance()
{
    if (_instance == 0)
    {
        throw "You must create a KeyInputEvent _instance first before you can get it! ";
    }

    return _instance;
}
KeyInputEvent::KeyInputEvent(Window * window)
{
    glfwSetKeyCallback(window->context, key_callback);
}


KeyInputEvent::~KeyInputEvent()
{
    delete _instance;
}

void KeyInputEvent::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    _instance->Key = key;
    _instance->Scancode = scancode;
    _instance->Action = action;
    _instance->Mods = mods;

    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            _instance->Keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            _instance->Keys[key] = false;
        }
    }

    _instance->Notify();
}
