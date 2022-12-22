#include"Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot){
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

    // Check what type of color channels the texture has and load it accordingly
	if (numColCh == 4)
		glTexImage2D
		(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else if (numColCh == 3)
		glTexImage2D
		(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else if (numColCh == 1)
		glTexImage2D
		(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else
		throw std::invalid_argument("Automatic Texture type recognition failed");
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