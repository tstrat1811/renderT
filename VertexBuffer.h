#ifndef VertexBuffer_H
#define VertexBuffer_H

#include<glad.h>

class VertexBuffer{
    public:
        //ID of the Vertext Buffer Object
        GLuint ID;
        //Generates VBO and links to vertices
        VertexBuffer(GLfloat* vertices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};
#endif