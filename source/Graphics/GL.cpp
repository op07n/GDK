// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#include "GL.h"
//gdk inc
#include "Color.h"
#include "../Debug/Logger.h"
#include "../Math/IntVector2.h"
//std inc
#include <vector>

using namespace GDK;
using namespace GFX;

void GLH::Viewport(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize)
{
    glViewport(aPos.x,aPos.y,aSize.x,aSize.y);
    
}

void GLH::Scissor(const GDK::Math::IntVector2& aPos, const GDK::Math::IntVector2& aSize)
{
    glScissor(aPos.x,aPos.y,aSize.x,aSize.y);
    
}

void GLH::ClearColor(const GDK::GFX::Color &aColor)
{
    glClearColor(aColor.r,aColor.g,aColor.b,aColor.a);
    
}

std::string GLH::GetShaderInfoLog(const GLuint &aShaderStageHandle)
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

std::string GLH::GetProgramInfoLog(const GLuint &aShaderProgramHandle)
{
    GLint maxLength = 0;
    glGetProgramiv(aShaderProgramHandle, GL_INFO_LOG_LENGTH, &maxLength);
    
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(aShaderProgramHandle, maxLength, &maxLength, &infoLog[0]);
    
    return std::string(infoLog.begin(),infoLog.end());
    
}

bool GLH::EnableVertexAttribute(const std::string &aAttributeName, const GLuint &aProgramHandle, const int &aAttributeSize, const int &aAttributeOffset, const int &aTotalNumberOfVertexAttributeComponents)
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

std::string GLH::GetError()
{
    switch (glGetError())
    {
        case(GL_INVALID_ENUM):
            return "GL_INVALID_ENUM";
        break;
            
        case(GL_INVALID_VALUE):
            return "GL_INVALID_VALUE";
        break;
            
        case(GL_INVALID_OPERATION):
            return "GL_INVALID_OPERATION";
        break;
            
        case(GL_INVALID_FRAMEBUFFER_OPERATION):
            return "GL_INVALID_FRAMEBUFFER_OPERATION";
        break;
            
        case(GL_OUT_OF_MEMORY):
            return "GL_OUT_OF_MEMORY";
        break;
            
    }
    
    return "GL_NO_ERROR";
    
}

std::vector<std::string> GLH::GetErrors()
{
    std::vector<std::string> errors;
    
    for(std::string error=GetError();;error=GetError())
    {
        errors.push_back(error);
        
        if (errors.back()=="GL_NO_ERROR")
            break;
        
    }
    
    return errors;
    
}

void GLH::LogErrors(const bool &aDoNotLogIfNoErrors)
{
    std::vector<std::string> errors = GetErrors();
    size_t s = errors.size();
    
    if (aDoNotLogIfNoErrors == true && s <= 1)
        return;
    
    std::ostringstream ss;
    ss << "OpenGL errors: ";
    
    if (s > 1) //removes GL_NO_ERROR from begin written at the end of the log
        s--;
    
    for(size_t i=0;i<s;i++)
    {
        ss << errors[i];
        
        if (i != s-1)
            ss << ", ";
        
    }
    
    Debug::error(ss.str());
    
}

bool GLH::BindTextureUniform(const GLuint &aShaderHandle, const std::string &aUniformName, const GLuint &aTextureHandle, const int aTextureUnit/*, final GLenum &aTextureType*/)
{
    int uniformHandle  = glGetUniformLocation(aShaderHandle, aUniformName.c_str());
    int theTextureType = GL_TEXTURE_2D;
    
    if (uniformHandle == -1)
        return false;
    
    switch (aTextureUnit)
    {
        case  1:glActiveTexture( GL_TEXTURE1);break;
        case  2:glActiveTexture( GL_TEXTURE2);break;
        case  3:glActiveTexture( GL_TEXTURE3);break;
        case  4:glActiveTexture( GL_TEXTURE4);break;
        case  5:glActiveTexture( GL_TEXTURE5);break;
        case  6:glActiveTexture( GL_TEXTURE6);break;
        case  7:glActiveTexture( GL_TEXTURE7);break;
            
        default:glActiveTexture( GL_TEXTURE0);break;
            
    }
    
    glBindTexture(theTextureType, aTextureHandle);
    glUniform1i(uniformHandle, aTextureUnit);
    
    return true;
    
}
