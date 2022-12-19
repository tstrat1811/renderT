#include "../renderT/shaderclass.h"

//reads vertex files 
std::string get_file_contents(const char* filename){
    std::ifstream in(filename, std::ios::binary);
    if(in){
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0],contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile){

    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    //converts the strings to character pointer that points to first char in string
    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();
    //Creates ID that points to new vertex shader object
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    //Specifies source of shader with the shader pointer, how many source codes, 
    //the source code memory address, and null length to assume null terminated string
    glShaderSource(vertexShader,1, &vertexSource, NULL);
    //Compile Shader into machine code for the GPU
    glCompileShader(vertexShader);

    //Repeat for fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //Create shader using a reference of the fragmentshadersource var defined above
    glShaderSource(fragmentShader,1, &fragmentSource, NULL);
    //Compile Shader into machine code for the GPU
    glCompileShader(fragmentShader);
    
    //Error handling
    int result;
    
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int length;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(vertexShader, length, &length, message);
        std::cout<<"failed to compile \n";
        std::cout<<message<<std::endl;
    }

    int result2;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result2);
    if(result2 == GL_FALSE){
        int length;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(fragmentShader, length, &length, message);
        std::cout<<"failed to compile \n";
        std::cout<<message<<std::endl;
    }

    //Returns a uint that is assigned to ID that will point to the shader program
    ID = glCreateProgram();

    //Attach shaders to the program and link it, executables are made of vert and frag shaders
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    //checks to see if executables are able to be run given state of machine
    glValidateProgram(ID);

    //Delete shaders because they're already part of program now
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate(){
    glUseProgram(ID);
}

void Shader::Delete(){
    glDeleteProgram(ID);
}

// Checks if the different Shaders have compiled properly
void Shader::CompileErrors(unsigned int shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}