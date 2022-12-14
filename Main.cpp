#include<iostream>
#include<glad.h>
#include<GLFW/glfw3.h>
#include <math.h>
#include"shaderclass.h"
#include"VertexArray.h"
#include"VertexBuffer.h"
#include"ElementBuffer.h"
#include"stb_image.h"
#include"Texture.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"Camera.h"

using namespace std;

const unsigned int width = 800;
const unsigned int height = 800;
/* COLORS
(0.0f,0.0f,0.0f) - black
(0.5f,0.5f,0.5f) - gray
(0.0f,1.0f,0.0f) - green
(0.0f,1.0f,1.0f) - cyan
(1.0f,0.5f,0.0f) - orange
(1.0f,0.0f,0.0f) - red
(1.0f,1.0f,0.0f) - yellow
*/




// To compile run g++ Main.cpp glad.c ElementBuffer.cpp shaderclass.cpp VertexArray.cpp VertexBuffer.cpp stb.cpp Texture.cpp Camera.cpp -ldl -lglfw
int main(){

    //Initialize GLFW and tell it what version of OpenGL is being used
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 
// Vertices coordinates
GLfloat vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	-0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
	 0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
	 0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f
};

// Indices for vertices order
GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
};

    //Create window of 800 x 800 with name of "Testing stuff"
    GLFWwindow* window = glfwCreateWindow(width,height, "Testing stuff",0,0);
   
    //Error handling if window fail to create
    if(window == NULL){
        std::cout<<"Failed to make da window \n";
        glfwTerminate();
        return -1;
    }

    //Make the new window the current context
    glfwMakeContextCurrent(window);

    //Load GLAD to configure OpenGL
    gladLoadGL();
    //Set viewport to go from (0,0) to (800,800)
    glViewport(0,0,width,height);

    //Loader shader with the following vert and frag files
    Shader shaderProgram("default.vert","default.frag");

    //Create a VAO and bind it
    VertexArray vertexArray;
    vertexArray.Bind();
    
    //Create VBO and EBO and link vertices and indices to them... Constructor also binds them
    VertexBuffer vertexBuffer(vertices, sizeof(vertices));
    ElementBuffer elementBuffer(indices, sizeof(indices));
    //Link the VBO attributes (coordinates, colors, textures) to VAO
    vertexArray.LinkAttrib(vertexBuffer,0,3,GL_FLOAT, 8*sizeof(float),(void*)0);
    vertexArray.LinkAttrib(vertexBuffer,1,3,GL_FLOAT, 8*sizeof(float),(void*)(3*sizeof(float)));
    vertexArray.LinkAttrib(vertexBuffer,2,2,GL_FLOAT, 8*sizeof(float),(void*)(6*sizeof(float)));
    vertexArray.Unbind();
    vertexBuffer.Unbind();
    elementBuffer.Unbind();
   
    //Load texture
    Texture testTex("water.png",GL_TEXTURE_2D,GL_TEXTURE0,GL_RGBA,GL_UNSIGNED_BYTE);
    testTex.texUnit(shaderProgram, "tex0",0);

    Camera camera(width, height, glm::vec3(0.0f,0.0f,2.0f));

    glEnable(GL_DEPTH_TEST);

    //MAIN LOOP 
    while(!glfwWindowShouldClose(window)){
        //Color of background
        glClearColor(0.5f,0.5f,0.5f, 1.0f);
        //Clears the back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Sets shaderProgram as the what OpenGl will sue
        shaderProgram.Activate();  
        camera.Inputs(window);
        camera.Matrix(45.0f,0.1f,100.0f,shaderProgram,"camMatrix");
        //Bind texture
        testTex.Bind();
        //Sets vertexArray to the one OpenGl will use
        vertexArray.Bind();
        //Draw triangles, number of indices, their datatypes and indexes
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT,0);
        //Set back buffer to front buffer
        glfwSwapBuffers(window);
        //Track GLFW Events
        glfwPollEvents();
    }

    //Delete objects we created
    vertexArray.Delete();
    vertexBuffer.Delete();
    elementBuffer.Delete();
    shaderProgram.Delete();
    testTex.Delete();
    //Delete the window
    glfwDestroyWindow(window);
    //Terminate glfw
    glfwTerminate();

    return 0;
}