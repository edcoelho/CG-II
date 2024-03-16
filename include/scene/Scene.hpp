#ifndef SCENE_SCENE_HPP
#define SCENE_SCENE_HPP

#include "scene/Camera.hpp"

namespace scene{

class Scene {

    private:

        scene::Camera camera;
        
    public:

        // --- CONSTRUTORES ---

        Scene(scene::Camera& camera);

        // --- GETTERS E SETTERS ---

        // Retorna uma referência para a câmera da cena.
        scene::Camera& get_camera();
        void set_camera(scene::Camera c);

        // --- OUTROS MÉTODOS ---

};

}

#endif