#include "Logger.h"


void Logger::GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

void Logger::GLCheckError(){
    while(GLenum error = glGetError()){
        std::cout<<"[!!! Error Detected !!! (" << error <<")"<<std::endl;
    }
}

void Logger::FramesLog(){
    i++;
    std::cout<<i<<::std::endl;
}

