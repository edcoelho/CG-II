#include "glut_callbacks.hpp"
#include <GL/freeglut.h>

void display () {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    // TODO

    // Troca o buffer exibido (double buffering).
    glutSwapBuffers();

}

void keyboard (unsigned char key, int x, int y) {

    switch (key) {

        case 27: // ESC

            // Encerra o loop principal do FreeGLUT.
            glutLeaveMainLoop();

            break;
        
        default:
            break;

    }

    // Pede ao FreeGLUT para chamar a função display.
    glutPostRedisplay();

}

void special_func_keyboard (int key, int x, int y) {

    // TODO

}

void mouse (int button, int state, int x, int y) {

    // TODO

}

void mouse_motion (int x, int y) {

    // TODO

}

void mouse_passive_motion (int x, int y) {

    // TODO

}

void window_reshape (int x, int y) {

    // TODO

}

void idle () {

    // TODO

    // Pede ao FreeGLUT para chamar a função display.
    glutPostRedisplay();

}

void set_glut_callbacks() {

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_func_keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouse_motion);
    glutPassiveMotionFunc(mouse_passive_motion);
    glutReshapeFunc(window_reshape);
    glutIdleFunc(idle);

}