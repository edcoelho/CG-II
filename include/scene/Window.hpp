#ifndef SCENE_WINDOW_HPP
#define SCENE_WINDOW_HPP

#include <string>
#include <GL/freeglut.h>
#include "cyCodeBase/cyColor.h"
#include "scene/Scene.hpp"

namespace scene {

class Window {

    private:
        // Largura da janela
        std::size_t width;
        // Altura da janela
        std::size_t height;
        // Cor padrão da janela.
        cyColorA clear_color;
        // Título da janela
        std::string title;

        // ID da janela.
        GLuint id;

    public:

        // --- CONSTRUTORES ---

        Window(std::size_t _width = 500, std::size_t _height = 500, cyColorA _clear_color = cyColorA(0.0f, 1.0f), std::string _title = "Window");

        // --- GETTERS E SETTERS ---

        std::size_t get_width() const;
        void set_width(std::size_t w);

        std::size_t get_height() const;
        void set_height(std::size_t h);

        cyColorA get_clear_color() const;
        void set_clear_color(cyColorA c);

        std::string get_title() const;
        void set_title(std::string t);

        GLuint get_id() const;

        // --- OUTROS MÉTODOS ---

};

}

#endif