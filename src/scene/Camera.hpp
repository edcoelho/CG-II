#ifndef CGII_CAMERA_HPP
#define CGII_CAMERA_HPP

#include "cyCodeBase/cyVector.h"
#include "cyCodeBase/cyMatrix.h"
#include "glm/glm.hpp"

namespace cgII {

    enum projection {

        ORTHOGRAPHIC,
        PERSPECTIVE

    };

class Camera {

    private:

        glm::vec3 position;
        glm::vec3 look_at;
        glm::vec3 view_up; // View-up point in view space
        projection projection_type;
        float near, far, bottom, top, left, right;

    public:

        Camera(glm::vec3 _position = glm::vec3(0.0), glm::vec3 _look_at = glm::vec3(0.0, 0.0, 1.0), glm::vec3 _view_up = glm::vec3(0.0, 1.0, 0.0), projection _projection_type = cgII::projection::ORTHOGRAPHIC, float _near = -0.1, float _far = -1000.0, float _bottom = -500.0, float _top = 500.0, float _left = -500.0, float _right = 500.0);

        glm::vec3 get_position() const;
        void set_position(glm::vec3 _position);

        glm::vec3 get_look_at() const;
        void set_look_at(glm::vec3 _look_at);

        glm::vec3 get_view_up() const;
        void set_view_up(glm::vec3 _view_up);

        projection get_projection_type() const;
        void set_projection_type(cgII::projection _projection_type);

        float get_near() const;
        void set_near(float _near);

        float get_far() const;
        void set_far(float _far);

        float get_bottom() const;
        void set_bottom(float _bottom);

        float get_top() const;
        void set_top(float _top);

        float get_left() const;
        void set_left(float _left);

        float get_right() const;
        void set_right(float _right);

        // Compute the projection matrix.
        // ATENTION: Returns a column-major matrix, as this is how GLM and GLSL stores matrices.
        glm::mat4 projection_matrix () const;

        // Compute the view matrix (world to camera transformation matrix).
        // ATENTION: Returns a column-major matrix, as this is how GLM and GLSL stores matrices.
        glm::mat4 view_matrix () const;

};

}

#endif
