#include "Texture.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::Texture& aTexture)
{
    stream.clear();
    stream << "{" << "Texture's operator<< has not been implemented" << "}";
    return stream;

}

Texture::Texture(const std::vector<const unsigned char>& aTextureData)
{
    //...
    
}

std::string Texture::getName(){return m_Name;}
GFXuint Texture::getHandle(){return m_Handle;}
