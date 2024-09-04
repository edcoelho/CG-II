#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <GL/glew.h>
#include <string>

#ifndef APIENTRY
#define APIENTRY
#endif

namespace cgII {

    // OpenGL Debug

    std::string get_openGL_version ();
    void APIENTRY openGL_debug_message_callback (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
    void enable_openGL_debug_messages (bool enable_notifications = true);

}

#endif