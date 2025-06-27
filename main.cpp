#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#if _WIN32
#include <GL/freeglut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux__
#include <GL/freeglut.h>
#endif

using namespace std;

// forward declarations
void runOnce();
void runEverytime();

// Text for the title bar of the window
string windowLabel("cppredict");

int xScreenRes = 1024; 
int yScreenRes = 768;

bool animate = false;

///////////////////////////////////////////////////////////////////////
// GL and GLUT callbacks
///////////////////////////////////////////////////////////////////////
void glutDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutSwapBuffers();
}


void glutMotion(int x, int y) {
}

void glutMouse(int button, int state, int x, int y) {

}

///////////////////////////////////////////////////////////////////////
// Map the arrow keys to something here
///////////////////////////////////////////////////////////////////////
void glutSpecial(int key, int x, int y)
{
  switch (key) {
  case GLUT_KEY_LEFT:
    break;
  case GLUT_KEY_RIGHT:
    break;
  case GLUT_KEY_UP:
    break;
  case GLUT_KEY_DOWN:
    break;
  default:
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Map the keyboard keys to something here
///////////////////////////////////////////////////////////////////////
void glutKeyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case ' ':
    animate = !animate;
    break;
  case 'c':
    break;
  case 'o':
    break;
  case 'l':
    break;
  case 'r': 
    break;
  case 'q':
    exit(0);
    break;
  default:
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// animate and display new result
///////////////////////////////////////////////////////////////////////
void glutIdle()
{
  if (animate) {
    runEverytime();
  }
  glutPostRedisplay();
}

//////////////////////////////////////////////////////////////////////////////
// open the GLVU window
//////////////////////////////////////////////////////////////////////////////
int glvuWindow()
{
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(xScreenRes, yScreenRes);
  glutInitWindowPosition(10, 10);

  // request OpenGL 4.3 and core profile
  glutInitContextVersion(4, 3); 
  glutInitContextProfile(GLUT_CORE_PROFILE); 

  // create the context
  glutCreateWindow(windowLabel.c_str());

  // enable modern OpenGL extensions  
  glewExperimental = GL_TRUE; 
  if (glewInit() != GLEW_OK) {
      fprintf(stderr, "Failed to initialize GLEW\n");
      exit(EXIT_FAILURE);
  }

  // initialize everything
  runOnce();

  // set the viewport resolution (w x h)
  glViewport(0, 0, (GLsizei)xScreenRes, (GLsizei)yScreenRes);
  glClearColor(0.0, 0.0, 0.0, 0);

  // register all the callbacks
  glutDisplayFunc(&glutDisplay);
  glutIdleFunc(&glutIdle); 
  glutKeyboardFunc(&glutKeyboard);
  glutSpecialFunc(&glutSpecial);  
  glutMotionFunc(&glutMotion);
  glutMouseFunc(&glutMouse);

  // enter the infinite GL loop
  glutMainLoop();

  // Control flow will never reach here
  return EXIT_SUCCESS;
}  

/////////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////////// 
int main(int argc, char **argv)
{
  // initialize GLUT and GL
  glutInit(&argc, argv); 

  // open the GL window
  glvuWindow();
  return 0;
}

void runEverytime()       
{          
  
  glClearColor(0.0, 1.0, 0.0, 0);
 
}

///////////////////////////////////////////////////////////////////////
// This is called once at the beginning so you can precache
// something here
///////////////////////////////////////////////////////////////////////
void runOnce()
{
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
}
  