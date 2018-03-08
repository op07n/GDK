// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#include "Graphics/GL.h"
//gdk inc
/*#include "Debug/Logger.h"
#include "Math/IntVector2.h"
#include "Math/Mat4x4.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"*/
//std inc
#include <vector>

using namespace GDK;
using namespace GFX;

/*void GLH::Viewport(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize) noexcept
{
    glViewport(aPos.x, aPos.y, aSize.x, aSize.y);
}

void GLH::Scissor(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize) noexcept
{
    glScissor(aPos.x, aPos.y, aSize.x, aSize.y);
}

void GLH::ClearColor(const GDK::GFX::Color &aColor) noexcept
{
    glClearColor(aColor.r, aColor.g, aColor.b, aColor.a);
}*/

std::string GLH::GetShaderInfoLog(const GLuint aShaderStageHandle) noexcept
{
    GLint bufflen = 0;
    glGetShaderiv(aShaderStageHandle, GL_INFO_LOG_LENGTH, &bufflen);
    
    if (bufflen > 1)
    {
        std::vector<GLchar> infoLog(bufflen);
        glGetShaderInfoLog(aShaderStageHandle, bufflen, 0, &infoLog[0]);
        
        return std::string(infoLog.begin(),infoLog.end());
    }
    
    return "clear";
}

std::string GLH::GetProgramInfoLog(const GLuint aShaderProgramHandle) noexcept
{
    GLint maxLength = 0;
    glGetProgramiv(aShaderProgramHandle, GL_INFO_LOG_LENGTH, &maxLength);
    
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(aShaderProgramHandle, maxLength, &maxLength, &infoLog[0]);
    
    return std::string(infoLog.begin(),infoLog.end());
}

/*bool GLH::EnableVertexAttribute(const std::string &aAttributeName, const GLuint aProgramHandle, const int aAttributeSize, const int aAttributeOffset, const int aTotalNumberOfVertexAttributeComponents) noexcept
{
    GLint attribute = glGetAttribLocation(aProgramHandle, aAttributeName.c_str());
    
    if (attribute ==-1) // The attribute either does not exist or is not used in the current shader program
        return false;
    
    glEnableVertexAttribArray(attribute);
    
    //Create vertex attribute pointers..
    glVertexAttribPointer
    (
        attribute, //Position attribute index
        aAttributeSize, //Pos size
        GL_FLOAT, //data type of each member of the format (must be uniform, look at glbindbufferdata, it takes an array or ptr to an array, so no suprise)
        GL_FALSE,
        sizeof(GLfloat)*aTotalNumberOfVertexAttributeComponents,
        (void*)(sizeof(GLfloat)*aAttributeOffset)
     
    );
    
    return true;
}

bool GLH::GetError(std::string *aErrorCode) noexcept
{
    std::string errorcodebuffer = "";
    
    switch (glGetError())
    {
        case(GL_NO_ERROR):
            errorcodebuffer = "GL_NO_ERROR";
            return false;
        
        case(GL_INVALID_ENUM):
            errorcodebuffer = "GL_INVALID_ENUM";
            
        case(GL_INVALID_VALUE):
            errorcodebuffer = "GL_INVALID_VALUE";
            
        case(GL_INVALID_OPERATION):
            errorcodebuffer = "GL_INVALID_OPERATION";
            
        case(GL_INVALID_FRAMEBUFFER_OPERATION):
            errorcodebuffer = "GL_INVALID_FRAMEBUFFER_OPERATION";
        
        case(GL_OUT_OF_MEMORY):
            errorcodebuffer = "GL_OUT_OF_MEMORY";
        
        default:
            errorcodebuffer = "GDK_UNHANDLED_GL_ERROR_CODE";
        
    }
    
    if (aErrorCode != nullptr)
    {
        *aErrorCode = errorcodebuffer;
    }
    
    return true;
}

void GLH::ClearErrors() noexcept
{
    while (glGetError() != GL_NO_ERROR);
}

bool GLH::BindTextureUniform(const GLuint aShaderHandle, const std::string &aUniformName, const GLuint aTextureHandle, const int aTextureUnit) noexcept
{
    GLint uniformHandle  = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    int theTextureType = GL_TEXTURE_2D;
    
    if (uniformHandle == -1)
        return false;
    
    switch (aTextureUnit)
    {
        case 1: glActiveTexture(GL_TEXTURE1); break;
        case 2: glActiveTexture(GL_TEXTURE2); break;
        case 3: glActiveTexture(GL_TEXTURE3); break;
        case 4: glActiveTexture(GL_TEXTURE4); break;
        case 5: glActiveTexture(GL_TEXTURE5); break;
        case 6: glActiveTexture(GL_TEXTURE6); break;
        case 7: glActiveTexture(GL_TEXTURE7); break;
            
        default: glActiveTexture( GL_TEXTURE0); break;
    }
    
    glBindTexture(theTextureType, aTextureHandle);
    glUniform1i(uniformHandle, aTextureUnit);
    
    return true;
}

bool GLH::Bind1FloatUniform(const GLuint aShaderHandle, const std::string &aUniformName, const float aValue) noexcept
{
    GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    
    if (uniformHandle == -1)
        return false;
    
    glUniform1f(uniformHandle, aValue);
    
    return true;
}

bool GLH::Bind2FloatUniform(const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector2 &aVector2) noexcept
{
    GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    
    if (uniformHandle == -1)
        return false;
    
    glUniform2f(uniformHandle, aVector2.x, aVector2.y);
    
    return true;
}

bool GLH::Bind3FloatUniform(const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector3 &aVector3) noexcept
{
    GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    
    if (uniformHandle == -1)
        return false;
    
    glUniform3f(uniformHandle, aVector3.x, aVector3.y, aVector3.z);
    
    return true;
}

bool GLH::Bind4FloatUniform(const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Vector4 &aVector4) noexcept
{
    GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    
    if (uniformHandle == -1)
        return false;
    
    glUniform4f(uniformHandle, aVector4.x, aVector4.y, aVector4.z, aVector4.w);
    
    return true;
}

bool GLH::BindMatrix4x4(const GLuint aShaderHandle, const std::string &aUniformName, const GDK::Math::Mat4x4 &aMatrix4x4) noexcept
{
    GLint uniformHandle = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    
    if (uniformHandle == -1)
        return false;
    
    glUniformMatrix4fv(uniformHandle, 1, GL_FALSE, &aMatrix4x4.m[0][0]);
    
    return true;
}*/
