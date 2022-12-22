#include"VertexArray.h"

// Constructor that generates a VertexArray ID
VertexArray::VertexArray()
{
	glGenVertexArrays(1, &ID);
}

// Links a VertexBuffer to the VertexArray using a certain layout
void VertexArray::LinkAttrib(VertexBuffer& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

// Binds the VertexArray
void VertexArray::Bind()
{
	glBindVertexArray(ID);
}

// Unbinds the VertexArray
void VertexArray::Unbind()
{
	glBindVertexArray(0);
}

// Deletes the VertexArray
void VertexArray::Delete()
{
	glDeleteVertexArrays(1, &ID);
}