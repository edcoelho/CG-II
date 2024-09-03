#include "graphics/Program.hpp"
#include <iostream>

namespace cgII {

    Program::Program () : is_created(true) {

        this->id = glCreateProgram();

    }
    Program::~Program () {

        this->destroy();

    }

    GLuint Program::get_id () const {

        return this->id;

    }

    void Program::attach (GLuint shader_id) {

        if (!this->is_created) {

            this->id = glCreateProgram();
            this->is_created = true;

        }

        glAttachShader(this->get_id(), shader_id);

    }

    void Program::attach (Shader shader) {

        this->attach(shader.get_id());

    }

    void Program::detach (GLuint shader_id) {

        glDetachShader(this->get_id(), shader_id);

    }

    void Program::detach (Shader shader) {

        this->detach(shader.get_id());

    }

    void Program::link() {

        if (!this->is_created) throw std::runtime_error("Error: Failed to link a program with a invalid ID (not created program)!");

        glLinkProgram(this->get_id());

        // Checks if there is any log message for linking and print it.
        int log_message_length;
	    glGetProgramiv(this->get_id(), GL_INFO_LOG_LENGTH, &log_message_length);
        if (log_message_length > 1) {

            std::string log_message;
            log_message.resize(log_message_length);
            glGetProgramInfoLog(this->get_id(), log_message_length, nullptr, log_message.data());
            std::cout << "GLSL linker (program " << this->get_id() << "): " << log_message << std::endl;

        }

        // Checks if the program was linked correctly.
        GLint linking_status = GL_FALSE;
        glGetProgramiv(this->get_id(), GL_LINK_STATUS, &linking_status);
        if (!linking_status) {

            this->destroy();
            throw std::runtime_error(std::string("GLSL linker (program " + std::to_string(this->get_id()) + "): Failed to link the program!"));

        }

    }

    void Program::use() const {

        glUseProgram(this->get_id());

    }

    void Program::destroy () {

        if (this->is_created) glDeleteProgram(this->get_id());
        this->is_created = false;

    }

}