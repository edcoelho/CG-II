#include <iostream>
#include <stdexcept>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/vec4.hpp>

#include "graphics/Window.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Program.hpp"
#include "utils.hpp"

// Called when FreeGLUT needs to draw something on the screen.
void display () {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glutSwapBuffers();

}

// Handles keyboard events involving keys that have ASCII representations.
void keyboard (unsigned char key, int x, int y) {

    switch (key) {

        case 27: // ESC

            // Terminates the main FreeGLUT loop.
            glutLeaveMainLoop();

            break;
        
        default:
            break;

    }

    // Asks GLUT to call the display function.
    glutPostRedisplay();

}

// Handles keyboard events involving special keys like Shift, Ctrl, Fn, F1 to F12, etc.
void special_func_keyboard (int key, int x, int y) {}

// Handles events involving mouse buttons.
void mouse (int button, int state, int x, int y) {}

// Handles events involving mouse movement while a button is being pressed.
void mouse_drag (int x, int y) {}

// Handles events involving passive mouse movement (when no button is being pressed).
void mouse_passive_motion (int x, int y) {}

// Handles window resizing events.
void window_reshape (int x, int y) {}

// Handles moments when no events are being processed.
void idle () {

    // Asks GLUT to call the display function.
    glutPostRedisplay();

}

int main(int argc, char * argv[]) {

    // Initialize GLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitContextFlags(GLUT_DEBUG);

    cgII::Window window(500, 500, glm::vec4(0.0, 0.0, 0.0, 1.0), "CG II");

    // Set GLUT callbacks.
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special_func_keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouse_drag);
    glutPassiveMotionFunc(mouse_passive_motion);
    glutReshapeFunc(window_reshape);
    glutIdleFunc(idle);

    // Initialize GLEW to load OpenGL API.
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK) {

        std::cout << "GLEW: Erro ao inicializar!" << std::endl;
        std::cout << "GLEW: " << glewGetErrorString(glew_status) << std::endl;
        return EXIT_FAILURE;

    }

    cgII::enable_openGL_debug_messages();

    cgII::Program program;

    cgII::Shader vertex_shader(GL_VERTEX_SHADER);
    vertex_shader.compile("shaders/vertex.vert");
    program.attach(vertex_shader);

    cgII::Shader fragment_shader(GL_FRAGMENT_SHADER);
    fragment_shader.compile("shaders/fragment.frag");
    program.attach(fragment_shader);

    program.link();
    program.use();

    // Model View Projection matrix
    GLfloat n = -1.0f, f = -5.0f, t = 5.0f, b = -5.0f, r = 5.0f, l = -5.0f;
    GLfloat mvp[4][4] = {
        {2.0f/(r-l), 0.0f, 0.0f, -(r+l)/(r-l)},
        {0.0f, 2.0f/(t-b), 0.0f, -(t+b)/(t-b)},
        {0.0f, 0.0f, 2.0f/(f-n), -(f+n)/(f-n)},
        {0.0f, 0.0f, 0.0f, 1.0f}
    };

    float vertexes[] = {
        -3.0f, 2.5f, -2.0f,
        4.5f, 0.5f, -2.0f,
        0.0f, -4.0f, -2.0f,
    };

    // GLfloat mvp[4][4] = {
    //     {1.0f, 0.0f, 0.0f, 0.0f},
    //     {0.0f, 1.0f, 0.0f, 0.0f},
    //     {0.0f, 0.0f, 1.0f, 0.0f},
    //     {0.0f, 0.0f, 0.0f, 1.0f}
    // };

    // float vertexes[] = {
    //     -0.5f, 0.5f, 0.5f,
    //     0.6f, 0.0f, 0.5f,
    //     0.0f, -0.8f, 0.5f,
    // };

    glUniformMatrix4fv(glGetUniformLocation(program.get_id(), "mvp"), 1, GL_TRUE, &mvp[0][0]); // "transpose" is set to GL_TRUE because the matrix is stored in the C++ program as row-major, while the shader will interpret it as column-major. This is due to the order of matrix multiplication by a vector. When we multiply the matrix on the left side of the vector (A*v), GLSL will interpret the matrix as column-major and the vector as a column vector. Conversely, when we multiply the matrix on the right side of the vector (v*A), GLSL will interpret the matrix as row-major and the vector as a row vector.

    // Create a Vertex Array Object (VAO)
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object (VBO).
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

    GLuint pos = glGetAttribLocation(program.get_id(), "pos");
    glEnableVertexAttribArray(pos);
    glVertexAttribPointer(pos, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    glutMainLoop();

    return EXIT_SUCCESS;

}