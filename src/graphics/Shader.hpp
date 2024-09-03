#ifndef CGII_SHADER_HPP_
#define CGII_SHADER_HPP_

#include <GL/glew.h>
#include <string>

namespace cgII {

    class Shader {

        private:

            GLuint id;
            GLenum type;

            bool is_compiled;

        public:

            Shader (GLenum _type = GL_VERTEX_SHADER);
            ~Shader ();

            GLuint get_id () const;
            GLenum get_type () const;

            // Compiles the shader from a file.
            void compile (const std::string source_path);
            // Deletes the shader.
            void destroy ();

    };

}

#endif