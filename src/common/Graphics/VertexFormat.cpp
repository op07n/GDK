// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "VertexFormat.h"
//gdk inc
#include "GL.h"
#include "Debug/Logger.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

// Special values
VertexFormat VertexFormat::Pos3uv2Norm3(
{
    {"a_Position",3},
    {"a_UV"      ,2},
    {"a_Normal"  ,3}
    
});

VertexFormat VertexFormat::Pos3uv2(
{
    {"a_Position",3},
    {"a_UV"      ,2}

});

VertexFormat VertexFormat::Pos3(
{
    {"a_Position",3}

});

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::VertexFormat& a)
{
    s << "{";
    s << "notimp Vertexformat";
    s << "}";
    return s;
    
}

VertexFormat::VertexFormat(const std::vector<VertexAttribute> &aAttributes)
: m_Format(aAttributes)
, m_SumOfAttributeComponents(([aAttributes]() -> int
{
    int buf = 0;
    
    for(size_t i = 0, s = aAttributes.size(); i < s; i++)
        buf += aAttributes[i].size;
    
    return buf;
    
})())
{}

void VertexFormat::enableAttributes(const GFXuint &aShaderProgramHandle)
{
    int attributeOffset = 0;
    
    for(size_t i = 0, s = m_Format.size(); i < s; i++)
    {
        std::string attributeName = m_Format[i].name;
        int attributeSize = m_Format[i].size;
        
        GLH::EnableVertexAttribute(attributeName, aShaderProgramHandle, attributeSize, attributeOffset, m_SumOfAttributeComponents);
        
        attributeOffset += attributeSize;
        
    }
    
}

int VertexFormat::getSumOfAttributeComponents() const {return m_SumOfAttributeComponents;}
