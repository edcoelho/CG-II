#include "scene/Scene.hpp"

namespace cgII {

    Camera& Scene::get_camera() {

        return this->camera;

    }
    void Scene::set_camera(Camera c) {

        this->camera = c;

    }

}