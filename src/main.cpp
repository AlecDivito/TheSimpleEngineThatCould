#include <iostream>

#include <GL/glew.h>

#include "util/Window.h"
#include "util/Shader.h"
#include "util/ShaderProgram.h"
#include "model/Rectangle.h"
#include "util/Texture.h"

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
	Window window(640, 480);

	Shader vertex("/home/divitoa/Program/c++/projects/game/shader/basic.vs", GL_VERTEX_SHADER);
	Shader fragment("/home/divitoa/Program/c++/projects/game/shader/basic.fs", GL_FRAGMENT_SHADER);
	ShaderProgram program(vertex, fragment);
	Rectangle rect;
	Texture t("/home/divitoa/Program/c++/projects/game/texture/sample.png");
	t.Generate();

	program.SetVector3f("uniColor", glm::vec3(1.0f, 0.0f, 0.0f), true);

	glfwSetKeyCallback(window.context, key_callback);
	glfwSetCursorPosCallback(window.context, cursor_pos_callback);
	glfwSetCursorEnterCallback(window.context, cursor_enter_callback);
	glfwSetMouseButtonCallback(window.context, mouse_button_callback);
	glfwSetScrollCallback(window.context, scroll_callback);
	glfwSetInputMode(window.context, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // set the cursor to be hidden and in the middle of the screen

	/* Loop until the user closes the window */
	double init_time = glfwGetTime(); // get time of startup
	while (!glfwWindowShouldClose(window.context))
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		program.Use();
		t.Bind();
		rect.Draw();
		/* Swap front and back buffers */
		glfwSwapBuffers(window.context);
		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}

