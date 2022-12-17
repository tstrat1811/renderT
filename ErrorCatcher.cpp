#include "ErrorCatcher.h"



void ErrorCatcher::GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}

void ErrorCatcher::GLCheckError(){
    while(GLenum error = glGetError()){
        std::cout<<"[!!! Error Detected !!! (" << error <<")"<<std::endl;
    }
}
