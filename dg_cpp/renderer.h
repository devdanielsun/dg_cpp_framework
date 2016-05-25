/**
* This file is part of DG_CPP, a 2D OpenGL framework.
*
* - Copyright 2015 Dani�l Geerts <daniel.geerts@live.nl>
*   - Initial commit
*/

#ifndef RENDERER_H
#define RENDERER_H

// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/transform.hpp>

// Include all dg_cpp classes needed in this class
#include <dg_cpp/shader.h>
#include <dg_cpp/camera.h>
#include <dg_cpp/scene.h>
#include <dg_cpp/line.h>
#include <dg_cpp/settings.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	void RenderScene(Scene* scene);
	void CleanAndTerminateWindow();

	GLFWwindow* getCurrentWindow() { return _window; }

private:
	void RenderLine(Line* line);

	Timer fpstimer;
	int ShowFramesPerSecond();

	Timer GlobalTimer;
	int GlobalFrameCounter = 0;

	GLFWwindow* _window;

	GLuint programID;
	GLuint vertexPosition_modelspaceID;
	GLuint vertexUVID;
	GLuint matrixID;

	GLuint blendColorID;

	glm::mat4 ProjectionMatrix;
};

#endif /* RENDERER_H */
