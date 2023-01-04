# renderT
renderT is a low level, barebones rendering engine made in c++ adhering to latest OpenGL (4.6) specs. Complete with movable camera, debug menu, customizable background

-Currently only some .gltf files are compatible
-Credits to the following Open source files / libs
-- GLFW (Cross platform Windowing library used to create the window)
-- GLAD (OpenGL Loader used for function pointers)
-- Json.h (Json reader used for model loading [niolmann]) 
-- (modified) Camera.cpp, (modified) Model.cpp [Victor Gordon]
-- stb_image lib (Open source library to help with loading images for texture)

![alt text](https://github.com/tstrat1811/renderT/blob/master/renderT.png?raw=true)

Before Compiling Place the following files in your include directory  
- GLFW (folder)  
- glad.h (file)  
- glm (folder)

To compile for linux --  

1.) Open a terminal in the /src directory  
2.) Run "make"  
3.) Run the executable with "./renderT"  

To compile for other platforms --
1.) Not entirely sure but this was made with portability in mind using cross platform libraries so should be somewhat easy

For details on how this works please refer to "renderT walkthrough.pdf"
===============================================================================