#include "Mesh.h"

Mesh::Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures)
{
	Mesh::vertices = vertices;
	Mesh::indices = indices;
	Mesh::textures = textures;

	vertexArray.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VertexBuffer vertexBuffer(vertices);
	//Generates Element Buffer Object and links it to indices (VAO has to be bound first)
	ElementBuffer elementBuffer(indices);
	// Links vertexBuffer attributes such as coordinates and colors to vertexArray
	//Specify the index (i.e. 0 for position)
	vertexArray.LinkAttrib(vertexBuffer,0,3,GL_FLOAT, 8*sizeof(float),(void*)0);
    vertexArray.LinkAttrib(vertexBuffer,1,3,GL_FLOAT, 8*sizeof(float),(void*)(3*sizeof(float)));
    vertexArray.LinkAttrib(vertexBuffer,2,2,GL_FLOAT, 8*sizeof(float),(void*)(6*sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	elementBuffer.Unbind();
}

void Mesh::Draw
(
	Shader& shader, 
	Camera& camera,
	glm::mat4 matrix,
	glm::vec3 translation, 
	glm::quat rotation, 
	glm::vec3 scale
)
{
    shader.Activate();
    vertexArray.Bind();
    textures[0].texUnit(shader, "tex0",0);
    textures[0].Bind();
    glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	//Draw call, draws triangles, how many indices we are using
	//Type being used in index buffer (EBO), and pointer to index buffer (can be 0 since it's bound arleady)
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glUniform3f(glGetUniformLocation(shader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
	camera.Matrix(shader, "camMatrix");

	//Initialize matrices
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 sca = glm::mat4(1.0f);

	// Transform the matrices to their correct form
	trans = glm::translate(trans, translation);
	rot = glm::mat4_cast(rotation);
	sca = glm::scale(sca, scale);

	// Push the matrices to the vertex shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "translation"), 1, GL_FALSE, glm::value_ptr(trans));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "rotation"), 1, GL_FALSE, glm::value_ptr(rot));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "scale"), 1, GL_FALSE, glm::value_ptr(sca));
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(matrix));

	// Draw the actual mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}