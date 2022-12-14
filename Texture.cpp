#include"Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType){
    type = texType;
    int widthImg, heightImg, numColCh;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

    //Set up texture
    GLuint texture;
    glGenTextures(1, &ID);
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    //Set scaling for texture
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    //Set Repeat for texture
    glTexParameteri(texType, GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T,GL_REPEAT);

    //Generate texture, RGB for JPG RGBA for PNG
    glTexImage2D(texType,0,GL_RGBA,widthImg, heightImg, 0, format, pixelType,bytes);
    glGenerateTextureMipmap(texType);
    stbi_image_free(bytes);
    glBindTexture(texType,0);
}
void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit){
    GLuint tex0Uni = glGetUniformLocation(shader.ID, uniform);
    shader.Activate();
    glUniform1i(tex0Uni,unit);
}

void Texture::Bind(){
    glBindTexture(type,ID);
}

void Texture::Unbind(){
    glBindTexture(type,0);
}

void Texture::Delete(){
    glDeleteTextures(1, &ID);
}