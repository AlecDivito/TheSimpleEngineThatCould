/******************************************************************************
 *
 * Input.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 10:22:26 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/Input.h"
#include <GL/glew.h>
#include <iostream>

/* Null, because instance will be initialized on demand. */
Input * Input::instance = 0;

void Input::createInstance(Window * window)
{
    if (instance == 0)
    {
        instance = new Input(window);
    }
}

Input * Input::getInstance()
{
    if (instance == 0)
    {
        throw "You must create the instance first before you can get it! ";
    }

    return instance;
}

Input::Input(Window * window)
{
    glfwSetKeyCallback(window->context, key_callback);
    glfwSetCursorPosCallback(window->context, cursor_pos_callback);
    glfwSetCursorEnterCallback(window->context, cursor_enter_callback);
    glfwSetMouseButtonCallback(window->context, mouse_button_callback);
    glfwSetScrollCallback(window->context, scroll_callback);
}


Input::~Input()
{
    delete instance;
}

void Input::cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
    std::cout << "Mouse Pos, X: " << xpos << ", Y: " << ypos << std::endl;
}

void Input::cursor_enter_callback(GLFWwindow * window, int entered)
{
    if (entered)
    {
        std::cout << "Curosr has Entered the window" << std::endl;
    }
    else
    {
        std::cout << "Cursor has left the window" << std::endl;
    }
}

void Input::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
        std::cout << "Right mouse button was pressed" << std::endl;
}

void Input::scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
    // may recive 2 inputs but most of the time it will be vertical..so yoffset
    std::cout << "Scroll: " << yoffset << std::endl;
}

void Input::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
