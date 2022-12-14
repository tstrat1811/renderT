
#version 460 core
//Positions / Coordinates
layout (location = 0) in vec3 aPos;
//Colors
layout (location = 1) in vec3 aColor;
//Texture Coordinates
layout (location = 2) in vec2 aTex;

//Outputs color and texture to fragment shader
out vec3 color;
out vec2 texCoord;

//Scale of vertices
uniform float scale;

uniform mat4 camMatrix;

void main()
{
   gl_Position = camMatrix * vec4(aPos, 1.0);
   color = aColor;
   texCoord = aTex;
};