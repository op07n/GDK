// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "Texture.h"
//gdk inc
#include "GL.h"
//Thirdparty inc
#include <stb/stb_image.h>
//std inc
#include <iostream>
#include <vector>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::Texture& aTexture)
{
    stream.clear();
    stream << "{" << "Texture's operator<< has not been implemented" << "}";
    return stream;

}

Texture::Texture(const std::string &aName, std::vector<GFXbyte>& aTextureData)
: m_Name(aName)
{
    //decode the png rgba32 data
    unsigned char *res_data, *decodedData;
    int width, height, components;
    res_data = &aTextureData[0];
    decodedData = stbi_load_from_memory(res_data, (int)aTextureData.size(), &width, &height, &components, 0);
    
    //Put the texture data in video memory
    glGenTextures(1, &m_Handle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_Handle);
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, decodedData );
    
    //Apply parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    
    glBindTexture( GL_TEXTURE_2D,0);//clear the binding
    stbi_image_free(decodedData);//remove decoded data from ram
    
}

Texture::Texture(Texture&& other)
{
    m_Name = other.m_Name;
    m_Handle = other.m_Handle;
    
    other.m_Handle = 0;
    
}

Texture::~Texture()
{
    glDeleteBuffers(1, &m_Handle);
    
}

std::string Texture::getName(){return m_Name;}
GFXuint Texture::getHandle(){return m_Handle;}
