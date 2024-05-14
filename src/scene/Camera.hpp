#ifndef SCENE_CAMERA_HPP
#define SCENE_CAMERA_HPP

#include "cyCodeBase/cyVector.h"
#include "cyCodeBase/cyMatrix.h"

namespace scene {

enum ProjectionType {

    ORTHOGRAPHIC,
    PERSPECTIVE

};

class Camera {

    private:

        // Posição da câmera em coordenadas de mundo.
        cyVec3d position;
        // Ponto para o qual a câmera está olhando.
        cyVec3d look_at;
        // Ponto que amarra o plano sargital da câmera.
        cyVec3d view_up;
        // Tipo de projeção da câmera.
        ProjectionType projection_type;
        // Limites do view space em coordenadas de câmera.
        double near, far, bottom, top, left, right;

        // Matriz da view transformation (mudança de coordenadas de mundo para câmera).
        cyMatrix4d view_matrix;
        // Matriz da projection transformation.
        cyMatrix4d projection_matrix;

        // Método privado para calcular a matriz de projeção.
        void compute_projection_matrix();

    public:

        // --- CONSTRUTORES ---

        Camera(cyVec3d _position = cyVec3d(0.0), cyVec3d _look_at = cyVec3d(0.0, 0.0, 1.0), cyVec3d _view_up = cyVec3d(0.0, 1.0, 0.0), ProjectionType _projection_type = scene::ProjectionType::ORTHOGRAPHIC, double _near = 0.1, double _far = 1000.0, double _bottom = -500.0, double _top = 500.0, double _left = -500.0, double _right = 500.0);

        // --- GETTERS E SETTERS ---

        cyVec3d get_position() const;
        void set_position(cyVec3d pos, bool update_view_matrix = true);

        cyVec3d get_look_at() const;
        void set_look_at(cyVec3d pos, bool update_view_matrix = true);

        cyVec3d get_view_up() const;
        void set_view_up(cyVec3d pos, bool update_view_matrix = true);

        ProjectionType get_projection_type() const;
        void set_projection_type(scene::ProjectionType type, bool update_projection_matrix = true);

        double get_near() const;
        void set_near(double scalar, bool update_projection_matrix = true);

        double get_far() const;
        void set_far(double scalar, bool update_projection_matrix = true);

        double get_bottom() const;
        void set_bottom(double scalar, bool update_projection_matrix = true);

        double get_top() const;
        void set_top(double scalar, bool update_projection_matrix = true);

        double get_left() const;
        void set_left(double scalar, bool update_projection_matrix = true);

        double get_right() const;
        void set_right(double scalar, bool update_projection_matrix = true);

        cyMatrix4d const& get_view_matrix() const;

        cyMatrix4d const& get_projection_matrix() const;

        // --- OUTROS MÉTODOS ---

};

}

#endif
