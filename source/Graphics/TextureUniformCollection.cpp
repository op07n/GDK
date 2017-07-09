// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-09.
#include "TextureUniformCollection.h"
//gdk inc
#include "GL.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::TextureUniformCollection& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "TextureUniformCollection's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void TextureUniformCollection::bind(const int &aProgramHandle)
{
    int i = 0;
    for (auto& pair : m_Map)
        GLH::BindTextureUniform(aProgramHandle, pair.first, pair.second->getHandle(), i++);
    
}

void TextureUniformCollection::unbind(const int &aProgramHandle)
{
    int i = 0;
    for (auto& pair : m_Map)
        GLH::BindTextureUniform(aProgramHandle, pair.first, 0, i++);
    
}
