#ifndef CGII_PROGRAM_HPP_
#define CGII_PROGRAM_HPP_

#include <GL/glew.h>
#include "graphics/Shader.hpp"
#include <vector>

namespace cgII {

    class Program {

        private:

            GLuint id;

            bool is_created;

        public:

            Program ();
            ~Program ();

            GLuint get_id () const;

            // Attachs a shader to the program.
            void attach (GLuint shader_id);
            // Attachs a shader to the program.
            void attach (Shader shader);

            // Detachs a shader from the program.
            // It is a good idea to detach all shaders objects after linking it.
            void detach (GLuint shader_id);
            // Detachs a shader from the program.
            // It is a good idea to detach all shaders objects after linking it.
            void detach (Shader shader);

            // Links the program.
            // The shaders must be attached before calling this.
            void link();

            // Bind the program to be used.
            void use() const;

            // Deletes the program.
            void destroy ();

    };

}

#endif