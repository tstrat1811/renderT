#ifndef Logger_CLASS_H
#define Logger_CLASSH_H

#include <glad.h>
#include <iostream>
#include<chrono>

class Logger{
    public:
        int i = 0;
        void GLClearError();
        void GLCheckError();
        void FramesLog();
};

#endif