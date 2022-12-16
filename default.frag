//Fragment shader (pixel shader) is ran each time for each pixel

#version 460 core
out vec4 FragColor;

//takes in color and texture from vert shader
in vec3 color;

in vec2 texCoord;

uniform sampler2D tex0;

void main()
{
   FragColor = texture(tex0, texCoord);
};