#ifndef Logger_CLASS_H
#define Logger_CLASSH_H

#include <glad.h>
#include <iostream>

class Logger{
    public:
        int i = 0;
        void GLClearError();
        void GLCheckError();
        void FramesLog(float red);
};

#endif