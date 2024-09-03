#ifndef CGII_CGII_HPP
#define CGII_CGII_HPP

#include "scene/Camera.hpp"

namespace cgII{

class Scene {

    private:

        cgII::Camera camera;
        
    public:

        // --- CONSTRUTORES ---

        Scene(cgII::Camera& camera);

        // --- GETTERS E SETTERS ---

        // Retorna uma referência para a câmera da cena.
        cgII::Camera& get_camera();
        void set_camera(cgII::Camera c);

        // --- OUTROS MÉTODOS ---

};

}

#endif