#include "Mesh.h"

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures)
{
	Mesh::vertices = vertices;
	Mesh::indices = indices;
	Mesh::textures = textures;

	vertexArray.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VertexBuffer vertexBuffer(vertices);
	// Generates Element Buffer Object and links it to indices
	ElementBuffer elementBuffer(indices);
	// Links vertexBuffer attributes such as coordinates and colors to vertexArray
	vertexArray.LinkAttrib(vertexBuffer,0,3,GL_FLOAT, 8*sizeof(float),(void*)0);
    vertexArray.LinkAttrib(vertexBuffer,1,3,GL_FLOAT, 8*sizeof(float),(void*)(3*sizeof(float)));
    vertexArray.LinkAttrib(vertexBuffer,2,2,GL_FLOAT, 8*sizeof(float),(void*)(6*sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	elementBuffer.Unbind();
}

void Mesh::Draw(Shader& shader, Camera& camera){
    shader.Activate();
    vertexArray.Bind();
    textures[0].texUnit(shader, "tex0",0);
    textures[0].Bind();
    glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}