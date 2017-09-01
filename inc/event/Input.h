#pragma once

/******************************************************************************
 *
 * Input.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 10:22:26 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"

class Input
{
    public:
        virtual ~Input();
        static void createInstance(Window *);
        static Input * getInstance();

        Input(Input const&)           = delete;
        void operator=(Input const&)  = delete;
    private:
        Input(Window *);
        static Input * instance;

        static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
        static void scroll_callback(GLFWwindow * window, double xoffset, double yoffset);
        static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
        static void cursor_enter_callback(GLFWwindow * window, int entered);
        static void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);
};
