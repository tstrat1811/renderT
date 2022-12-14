#ifndef ElementBuffer_H
#define ElementBuffer_H

#include<glad.h>

class ElementBuffer{
    public:
        //ID of Element buffer object
        GLuint ID;
        //Generates EBO and links to indices
        ElementBuffer(GLuint* indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
};
#endif