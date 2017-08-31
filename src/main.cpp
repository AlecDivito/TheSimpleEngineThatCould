#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char * description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void close_window_callback(GLFWwindow * window) 
{
	std::cout << "Closing Window" << std::endl;
}

void framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	// glViewport(0, 0, width, height);
	std::cout << "Window Resize, Width: " << width << ", Height: " << height << std::endl;
}

void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos)
{
	std::cout << "Mouse Pos, X: " << xpos << ", Y: " << ypos << std::endl;
}

void cursor_enter_callback(GLFWwindow * window, int entered)
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

void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS);
		std::cout << "Right mouse button was pressed" << std::endl;
}

void scroll_callback(GLFWwindow * window, double xoffset, double yoffset)
{
	// may recive 2 inputs but most of the time it will be vertical..so yoffset
	std::cout << "Scroll: " << yoffset << std::endl;
}

static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}


int main(int argc, char const *argv[])
{
	GLFWwindow* window;
	
	glfwSetErrorCallback(error_callback);

	/* Initialize the library */
        if (!glfwInit())
	        exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, key_callback);
	glfwSetWindowCloseCallback(window, close_window_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
	glfwSetCursorEnterCallback(window, cursor_enter_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // set the cursor to be hidden and in the middle of the screen

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	double init_time = glfwGetTime(); // get time of startup
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwDestroyWindow(window); // destroy the window
 	glfwTerminate();
	return 0;
}

