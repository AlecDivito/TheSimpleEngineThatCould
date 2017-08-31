#pragma once

/******************************************************************************
 *
 * Window.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 12:41:08 EDT 2017
 * {description}
 *
 *****************************************************************************/

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
    public:
        // Variables
        int Width;
        int Height;
        GLFWwindow * context;

        Window(int, int);
        virtual ~Window();
        GLFWwindow * getWindow();
    protected:
    private:
        static void error_callback(int, const char *);
        static void close_window_callback(GLFWwindow *);
        static void framebuffer_size_callback(GLFWwindow *, int, int);
};
