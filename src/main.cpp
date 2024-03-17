#include "include_list.hpp"

// Assinaturas das funções callbacks do GLUT.

// É chamada quando o FreeGLUT necessita desenhar algo na tela.
void display ();
// Lida com eventos de teclado envolvendo teclas com representações em ASCII.
void keyboard (unsigned char key, int x, int y);
// Lida com eventos de teclado envolvendo teclas especiais, como Shift, Ctrl, Fn, de F1 até F12, etc.
void special_func_keyboard (int key, int x, int y);
// Lida com eventos envolvendo os botões do mouse.
void mouse (int button, int state, int x, int y);
// Lida com eventos envolvendo o movimento do mouse enquanto um botão é pressionado.
void mouse_motion (int x, int y);
// Lida com eventos envolvendo o movimento passivo do mouse (quando não tem um botão pressionado).
void mouse_passive_motion (int x, int y);
// Lida com eventos de redimensionamento de janelas.
void window_reshape (int x, int y);
// Lida com momentos em que não há nenhum evento sendo processado.
void idle ();

int main(int argc, char * argv[]) {

    // Inicializa o FreeGLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitContextFlags(GLUT_DEBUG);

    // Cria uma janela.
    scene::Window window(500, 500, cyColorA(0.0, 1.0), "CG II");

    // Inicializa o GLEW para carregar as funções do OpenGL.
    GLenum erro = glewInit();
    if (erro != GLEW_OK) {

        std::cout << "Erro ao inicializar o GLEW!" << std::endl;
        std::cout << "Erro: " << glewGetErrorString(erro) << std::endl;

        return EXIT_FAILURE;

    }

    // Habilita a impressão de erros do GLSL no console.
    CY_GL_REGISTER_DEBUG_CALLBACK;

    // Define as funções callback do FreeGLUT.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_func_keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouse_motion);
    glutPassiveMotionFunc(mouse_passive_motion);
    glutReshapeFunc(window_reshape);
    glutIdleFunc(idle);

    // Cria um programa GLSL.
    cyGLSLProgram programa;
    programa.CreateProgram();

    // Cria um vertex shader e o atribui ao programa.
    cyGLSLShader vertex_shader;
    vertex_shader.CompileFile("shaders/vertex.vert", GL_VERTEX_SHADER);
    programa.AttachShader(vertex_shader);

    // Cria um fragment shader e o atribui ao programa.
    cyGLSLShader fragment_shader;
    fragment_shader.CompileFile("shaders/fragment.frag", GL_FRAGMENT_SHADER);
    programa.AttachShader(fragment_shader);

    // Linka o programa para que os seus shaders sejam usados.
    if (!programa.Link()) {

        std::cout << "Erro ao linkar o programa!" << std::endl;
        return EXIT_FAILURE;

    }

    // Indica que o programa será usado.
    programa.Bind();

    // Passando a matriz MVP para o programa.
    GLfloat n = 1.0f, f = 5.0f, t = 5.0f, b = -5.0f, r = 5.0f, l = -5.0f;
    GLfloat mvp[4][4] = {
        {2.0f/(r-l), 0.0f, 0.0f, -(r+l)/(r-l)},
        {0.0f, 2.0f/(t-b), 0.0f, -(t+b)/(t-b)},
        {0.0f, 0.0f, 2.0f/(f-n), -(f+n)/(f-n)},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    glUniformMatrix4fv(glGetUniformLocation(programa.GetID(), "mvp"), 1, GL_FALSE, &mvp[0][0]);

    // Vértices para teste
    float vertices[] = {
        -3.0f, 2.5f, 0.0f,
        4.5f, 0.5f, 0.0f,
        0.0f, -4.0f, 0.0f,
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
    GLuint pos = glGetAttribLocation(programa.GetID(), "pos");
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