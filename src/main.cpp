#include <iostream>
#include <stdexcept>
#include <string>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>

#include "graphics/Window.hpp"
#include "graphics/Shader.hpp"
#include "graphics/Program.hpp"
#include "scene/Camera.hpp"
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

    cgII::Camera camera(
        glm::vec3(0.0f, 0.0f, 0.0f), // position
        glm::vec3(0.0f, 0.0f, -1.0f), // look_at
        glm::vec3(0.0f, 1.0f, 0.0f), // view_up (in view/camera space)
        cgII::PERSPECTIVE, // projection type
        // near and far distances (positive numbers)
        1.0f, 5.0f,
        // bottom, top, left, right
        -5.0f, 5.0f, -5.0f, 5.0f
    );
    glm::mat4
        model_mat(1.0f),
        view_mat = camera.view_matrix(),
        projection_mat = camera.projection_matrix();

    float z_v = -5.0;

    float vertexes[] = {
        -3.0f, 2.5f, z_v,
        4.5f, 0.5f, z_v,
        0.0f, -4.0f, z_v
    };

    cgII::Program program;

    cgII::Shader vertex_shader(GL_VERTEX_SHADER);
    vertex_shader.compile("shaders/vertex.vert");
    program.attach(vertex_shader);

    cgII::Shader fragment_shader(GL_FRAGMENT_SHADER);
    fragment_shader.compile("shaders/fragment.frag");
    program.attach(fragment_shader);

    program.link();
    program.use();

    glUniformMatrix4fv(glGetUniformLocation(program.get_id(), "model_mat"), 1, GL_FALSE, glm::value_ptr(model_mat));
    glUniformMatrix4fv(glGetUniformLocation(program.get_id(), "view_mat"), 1, GL_FALSE, glm::value_ptr(view_mat));
    glUniformMatrix4fv(glGetUniformLocation(program.get_id(), "projection_mat"), 1, GL_FALSE, glm::value_ptr(projection_mat));

    // Create a Vertex Array Object (VAO)
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a Vertex Buffer Object (VBO).
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

    GLuint position = glGetAttribLocation(program.get_id(), "position");
    glEnableVertexAttribArray(position);
    glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);

    glutMainLoop();

    return EXIT_SUCCESS;

}