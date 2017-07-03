#include "GL.h"
//gdk inc
#include "Color.h"
//std inc
#include <vector>

using namespace GDK;
using namespace GFX;

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
    //Position attribute pointer
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
