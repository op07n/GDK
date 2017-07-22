// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-22.
#include "Mat4x4UniformCollection.h"
//gdk inc
#include "GL.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Mat4x4UniformCollection& a)
{
    s.clear(); s << "{";
    int i = 0;
    for (auto& pair : a.m_Map)
    {
        auto mat4x4 = pair.second;
        s << i << ": " << "{Name: " << pair.first << ", " << "Matrix: " << mat4x4 << "}";
        
    }
    s << "}"; return s;
    
}

void Mat4x4UniformCollection::bind(const GFXuint &aProgramHandle)
{
    for (auto& pair : m_Map)
        GLH::BindMatrix4x4(aProgramHandle, pair.first, pair.second);
    
}

void Mat4x4UniformCollection::unbind(const GFXuint &aProgramHandle)
{
    for (auto& pair : m_Map)
        GLH::BindMatrix4x4(aProgramHandle, pair.first, Math::Mat4x4::Identity);
    
}
