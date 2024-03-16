#include "scene/Scene.hpp"

scene::Camera& scene::Scene::get_camera() {

    return this->camera;

}
void scene::Scene::set_camera(scene::Camera c) {

    this->camera = c;

}