#include <memory>
#include <string>
#include <iostream>

// glew and glm
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// OpenGl
#if _WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/freeglut.h>
#endif

using namespace std;
