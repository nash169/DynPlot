#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#include <cassert>
#include <iostream>

#include <GL/glew.h>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

class Texture {
public:
    Texture(const std::string& fileName);

    Texture();

    ~Texture();

    void Bind(unsigned int unit);

    inline GLuint GetTexture() { return m_texture; }

    // Custom loaders (opengl-tutorial)
    GLuint loadBMP_custom(const char* imagepath);

    GLuint loadDDS(const char* imagepath);

protected:
private:
    GLuint m_texture;
};

#endif // TEXTURE_HPP