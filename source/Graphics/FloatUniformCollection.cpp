// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-09.
#include "FloatUniformCollection.h"
//gdk inc
#include "GL.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::FloatUniformCollection& a)
{
    s.clear(); s << "{";
    int i = 0;
    for (auto& pair : a.m_Map)
        s << i << ": " << "{Name: " << pair.first << ", " << "Float: " << *pair.second.get() << "}";
    s << "}"; return s;
    
}

void FloatUniformCollection::bind(const GFXuint &aProgramHandle)
{
    for (auto& pair : m_Map)
        GLH::Bind1FloatUniform(aProgramHandle, pair.first, *pair.second.get());
    
}

void FloatUniformCollection::unbind(const GFXuint &aProgramHandle)
{
    for (auto& pair : m_Map)
        GLH::Bind1FloatUniform(aProgramHandle, pair.first, 0);
    
}
