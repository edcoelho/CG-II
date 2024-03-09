#include <GL/glew.h>
#include <GL/freeglut.h>

#include "FreeGLUT_callbacks.h"

int main(int argc, char *argv[]) {

    // Inicializa o FreeGLUT.
    glutInit(&argc, argv);

    // Configura o modo do FreeGLUT.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

    // Cria uma janela.
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CG II");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Define as funções callback do FreeGLUT.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialFuncKeyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mousePassiveMotion);
    glutReshapeFunc(windowReshape);
    glutIdleFunc(idle);

    // Entra no loop do FreeGLUT.
    glutMainLoop();

    return EXIT_SUCCESS;

}

// É chamada quando o FreeGLUT necessita desenhar algo na tela.
void display () {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // TODO

    // Troca o buffer exibido (double buffering).
    glutSwapBuffers();

}

// Lida com eventos de teclado envolvendo teclas com representações em ASCII.
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

// Lida com eventos de teclado envolvendo teclas especiais, como Shift, Ctrl, Fn, de F1 até F12, etc.
void specialFuncKeyboard (int key, int x, int y) {

    // TODO

}

// Lida com eventos envolvendo os botões do mouse.
void mouse (int button, int state, int x, int y) {

    // TODO

}

// Lida com eventos envolvendo o movimento do mouse enquanto um botão é pressionado.
void mouseMotion (int x, int y) {

    // TODO

}

// Lida com eventos envolvendo o movimento passivo do mouse (quando não tem um botão pressionado).
void mousePassiveMotion (int x, int y) {

    // TODO

}

// Lida com eventos de redimensionamento de janelas.
void windowReshape (int x, int y) {

    // TODO

}

// Lida com momentos em que não há nenhum evento sendo processado.
void idle () {

    // TODO

    // Pede ao FreeGLUT para chamar a função display.
    glutPostRedisplay();

}