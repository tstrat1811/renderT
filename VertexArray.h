#ifndef VertexArray_H
#define VertexArray_H

#include<glad.h>
#include"VertexBuffer.h"

class VertexArray{
    public:
    //ID of VBO
    GLuint ID;
    //Generates VAO ID
    VertexArray();

    void LinkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
    void Bind();
    void Unbind();
    void Delete();
};

#endif