#include"Mesh.h"

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


// Vertices coordinates
Vertex vertices[] =
{ //     COORDINATES     /        COLORS      /   TexCoord  //
	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(5.0f, 0.0f)},
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(0.0f, 0.0f)},
	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f),     glm::vec3(0.83f, 0.70f, 0.44f),	glm::vec2(5.0f, 0.0f)},
	Vertex{glm::vec3( 0.0f, 0.8f,  0.0f),     glm::vec3(0.92f, 0.86f, 0.76f),	glm::vec2(2.5f, 5.0f)}
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

// To compile run g++ Main.cpp glad.c ElementBuffer.cpp shaderclass.cpp VertexArray.cpp VertexBuffer.cpp stb.cpp Texture.cpp Camera.cpp Mesh.cpp -ldl -lglfw
int main(){

    //Initialize GLFW and tell it what version of OpenGL is being used
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 
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

    Texture textures[]{
    //Load texture
    Texture("water.png", GL_TEXTURE_2D, 0, GL_RGBA ,GL_UNSIGNED_BYTE)
    };

    //Loader shader with the following vert and frag files
    Shader shaderProgram("default.vert","default.frag");    

    std::vector <Vertex> verts(vertices, vertices + sizeof(vertices) / sizeof(Vertex));
	std::vector <GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));
	std::vector <Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));
	Mesh mainMesh(verts, ind, tex);
    
    Camera camera(width, height, glm::vec3(0.0f,0.0f,2.0f));

    glEnable(GL_DEPTH_TEST);

    //MAIN LOOP 
    while(!glfwWindowShouldClose(window)){
        //Color of background
        glClearColor(1.0f,0.5f,0.0f,1.0f);
        //Clears the back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Sets shaderProgram as the what OpenGl will sue
        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);
        //Bind texture
        mainMesh.Draw(shaderProgram, camera);
    
        //Set back buffer to front buffer
        glfwSwapBuffers(window);
        //Track GLFW Events
        glfwPollEvents();
    }

    //Delete objects we created
    shaderProgram.Delete();
    //Delete the window
    glfwDestroyWindow(window);
    //Terminate glfw
    glfwTerminate();

    return 0;
}