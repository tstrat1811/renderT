#ifndef ElementBuffer_H
#define ElementBuffer_H

#include<glad.h>
#include<vector>

class ElementBuffer{
    public:
        //ID of Element buffer object
        GLuint ID;
        //Generates EBO and links to indices
        ElementBuffer(std::vector <GLuint> &indices);

        void Bind();
        void Unbind();
        void Delete();
};
#endif