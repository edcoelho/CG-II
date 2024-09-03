#include <iostream>
#include <stdexcept>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec4.hpp>

#include "utils.hpp"
#include "graphics/Window.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Program.hpp"

int main(int argc, char * argv[]) {

    // Inicializa o FreeGLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitContextFlags(GLUT_DEBUG);

    // Cria a janela.
    cgII::Window window(500, 500, glm::vec4(0.0, 0.0, 0.0, 1.0), "CG II");

    // Define as funções callback do FreeGLUT.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_func_keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouse_motion);
    glutPassiveMotionFunc(mouse_passive_motion);
    glutReshapeFunc(window_reshape);
    glutIdleFunc(idle);

    // Inicializa o GLEW para carregar as funções do OpenGL.
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {

        std::cout << "GLEW: Erro ao inicializar!" << std::endl;
        std::cout << "GLEW: " << glewGetErrorString(glew_status) << std::endl;
        return EXIT_FAILURE;

    }

    // Cria um programa GLSL.
    cgII::Program program;

    // Cria um vertex shader e o atribui ao programa.
    cgII::Shader vertex_shader(GL_VERTEX_SHADER);
    vertex_shader.compile("shaders/vertex.glsl");
    program.attach(vertex_shader);

    // Cria um fragment shader e o atribui ao programa.
    cgII::Shader fragment_shader(GL_FRAGMENT_SHADER);
    fragment_shader.compile("shaders/fragment.glsl");
    program.attach(fragment_shader);

    // Linka o programa para que os seus shaders sejam usados e indica que ele será usado.
    program.link();
    program.use();

    // Passando a matriz MVP para o programa.
    GLfloat n = 1.0f, f = 5.0f, t = 5.0f, b = -5.0f, r = 5.0f, l = -5.0f;
    GLfloat mvp[4][4] = {
        {2.0f/(r-l), 0.0f, 0.0f, -(r+l)/(r-l)},
        {0.0f, 2.0f/(t-b), 0.0f, -(t+b)/(t-b)},
        {0.0f, 0.0f, 2.0f/(f-n), -(f+n)/(f-n)},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    glUniformMatrix4fv(glGetUniformLocation(program.get_id(), "mvp"), 1, GL_FALSE, &mvp[0][0]);

    // Vértices para teste
    float vertices[] = {
        -3.0f, 2.5f, 2.0f,
        4.5f, 0.5f, 2.0f,
        0.0f, -4.0f, 2.0f,
    };

    // Cria um Vertex Array Object (VAO)
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Cria um Vertex Buffer Object (VBO).
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Descreve ao OpenGL a organização dos dados no buffer.
    GLuint pos = glGetAttribLocation(program.get_id(), "pos");
    glEnableVertexAttribArray(pos);
    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    // Entra no loop do FreeGLUT.
    glutMainLoop();

    return EXIT_SUCCESS;

}

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