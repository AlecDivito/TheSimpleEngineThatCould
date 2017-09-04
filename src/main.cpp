#include <GL/glew.h>

#include "util/Window.h"
#include "util/Shader.h"
#include "util/ShaderProgram.h"
#include "model/Rectangle.h"
#include "util/Texture.h"

#include "event/MouseInputEvent.h"
#include "event/CursorPositionEvent.h"
#include "event/KeyInputEvent.h"
#include "event/MouseScrollEvent.h"

#include "controller/Camera3d.h"


int main(int argc, char const *argv[])
{
	Window window(640, 480);

	MouseInputEvent::CreateInstance(&window);
	CursorPositionEvent::CreateInstance(&window);
	KeyInputEvent::CreateInstance(&window);
	MouseScrollEvent::CreateInstance(&window);

	Camera3d camera;

	glm::mat4 projection = glm::perspective(
		glm::radians(45.0f), 1.0f * window.Width/window.Height, 0.1f, 500.0f);

	Shader vertex("/home/divitoa/Program/c++/projects/game/shader/basic.vs", GL_VERTEX_SHADER);
	Shader fragment("/home/divitoa/Program/c++/projects/game/shader/basic.fs", GL_FRAGMENT_SHADER);
	ShaderProgram program(vertex, fragment);
	Texture t("/home/divitoa/Program/c++/projects/game/texture/sample.png");
	t.Generate();
	Rectangle rect(&t);

		program.Use();

	program.SetMatrix4("projection", projection);
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
		/* Some math */
		program.SetMatrix4("view", camera.ViewMatrix());
		program.SetMatrix4("model", glm::mat4(1.0f));
		/* Draw stuff */
		// 		program.Use();
		rect.Draw(program);
		/* Swap front and back buffers */
		glfwSwapBuffers(window.context);
		/* Poll for and process events */
		glfwPollEvents();
	}

	return 0;
}

