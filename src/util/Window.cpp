/******************************************************************************
 *
 * Window.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 12:41:08 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"
#include <iostream>

Window::Window(int width, int height) : Width(width), Height(height)
{
    glfwSetErrorCallback(this->error_callback);

    /* Initialize the library */
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    context = glfwCreateWindow(Width, Height, "Hello World", nullptr, nullptr);
    if (!context)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // set up window callbacks
    glfwSetWindowCloseCallback(context, this->close_window_callback);
    glfwSetFramebufferSizeCallback(context, this->framebuffer_size_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(context);

	glfwSetInputMode(context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    /* Initializing GLEW */
    glewExperimental = GL_TRUE; // (if we didn't do this, could cause issues when using the core profile)
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        exit(EXIT_FAILURE);
    }

    int w, h;
    glfwGetFramebufferSize(context, &w, &h);
    // set the view port
    glViewport(0, 0, w, h);
    // enable depth testing    
    glEnable(GL_DEPTH_TEST);
}

Window::~Window()
{
    glfwDestroyWindow(context); // destroy the window
    glfwTerminate();
}

void Window::error_callback(int error, const char * description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void Window::close_window_callback(GLFWwindow * context)
{
    std::cout << "Closing Window" << std::endl;
}

void Window::framebuffer_size_callback(GLFWwindow * context, int width, int height)
{
/*    Width = width;
    Height = height;*/
    // glViewport(0, 0, width, height);
    std::cout << "Window Resize, Width: " << width << ", Height: " << height << std::endl;
}
