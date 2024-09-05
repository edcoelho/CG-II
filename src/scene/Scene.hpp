#ifndef CGII_SCENE_HPP
#define CGII_SCENE_HPP

#include "scene/Camera.hpp"

namespace cgII{

class Scene {

    private:

        cgII::Camera camera;
        
    public:

        Scene(cgII::Camera& camera);

        cgII::Camera& get_camera();
        void set_camera(cgII::Camera c);

};

}

#endif