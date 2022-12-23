#include"Model.h"
#include"Logger.h"

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

// To compile run g++ Main.cpp glad.cpp ElementBuffer.cpp shaderclass.cpp VertexArray.cpp VertexBuffer.cpp stb.cpp Texture.cpp Camera.cpp Mesh.cpp Model.cpp Logger.cpp -ldl -lglfw
int main(){
    
    Logger logger;
    //Initialize GLFW and tell it what version of OpenGL is being used (4.6)
    //GLFW is a library that creates windows cross platform
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 
    //Create window of 800 x 800 with name of "Testing stuff"
    GLFWwindow* window = glfwCreateWindow(width,height, "renderT by Taylor Stratford :)",0,0);
   
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

    //Shaders are simply a program that runs on the gpu, vertex shader mainly is used
    //for telling OpenGL where to create vertices, fragment is for each pixel
    Shader shaderProgram("default.vert","default.frag");    
    
    //Create array of vertices, indices, and textures
    shaderProgram.Activate();
    
    //Initialize a camera with the initial 
    Camera camera(width, height, glm::vec3(0.0f,0.0f,2.0f));

    glEnable(GL_DEPTH_TEST);
    
    Model model("../Textures/grindstone/scene.gltf"); 

    float red = 0.0f;
    bool reverseRed = false;
    //MAIN LOOP 
    while(!glfwWindowShouldClose(window)){
        //Color of background
        glClearColor(red,0.4f,0.5f,1.0f);
        //Clears the back buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Takes inputs in from window to camera         
        camera.Inputs(window);
        camera.updateMatrix(45.0f, 0.1f, 100.0f);
        logger.FramesLog(red);
        if (red >= 1.0f){reverseRed = true;}
        if (red <= 0.0f){reverseRed = false;}
        reverseRed ? red -= .005f : red += .005f;
        
        //Error catcher
        logger.GLClearError();
        //Draw the model
        model.Draw(shaderProgram, camera);

        logger.GLCheckError();
    
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