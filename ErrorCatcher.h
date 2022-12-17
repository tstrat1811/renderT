#ifndef ERRORCATCHER_CLASS_H
#define ERRORCATCHER_CLASSH_H

#include <glad.h>
#include <iostream>

class ErrorCatcher{
    public:
        void GLClearError();
        void GLCheckError();
};

#endif