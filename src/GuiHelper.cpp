#include "GuiHelper.h"

GuiHelper::GuiHelper(GLFWwindow* window){
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
#if defined(__APPLE__)
    // GL 3.2 + GLSL 150
    glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);   
#else
    glsl_version = "#version 130";
#endif  
    
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    ImGui::StyleColorsDark();
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

}

void GuiHelper::Display(DebugStruct& bgstruct){

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Dee Bug");                          //Create "Dee Bug" window

    ImGui::Text("Debug Menu.");               // Display some text (you can use a format strings too)
    ImGui::Checkbox("Changing Colors", &bgstruct.dynamicBg);      // Edit bools storing our window open/close state

    ImGui::SliderFloat("Red", &bgstruct.red, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
    ImGui::SliderFloat("Green", &bgstruct.green, 0.0f, 1.0f);      
    ImGui::SliderFloat("Blue", &bgstruct.blue, 0.0f, 1.0f);      

    ImGui::Text("counter = %d", counter);
    if (ImGui::Button("Cool Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    if(counter > 2){
        ImGui::BeginChild("Secret Window");
        ImGui::Text("== YOU FOUND THE SECRET");
        ImGui::EndChild();
    }

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
    ImGui::Render();
    ImGui::EndFrame();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void GuiHelper:: Destroy(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}