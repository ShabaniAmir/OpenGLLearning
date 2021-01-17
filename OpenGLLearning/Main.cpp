#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Personal
#include "util/logger.hpp"

using namespace glm;

int main() {
	Logger* logger = new Logger(logLevel::DEBUG);
	logger->log(logLevel::DEBUG, "Launching application. So far so good");
}