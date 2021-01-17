//#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>


// Personal
#include "util/logger.hpp"

using namespace glm;

int main() {
	const char* title = "OpenGL Learning";
	Logger* logger = new Logger(logLevel::DEBUG);
	logger->log(logLevel::DEBUG, "Launching application. So far so good");

	glewExperimental = true;
	
	if (!glfwInit()) {
		logger->log(logLevel::FATAL, "Failed to initialize GLFW", true);
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	// Open window and create OpenGL Context

	GLFWwindow* window = glfwCreateWindow(1024, 768, title, NULL, NULL);
	if (window == NULL) {
		logger->log(logLevel::FATAL, "Failed to open GLFW Window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials");
		glfwTerminate();
		return -1;
	}

	/* At this point, a window quickly launches and closes. */

	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		logger->log(logLevel::FATAL, "Failed to initialize GLEW", true);
	}


	/* Now to capture keys and close on escape */
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	do {
		glClear(GL_COLOR_BUFFER_BIT);

		/* Drawing happens here */

		glfwSwapBuffers(window); /* Not quite sure what swapping buffers does, or what buffers even are, yet. */
		glfwPollEvents(); 
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);
}