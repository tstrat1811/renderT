#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad.h>
#include"stb_image.h"
#include"shaderclass.h"

class Texture{

    public:
    GLuint ID;
    GLenum type;
    Texture(const char* image, GLenum texType, GLenum slot);

    void texUnit(Shader& shader, const char* uniform, GLuint unit);
    void Bind();
    void Unbind();
    void Delete();
};

#endif