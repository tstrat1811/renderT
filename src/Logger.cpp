#include "Logger.h"


void Logger::GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

void Logger::GLCheckError(){
    while(GLenum error = glGetError()){
        std::cout<<"[!!! Error Detected !!! (" << error <<")"<<std::endl;
    }
}

void Logger::FramesLog(float red){
    i++;
    std::string tmp;
    if (red <0.4f){
        tmp = "<(^.^<(";
    }
    else if (0.4f <= red & red <0.7f){
        tmp = "<(^.^)>";
    }
    else if (0.7f <= red){
        tmp = ")>^.^)>";
    }
    std::cout<<i<<"   "<<tmp<<::std::endl;
}

