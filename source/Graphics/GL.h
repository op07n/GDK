// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_GL_H
#define GDK_GFX_GL_H

/*!
 OpenGL header for GDK
 includes gl functions from glew and declares C++ friendly helpers in the GLH namespace
 */
#include <glew/include/GL/glew.h>
#include <string>
#include <vector>

namespace GDK{namespace GFX{struct Color;}}

namespace GLH
{
    void ClearColor(const GDK::GFX::Color &aColor);
    
    std::string GetShaderInfoLog(const GLuint &aShaderStageHandle);
    std::string GetProgramInfoLog(const GLuint &aShaderProgramHandle);
    
    std::string GetError();
    std::vector<std::string> GetErrors();
    ///Write all the errors to Debug::error()
    void LogErrors();
    
    ///Enable vertex attribute buffer and create the attribute pointer
    bool EnableVertexAttribute(const std::string &aAttributeName, const GLuint &aProgramHandle, const int &aAttributeSize, const int &aAttributeOffset, const int &aTotalNumberOfVertexAttributeComponents);
    
}

#endif /* GDK_GFX_GL_H  */
