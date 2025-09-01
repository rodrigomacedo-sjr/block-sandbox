#include "LUtil.h"
#include <GL/freeglut_std.h>

bool initGL() {
  // Initialize Projection Matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Initialize Modelview Matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // Initialize clear color
  glClearColor(0.f, 0.f, 0.f, 1.f);

  // Check for error
  GLenum error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error initializing OpenGL! %s\n", gluErrorString(error));
    return false;
  }

  return true;
}

void update() {}

void render() {
  // Render quad
  glBegin(GL_QUADS);
  glVertex2f(-0.5f, -0.5f);
  glVertex2f(0.5f, -0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(-0.5f, 0.5f);
  glEnd();

  // Update screen
  glutSwapBuffers();
}

void runMainLoop(int val) {
  // Frame logic
  update();
  render();

  // Run frame one more time
  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}
