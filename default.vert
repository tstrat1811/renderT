//Vertex Shader is ran for each vertex to tell gpu where to draw triangle

//specify version
#version 460 core

//Specify that position attribute is at index 0 (should match vertexAttribPointer)
layout (location = 0) in vec3 aPos;

//Colors
layout (location = 1) in vec3 aColor;
//Texture Coordinates
layout (location = 2) in vec2 aTex;

//Outputs color and texture to fragment shader (next step in pipeline)
out vec3 color;
out vec2 texCoord;

//Scale of vertices
uniform float scale;

uniform mat4 camMatrix;

//main function for shader program
void main()
{
	//set the position equal to camera matrix 
   gl_Position = camMatrix * vec4(aPos, 1.0);
   color = aColor;
   texCoord = aTex;
};