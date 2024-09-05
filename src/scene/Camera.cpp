#include "scene/Camera.hpp"

namespace cgII {

    Camera::Camera(glm::vec3 _position, glm::vec3 _look_at, glm::vec3 _view_up, projection _projection_type, float _near, float _far, float _bottom, float _top, float _left, float _right) : position(_position), look_at(_look_at), view_up(_view_up), projection_type(_projection_type), near(_near), far(_far), bottom(_bottom), top(_top), left(_left), right(_right) {}

    glm::vec3 Camera::get_position() const {

        return this->position;

    }
    void Camera::set_position(glm::vec3 _position) {

        this->position = _position;

    }

    glm::vec3 Camera::get_look_at() const {

        return this->look_at;

    }
    void Camera::set_look_at(glm::vec3 _look_at) {

        this->look_at = _look_at;

    }

    glm::vec3 Camera::get_view_up() const {

        return this->view_up;

    }
    void Camera::set_view_up(glm::vec3 _view_up) {

        this->view_up = _view_up;

    }

    projection Camera::get_projection_type() const {

        return this->projection_type;

    }
    void Camera::set_projection_type(projection _projection_type) {

        this->projection_type = _projection_type;

    }

    float Camera::get_near() const {

        return this->near;

    }
    void Camera::set_near(float _near) {

        this->near = _near;

    }

    float Camera::get_far() const {

        return this->far;

    }
    void Camera::set_far(float _far) {

        this->far = _far;

    }

    float Camera::get_bottom() const {

        return this->bottom;

    }
    void Camera::set_bottom(float _bottom) {

        this->bottom = _bottom;

    }

    float Camera::get_top() const {

        return this->top;

    }
    void Camera::set_top(float _top) {

        this->top = _top;

    }

    float Camera::get_left() const {

        return this->left;

    }
    void Camera::set_left(float _left) {

        this->left = _left;


    }

    float Camera::get_right() const {

        return this->right;

    }
    void Camera::set_right(float _right) {

        this->right = _right;

    }

    // The returned matrix is stored in column-major for, as this is how GLM and GLSL store matrices.
    glm::mat4 Camera::projection_matrix () const {

        glm::vec4 col0, col1, col2, col3;

        if (this->get_projection_type() == PERSPECTIVE) {

            col0 = glm::vec4(
                (2.0f * near) / (right - left),
                0.0f,
                0.0f, 
                0.0f
            );

            col1 = glm::vec4(
                0.0f,
                (2.0f * near) / (top - bottom),
                0.0f,
                0.0f
            );

            col2 = glm::vec4(
                (right + left) / (right - left),
                (top + bottom) / (top - bottom),
                -(far + near) / (far - near),
                -1.0f
            );

            col3 = glm::vec4(
                0.0f,
                0.0f,
                -(2.0f * far * near) / (far - near),
                0.0f
            );

        } else {

            col0 = glm::vec4(
                2.0f / (right - left),
                0.0f,
                0.0f,
                0.0f
            );

            col1 = glm::vec4(
                0.0f,
                2.0f / (top - bottom),
                0.0f,
                0.0f
            );

            col2 = glm::vec4(
                0.0f,
                0.0f,
                2.0f / (far - near),
                0.0f
            );

            col3 = glm::vec4(
                -(right + left) / (right - left),
                -(top + bottom) / (top - bottom),
                -(far + near) / (far - near),
                1.0f
            );

        }

        return glm::mat4(col0, col1, col2, col3);

    }

    // The returned matrix is stored in column-major for, as this is how GLM and GLSL store matrices.
    glm::mat4 Camera::view_matrix () const {

        glm::mat4 matrix(1.0f);
        glm::vec3 camera_x_axis, camera_y_axis, camera_z_axis;

        camera_z_axis = position - look_at;
        camera_z_axis = glm::normalize(camera_z_axis);

        camera_x_axis = glm::cross(view_up, camera_z_axis); // view_up is defined in view/camera space
        camera_x_axis = glm::normalize(camera_x_axis);

        camera_y_axis = glm::cross(camera_z_axis, camera_x_axis);
        camera_y_axis = glm::normalize(camera_y_axis);
        
        for (int i = 0; i < 3; i++) {

            matrix[i][0] = camera_x_axis[i];
            matrix[i][1] = camera_y_axis[i];
            matrix[i][2] = camera_z_axis[i];

        }

        matrix[3][0] = -glm::dot(camera_x_axis, position);
        matrix[3][1] = -glm::dot(camera_y_axis, position);
        matrix[3][2] = -glm::dot(camera_z_axis, position);

        return matrix;

    }

}