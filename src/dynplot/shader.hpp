#ifndef SHADER_HPP
#define SHADER_HPP

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "dynplot/camera.hpp"
#include "dynplot/light.hpp"
#include "dynplot/model.hpp"

class Shader {
public:
    Shader();

    Shader(const std::string& vertexPath, const std::string& fragmentPath);

    virtual ~Shader();

    inline GLuint GetShader() { return m_program; }
    inline GLuint GetUniform(int num) { return m_uniforms[num]; }

    void SetShader(const std::string& vertexPath, const std::string& fragmentPath);

    void Bind();

    void Update(Model& State, Camera& Cam, Light& Lamp);

    static GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

protected:
private:
    enum {
        MODEL,

        VIEW,

        MVP,

        LIGHTPOS,

        GSAMPLER,

        NUM_UNIFORMS
    };

    GLuint m_program;

    GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_HPP