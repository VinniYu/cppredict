
#include "SETTINGS.h"

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

  ImGui_ImplGLUT_NewFrame();
  ImGui_ImplOpenGL3_NewFrame();
  ImGui::NewFrame();

  // where drawing happens
  glClearColor(1.0, 0.0, 0.0, 1.0);


  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  

  glutSwapBuffers();
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
  //(commented out input callbacks to give ImGui control)
  glutDisplayFunc(&glutDisplay);
  glutIdleFunc(&glutIdle); 
  // glutKeyboardFunc(&glutKeyboard);
  // glutSpecialFunc(&glutSpecial);  
  // glutMotionFunc(&glutMotion);
  // glutMouseFunc(&glutMouse);

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
  // initialize ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); 
  (void)io;
  ImGui::StyleColorsDark();
  ImGui_ImplGLUT_Init();
  ImGui_ImplGLUT_InstallFuncs();
  ImGui_ImplOpenGL3_Init("#version 430 core");
}
  