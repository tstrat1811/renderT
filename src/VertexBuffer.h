#ifndef VertexBuffer_CLASS_H
#define VertexBuffer_CLASS_H

#include<glm/glm.hpp>
#include<glad.h>
#include<vector>

struct Vertex{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec2 texUV;
};

class VertexBuffer{
    public:
        //ID of the Vertext Buffer Object
        GLuint ID;
        //Generates VBO and links to vertices
        VertexBuffer(std::vector<Vertex> &vertices);

        void Bind();
        void Unbind();
        void Delete();
};
#endif