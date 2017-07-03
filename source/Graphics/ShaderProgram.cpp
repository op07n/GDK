#include "ShaderProgram.h"
//std inc
#include <iostream>
#include <vector>
//gdk inc
#include "../Debug/Logger.h"
#include "GL.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::ShaderProgram& aShaderProgram)
{
    stream.clear();
    stream << "{" << aShaderProgram.m_Name << "}";
    return stream;

}

ShaderProgram::ShaderProgram(const std::string &aName,const std::string &aVertexSource,const std::string &aFragmentSource)
: m_Name(aName)
{
    Debug::log("Creating "+aName+" shader program:");
    const char* vertex_shader   = aVertexSource.c_str();
    const char* fragment_shader = aFragmentSource.c_str();
    
    GFXuint vs = 0;
    {
        Debug::log("Compiling vertex stage sourcecode");
        //run the glsl sources through the compiler, keep handle to both compiled shaders
        vs = glCreateShader (GL_VERTEX_SHADER);
        glShaderSource(vs, 1, &vertex_shader, 0);
        glCompileShader (vs);
    
        GFXint bufflen = 0;
        glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &bufflen);
        
        if (bufflen > 1)
        {
            std::vector<GLchar> infoLog(bufflen);
            glGetShaderInfoLog(vs, bufflen, 0, &infoLog[0]);

            Debug::log("Error: " +std::string(infoLog.begin(),infoLog.end()));
            
        }
        
    }

    GFXuint fs = 0;
    {
        Debug::log("Compiling fragment stage sourcecode");
        fs = glCreateShader (GL_FRAGMENT_SHADER);
        glShaderSource (fs, 1, &fragment_shader, 0);
        glCompileShader (fs);
    
        GFXint bufflen = 0;
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &bufflen);
        
        if (bufflen > 1)
        {
            std::vector<GLchar> infoLog(bufflen);
            glGetShaderInfoLog(fs, bufflen, 0, &infoLog[0]);
            
            Debug::log("Error: " +std::string(infoLog.begin(),infoLog.end()));
            
        }
        
    }
    
    Debug::log("Linking graphics program");
    //create the program with the compiled vert and frag shaders
    m_ProgramHandle = glCreateProgram ();
    glAttachShader(m_ProgramHandle, vs);
    glAttachShader(m_ProgramHandle, fs);
    glLinkProgram(m_ProgramHandle);
    GFXint status = -1;//expecting an error by default
    glGetProgramiv(m_ProgramHandle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        Debug::log("The shader "+aName+" has failed to compile!");
        
        GLint maxLength = 0;
        glGetProgramiv(m_ProgramHandle, GL_INFO_LOG_LENGTH, &maxLength);
        
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(m_ProgramHandle, maxLength, &maxLength, &infoLog[0]);

        Debug::log("Error: " +std::string(infoLog.begin(),infoLog.end()));
        
    }
    else
    {
        Debug::log("Shader program successfully linked");
        
        GFXint attributeCount = -1;
        glGetProgramiv(m_ProgramHandle, GL_ACTIVE_ATTRIBUTES, &attributeCount);
        
        Debug::log("handle number: ",m_ProgramHandle);
        Debug::log("Active attributes: ",attributeCount);
        
        GFXint uniformCount = -1;
        glGetProgramiv(m_ProgramHandle, GL_ACTIVE_UNIFORMS, &uniformCount);
        
        Debug::log("Active uniforms: ",uniformCount);
    
    }
    
}

ShaderProgram::~ShaderProgram()
{
    
    
}
