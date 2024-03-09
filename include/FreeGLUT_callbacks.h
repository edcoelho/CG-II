#ifndef FREEGLUT_CALLBACKS_H
#define FREEGLUT_CALLBACKS_H

// Funções callbacks do FreeGLUT.

void display ();
void keyboard (unsigned char key, int x, int y);
void specialFuncKeyboard (int key, int x, int y);
void mouse (int button, int state, int x, int y);
void mouseMotion (int x, int y);
void mousePassiveMotion (int x, int y);
void windowReshape (int x, int y);
void idle ();

#endif