#ifndef CGII_WINDOW_HPP
#define CGII_WINDOW_HPP

#include <string>
#include <GL/freeglut.h>
#include <glm/vec4.hpp>
#include "scene/Scene.hpp"

namespace cgII {

    class Window {

        private:

            std::size_t width;
            std::size_t height;
            glm::vec4 clear_color;
            std::string title;
            GLuint id;

        public:

            Window(std::size_t _width = 500, std::size_t _height = 500, glm::vec4 _clear_color = glm::vec4(0.0, 0.0, 0.0, 1.0), std::string _title = "Window");

            std::size_t get_width() const;
            void set_width(std::size_t w);

            std::size_t get_height() const;
            void set_height(std::size_t h);

            glm::vec4 get_clear_color() const;
            void set_clear_color(glm::vec4 c);

            std::string get_title() const;
            void set_title(std::string t);

            GLuint get_id() const;

    };

}

#endif