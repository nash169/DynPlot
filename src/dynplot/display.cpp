#include "dynplot/display.hpp"

Display::Display(const std::string& title, int width, int height)
{
    x = width;
    y = height;

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For Mac ??
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    if (m_window == NULL) {
        std::cerr << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
    }

    // Define the viewport dimensions ?? ..didn't realy get what it needs for so far..
    // glViewport(0, 0, width, height);

    // Set OpenGL options
    glEnable(GL_CULL_FACE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
    m_isClosed = false;
    record = false;
}

Display::Display() {}

Display::~Display()
{
    if (record)
        pclose(ffmpeg);

    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Display::Clear(float r, float b, float g, float a)
{
    glfwMakeContextCurrent(m_window);
    glClearColor(r, b, g, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::Update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();

    if (record) {
        glReadPixels(0, 0, x, y, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
        fwrite(buffer, sizeof(int) * x * y, 1, ffmpeg);
    }

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS || glfwWindowShouldClose(m_window) != 0)
        m_isClosed = true;
}

bool Display::isClosed() { return m_isClosed; }

void Display::SetRecorder(const std::string& savePath)
{
    buffer = new int[x * y];
    int dummy = asprintf(&fname, "%dx%d", x, y);
    std::string res = fname;

    std::string cmd = "ffmpeg -r 60 -f rawvideo -pix_fmt rgba -s " + res + " -i - -threads 0 -preset fast -y -pix_fmt yuv420p -crf 21 -vf vflip " + savePath;
    ffmpeg = popen(cmd.c_str(), "w");
    record = true;
}
