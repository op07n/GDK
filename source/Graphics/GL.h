// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_GL_H
#define GDK_GFX_GL_H

/*!
 OpenGL header for GDK
 includes gl functions from glew and declares C++ friendly helpers in the GLH namespace
 */
//Thirdparty inc
#include <glew/include/GL/glew.h>
//std inc
#include <string>
#include <vector>

namespace GDK{namespace GFX{struct Color;}}
namespace GDK{namespace Math{struct IntVector2;}}

namespace GLH
{
    // GDK-type friendly conveniences
    void Viewport(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize);
    void Scissor(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize);
    void ClearColor(const GDK::GFX::Color &aColor);
    
    // Error detection & logging
    std::string GetShaderInfoLog(const GLuint &aShaderStageHandle);
    std::string GetProgramInfoLog(const GLuint &aShaderProgramHandle);
    std::string GetError();
    std::vector<std::string> GetErrors();
    void LogErrors(const bool &aDoNotLogIfNoErrors = false);
    bool EnableVertexAttribute(const std::string &aAttributeName, const GLuint &aProgramHandle, const int &aAttributeSize, const int &aAttributeOffset, const int &aTotalNumberOfVertexAttributeComponents);
    
}

#endif /* GDK_GFX_GL_H  */
