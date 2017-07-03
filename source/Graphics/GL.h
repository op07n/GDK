// © 2017 Joseph Cameron - &all Rights Reserved
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
    //GetError();
    
    void ClearColor(const GDK::GFX::Color &aColor);
    
    std::string GetShaderInfoLog(const GLuint &aShaderStageHandle);
    std::string GetProgramInfoLog(const GLuint &aShaderProgramHandle);
    std::string GetError();
    std::vector<std::string> GetErrors();
    void LogErrors();
    
    bool EnableVertexAttribute(const std::string &aAttributeName, const GLuint &aProgramHandle, const int &aAttributeSize, const int &aAttributeOffset, const int &aTotalNumberOfVertexAttributeComponents);
    
    /*namespace Diagnostics
    {
        void checkGLErrors(void);
        void checkGLSLErrors(const GLuint &aShaderHandle);
        void clearGLErrors(void);
        
    }*/
    
    /*namespace Uniforms
    {
        //Floats
        void load1Foat(const GLuint &aShaderHandle, const char* &aUniformName, const float &aValue);
        
        //Vectors
        void loadVector3f(const GLuint &aShaderHandle, const char* &aUniformName, float* &aValue);
        
        //Texture
        void loadTexture(const GLuint &aShaderHandle, const char* aUniformName, const GLuint &aTextureHandle, const GLuint &aTextureUnit = 0, const GLenum &aTextureType = GL_TEXTURE_2D);
        
        //Matricies
        void loadMatrix4x4(const GLuint &aShaderHandle, const char* &aUniformName, const float* aMatrix4x4);
        void loadMatrix3x3(const GLuint &aShaderHandle, const char* &aUniformName, const float* aMatrix3x3);
        
    }*/
    
}

#endif /* GDK_GFX_GL_H  */
