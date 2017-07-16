// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "Mesh.h"
//std inc
#include <iostream>
//gdk inc
#include "GL.h"
#include "../Debug/Logger.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Mesh& a)
{
    s.clear(); s << "{"
    << "Name: "         << a.m_Name               << ", "
    << "Handle: "       << a.m_VertexBufferHandle << ", "
    << "VertexCount: "  << a.m_VertexCount        << ", "
    << "VertexFormat: " << a.m_VertexFormat
    << "}"; return s;

}

GLenum MeshTypeToOpenGLDrawType(const Mesh::Type &aType)
{
    switch (aType)
    {
        case Mesh::Type::Dynamic:
            return GL_DYNAMIC_DRAW;
        break;
        
        default:
        case Mesh::Type::Static:
            return GL_STATIC_DRAW;
        break;
        
    }
    
}

Mesh::Mesh(const std::string &aName, const std::vector<GFXfloat> &aVertexData, const VertexFormat &aVertexFormat, const Mesh::Type &aType)
: m_Name(aName)
, m_VertexBufferHandle(0)
, m_VertexCount((int)aVertexData.size()/aVertexFormat.getSumOfAttributeComponents())
, m_VertexFormat(aVertexFormat)
{
    GLint type = MeshTypeToOpenGLDrawType(aType);
    
    // Create and populate a VBO
    glGenBuffers(1, &m_VertexBufferHandle);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * aVertexData.size(), &aVertexData[0], type);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
}

Mesh::~Mesh()
{
    if (m_VertexBufferHandle > 0)
        glDeleteBuffers(1, &m_VertexBufferHandle);
    
}

Mesh::Mesh(Mesh&& a)
{
    m_Name               = a.m_Name;
    m_VertexBufferHandle = a.m_VertexBufferHandle;
    m_VertexCount        = a.m_VertexCount;
    m_VertexFormat       = a.m_VertexFormat;
    
    a.m_VertexBufferHandle = 0;
    
}

void Mesh::draw(const GFXuint aShaderProgramHandle)
{
    glBindBuffer( GL_ARRAY_BUFFER, m_VertexBufferHandle);
    
    std::vector<std::string> attributeNames = m_VertexFormat.getNames();
    int attributeOffset = 0;
    
    for(size_t i=0,s=attributeNames.size();i<s;i++)
    {
        std::string attributeName = attributeNames[i];
        int attributeSize = m_VertexFormat.getAttributeSize(attributeName);
        
        GLH::EnableVertexAttribute(attributeName, aShaderProgramHandle, attributeSize, attributeOffset, m_VertexFormat.getSumOfAttributeComponents());
        
        attributeOffset+=attributeSize;
        
    }
    
    glDrawArrays( GL_TRIANGLES, 0, m_VertexCount );
    
}

void Mesh::updateVertexData(const std::vector<GFXfloat> &aNewVertexData, const VertexFormat &aNewVertexFormat, const Mesh::Type &aNewType)
{
    m_VertexFormat = aNewVertexFormat;
    m_VertexCount  = (int)(aNewVertexData.size()/aNewVertexFormat.getSumOfAttributeComponents());
    GLint type = MeshTypeToOpenGLDrawType(aNewType);
    
    glBindBuffer (GL_ARRAY_BUFFER, m_VertexBufferHandle);
    glBufferData (GL_ARRAY_BUFFER, sizeof(GLfloat) * aNewVertexData.size(), &aNewVertexData[0], type);
    glBindBuffer (GL_ARRAY_BUFFER,0);
    
}

// Accessors
std::string Mesh::getName()const{return m_Name;}
GFXuint Mesh::getHandle()const{return m_VertexBufferHandle;}
