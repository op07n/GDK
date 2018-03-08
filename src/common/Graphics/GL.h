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
#include <glew.h>
//std inc
#include <string>
#include <vector>

namespace GDK{namespace GFX{struct Color;}}
namespace GDK{namespace Math{struct IntVector2;}}
namespace GDK{namespace Math{struct Vector2;}}
namespace GDK{namespace Math{struct Vector3;}}
namespace GDK{namespace Math{struct Vector4;}}
namespace GDK{namespace Math{struct Mat4x4;}}

namespace GLH
{
    // GDK-type friendly conveniences
    void Viewport(const GDK::Math::IntVector2 &aPos, const GDK::Math::IntVector2 &aSize) noexcept;
    void Scissor(const GDK::Math::IntVector2 &aPos, const GDK::Math::IntVector2 &aSize) noexcept;
    void ClearColor(const GDK::GFX::Color &aColor) noexcept;
    
    // Error detection & logging
    std::string GetShaderInfoLog(const GLuint aShaderStageHandle) noexcept;
    std::string GetProgramInfoLog(const GLuint aShaderProgramHandle) noexcept;
    bool GetError(std::string *aErrorCode = nullptr) noexcept;
    //std::vector<std::string> GetErrors();
    //void LogErrors(const bool &aDoNotLogIfNoErrors = false);
    void ClearErrors() noexcept;
    
    // Vertex binding
    bool EnableVertexAttribute(const std::string &aAttributeName, const GLuint aProgramHandle, const int aAttributeSize, const int aAttributeOffset, const int aTotalNumberOfVertexAttributeComponents) noexcept;
    
    //Uniform binding
    bool BindTextureUniform(const GLuint aShaderHandle, const std::string &aUniformName, const GLuint aTextureHandle, const int aTextureUnit/*, final GLenum &aTextureType*/) noexcept;
    bool Bind1FloatUniform (const GLuint aShaderHandle, const std::string &aUniformName, const float aScalar) noexcept;
    bool Bind2FloatUniform (const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector2 &aVector2) noexcept;
    bool Bind3FloatUniform (const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector3 &aVector3) noexcept;
    bool Bind4FloatUniform (const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector4 &aVector4) noexcept;
    bool BindMatrix4x4     (const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Mat4x4  &aMatrix4x4) noexcept;
}

#endif /* GDK_GFX_GL_H  */
