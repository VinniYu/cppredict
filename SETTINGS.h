// SETTINGS.h
#pragma once

// =========================
// C++ libraries
// =========================
#include <memory>
#include <string>
#include <iostream>

// =========================
// GLEW and GLUT (platform-specific)
// =========================
#include <GL/glew.h>

#if _WIN32
    #include <GL/freeglut.h>
#elif __APPLE__
    #include <GLUT/glut.h>
#elif __linux__
    #include <GL/freeglut.h>
#endif

// =========================
// Dear ImGui (core + backends)
// =========================
#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "imgui/backends/imgui_impl_glut.h"

// namespaces
using namespace std;
