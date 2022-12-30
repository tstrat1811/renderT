#ifndef GUIHELPER_CLASS_H
#define GUIHELPER_CLASS_H
#include "./imgui/imgui.h"
#include "./imgui/imgui_impl_glfw.h"
#include "./imgui/imgui_impl_opengl3.h"
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> 
#include<iostream>

struct DebugStruct{
    float red;
    float green;
    float blue;
    bool dynamicBg;
};

class GuiHelper{
    public:
      bool show_demo_window;
      bool show_another_window;
      const char* glsl_version;
      
      
      GuiHelper(GLFWwindow* window);  

      void Display(DebugStruct& bgstruct);
      void Destroy();
     
};

#endif