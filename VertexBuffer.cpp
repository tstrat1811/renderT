#include "VertexBuffer.h"
#include<vector>

//Constructor that takes in the ID declared in header file, and changes it to 
//point to the buffer, then you can bind it by passing that ID to glBindBuffer
//Then pass the buffer data of what type, the size of the buffer, the data, and the draw call
VertexBuffer::VertexBuffer(std::vector<Vertex> &vertices){
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VertexBuffer::Bind(){
    glBindBuffer(GL_ARRAY_BUFFER,ID);
}

void VertexBuffer::Unbind(){
    glBindBuffer(GL_ARRAY_BUFFER,0);
}

void VertexBuffer::Delete(){
    glDeleteBuffers(1, &ID);
}