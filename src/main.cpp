#include <GL/glew.h>

#include "util/Window.h"
#include "util/Shader.h"
#include "util/ShaderProgram.h"
#include "model/Rectangle.h"
#include "util/Texture.h"

int main(int argc, char const *argv[])
{
	Window window(640, 480);

	Shader vertex("/home/divitoa/Program/c++/projects/game/shader/basic.vs", GL_VERTEX_SHADER);
	Shader fragment("/home/divitoa/Program/c++/projects/game/shader/basic.fs", GL_FRAGMENT_SHADER);
	ShaderProgram program(vertex, fragment);
	Texture t("/home/divitoa/Program/c++/projects/game/texture/sample.png");
	t.Generate();
	Rectangle rect(&t);

	program.SetVector3f("uniColor", glm::vec3(1.0f, 0.0f, 0.0f), true);

	 // set the cursor to be hidden and in the middle of the screen
	//glfwSetInputMode(window.context, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	/* Loop until the user closes the window */
	double init_time = glfwGetTime(); // get time of startup
	while (!glfwWindowShouldClose(window.context))
	{
		/* Render here */
		glClearColor(0.2f, 0.3f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		program.Use();
		rect.Draw(program);
		/* Swap front and back buffers */
		glfwSwapBuffers(window.context);
		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}

