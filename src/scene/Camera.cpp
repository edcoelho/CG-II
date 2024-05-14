#include "scene/Camera.hpp"

// --- MÉTODOS PRIVADOS ---

void scene::Camera::compute_projection_matrix() {

    this->projection_matrix.SetIdentity();

    if (this->get_projection_type() == scene::ProjectionType::PERSPECTIVE) {

        this->projection_matrix(0, 0) = 2.0 * this->get_near() / (this->get_right() - this->get_left());
        this->projection_matrix(0, 2) = -(this->get_right() + this->get_left()) / (this->get_right() - this->get_left());

        this->projection_matrix(1, 1) = 2.0 * this->get_near() / (this->get_top() - this->get_bottom());
        this->projection_matrix(1, 2) = -(this->get_top() + this->get_bottom()) / (this->get_top() - this->get_bottom());

        this->projection_matrix(2, 2) = (this->get_far() + this->get_near()) / (this->get_far() - this->get_near());
        this->projection_matrix(2, 3) = -2.0 * this->get_near() * this->get_far() / (this->get_far() - this->get_near());

        this->projection_matrix(3, 2) = 1.0;
        this->projection_matrix(3, 3) = 0.0;

    } else {

        this->projection_matrix(0, 0) = 2.0 / (this->get_right() - this->get_left());
        this->projection_matrix(0, 3) = -(this->get_right() + this->get_left()) / (this->get_right() - this->get_left());

        this->projection_matrix(1, 1) = 2.0 / (this->get_top() - this->get_bottom());
        this->projection_matrix(1, 3) = -(this->get_top() + this->get_bottom()) / (this->get_top() - this->get_bottom());

        this->projection_matrix(2, 2) = 2.0 / (this->get_far() - this->get_near());
        this->projection_matrix(2, 3) = -(this->get_far() + this->get_near()) / (this->get_far() - this->get_near());

    }

}

// --- CONSTRUTORES ---

scene::Camera::Camera(cyVec3d _position, cyVec3d _look_at, cyVec3d _view_up, ProjectionType _projection_type, double _near, double _far, double _bottom, double _top, double _left, double _right) : position(_position), look_at(_look_at), view_up(_view_up), projection_type(_projection_type), near(_near), far(_far), bottom(_bottom), top(_top), left(_left), right(_right) {

    this->view_matrix.SetView(_position, _look_at, _view_up);
    this->compute_projection_matrix();

}

cyVec3d scene::Camera::get_position() const {

    return this->position;

}
void scene::Camera::set_position(cyVec3d pos, bool update_view_matrix) {

    this->position = pos;
    if (update_view_matrix) this->view_matrix.SetView(pos, this->get_look_at(), this->get_view_up());

}

cyVec3d scene::Camera::get_look_at() const {

    return this->look_at;

}
void scene::Camera::set_look_at(cyVec3d pos, bool update_view_matrix) {

    this->look_at = pos;
    if (update_view_matrix) this->view_matrix.SetView(this->get_position(), pos, this->get_view_up());

}

cyVec3d scene::Camera::get_view_up() const {

    return this->view_up;

}
void scene::Camera::set_view_up(cyVec3d pos, bool update_view_matrix) {

    this->view_up = pos;
    if(update_view_matrix) this->view_matrix.SetView(this->get_position(), this->get_look_at(), pos);

}

scene::ProjectionType scene::Camera::get_projection_type() const {

    return this->projection_type;

}
void scene::Camera::set_projection_type(scene::ProjectionType type, bool update_projection_matrix) {

    this->projection_type = type;
    if (update_projection_matrix) this->compute_projection_matrix();

}

double scene::Camera::get_near() const {

    return this->near;

}
void scene::Camera::set_near(double scalar, bool update_projection_matrix) {

    this->near = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();

}

double scene::Camera::get_far() const {

    return this->far;

}
void scene::Camera::set_far(double scalar, bool update_projection_matrix) {

    this->far = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();

}

double scene::Camera::get_bottom() const {

    return this->bottom;

}
void scene::Camera::set_bottom(double scalar, bool update_projection_matrix) {

    this->bottom = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();

}

double scene::Camera::get_top() const {

    return this->top;

}
void scene::Camera::set_top(double scalar, bool update_projection_matrix) {

    this->top = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();


}

double scene::Camera::get_left() const {

    return this->left;

}
void scene::Camera::set_left(double scalar, bool update_projection_matrix) {

    this->left = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();


}

double scene::Camera::get_right() const {

    return this->right;

}
void scene::Camera::set_right(double scalar, bool update_projection_matrix) {

    this->right = scalar;
    if (update_projection_matrix) this->compute_projection_matrix();

}

cyMatrix4d const& scene::Camera::get_view_matrix() const {

    return this->view_matrix;

}

cyMatrix4d const& scene::Camera::get_projection_matrix() const {

    return this->projection_matrix;

}