#ifndef PLOTTER_HPP
#define PLOTTER_HPP

#include <cstring>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "dynplot/shader.hpp"

class Plotter {
public:
    Plotter(double* data_max, double* data_min, int num_plot);

    void Plot();

    void SetData(double* data, double time);

    ~Plotter();

protected:
    std::vector<glm::vec3> back_coord;
    std::vector<glm::vec3> back_color;

    std::vector<glm::vec3> coords1;
    std::vector<glm::vec3> coords2;
    std::vector<glm::vec3> coords3;

    std::vector<glm::vec3> colors1;
    std::vector<glm::vec3> colors2;
    std::vector<glm::vec3> colors3;

    int num_window;

    double *max, *min;
    double max_time;
    int index;

    double WIN_MAX, WIN_MIN;

    glm::mat4 posPlot;

    enum {
        POSITION,

        COLOR,

        NUM_BUFFERS
    };

    enum {
        BACKGROUND,

        DATA1,

        DATA2,

        DATA3,

        MAX
    };

    GLuint m_vertexArrayObject[MAX];

    GLuint m_vertexArrayBuffers[NUM_BUFFERS];

    Shader GraphShader;

private:
    double Resize(double current_data, double max_data, double min_data, double max_win, double min_win);
};

#endif // PLOTTER_HPP