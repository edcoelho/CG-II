#include "scene/Window.hpp"

scene::Window::Window(std::size_t _width, std::size_t _height, cyColorA _clear_color, std::string _title) : width(_width), height(_height), clear_color(_clear_color), title(_title) {

    glutInitWindowSize(_width, _height);
    glutInitWindowPosition(100, 100);
    this->id = glutCreateWindow(_title.c_str());
    glClearColor(_clear_color.r, _clear_color.g, _clear_color.b, _clear_color.a);

}

std::size_t scene::Window::get_width() const {

    return this->width;

}
void scene::Window::set_width(std::size_t w) {

    this->width = w;
    glutReshapeWindow(w, this->get_height());

}

std::size_t scene::Window::get_height() const {

    return this->height;

}
void scene::Window::set_height(std::size_t h) {

    this->height = h;
    glutReshapeWindow(this->get_width(), h);

}

cyColorA scene::Window::get_clear_color() const {

    return this->clear_color;

}
void scene::Window::set_clear_color(cyColorA c) {

    this->clear_color = c;
    glClearColor(c.r, c.g, c.b, c.a);

}

std::string scene::Window::get_title() const {

    return this->title;

}
void scene::Window::set_title(std::string t) {

    this->title = t;

}

GLuint scene::Window::get_id() const {

    return this->id;

}