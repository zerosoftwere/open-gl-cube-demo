#pragma once

#include <Windows.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <sstream>

#ifndef GLSL
#define GLSL(version, code) "#version " #version "\n" #code
#endif

void ShaderCompileCheck(GLuint id);
void ShaderLinkCheck(GLuint id);
GLuint LoadShaders(const char* vert, const char* frag);