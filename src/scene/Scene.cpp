#include "scene/Scene.hpp"

cgII::Camera& cgII::Scene::get_camera() {

    return this->camera;

}
void cgII::Scene::set_camera(cgII::Camera c) {

    this->camera = c;

}