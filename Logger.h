#ifndef Logger_CLASS_H
#define Logger_CLASSH_H

#include <glad.h>
#include <iostream>

class Logger{
    public:
        void GLClearError();
        void GLCheckError();
};

#endif