// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#include "ShaderProgram.h"
//std inc
#include <iostream>
//#include <vector>
//gdk inc
#include "../Debug/Logger.h"
#include "GL.h"
#include "../Utilities/Exception.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::ShaderProgram& aShaderProgram)
{
    GFXint activeAttribs = 0, activeUniforms = 0;
    glGetProgramiv(aShaderProgram.m_ProgramHandle, GL_ACTIVE_ATTRIBUTES, &activeAttribs);
    glGetProgramiv(aShaderProgram.m_ProgramHandle, GL_ACTIVE_UNIFORMS, &activeUniforms);
    //Debug::log("Success! Handle: ",m_ProgramHandle,", Active attributes: ",activeAttribs,", Active uniforms: ",activeUniforms);
    
    stream.clear();
    stream
    << "{"
    << "Name: " << aShaderProgram.m_Name
    << ", Active attributes: " << activeAttribs
    << ", Active uniforms: " << activeUniforms
    << "}";
    
    return stream;

}



ShaderProgram::ShaderProgram(const std::string &aName,const std::string &aVertexSource,const std::string &aFragmentSource)
: m_Name(aName)
{
    // Compile vertex stage
    const char* vertex_shader = aVertexSource.c_str();
    GFXuint vs = 0;
    vs = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, 0);
    glCompileShader(vs);
 
    // Compile fragment stage
    const char* fragment_shader = aFragmentSource.c_str();
    GFXuint fs = 0;
    fs = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fs, 1, &fragment_shader, 0);
    glCompileShader (fs);
    
    // Link the program
    m_ProgramHandle = glCreateProgram ();
    glAttachShader(m_ProgramHandle, vs);
    glAttachShader(m_ProgramHandle, fs);
    glLinkProgram(m_ProgramHandle);
    
    GFXint status = -1;
    glGetProgramiv(m_ProgramHandle, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        std::ostringstream message;
        
        message << "The shader " << aName << " has failed to compile!";
        
        std::string shortMessage(message.str().append(" See error log for details"));
        
        message << std::endl
        << std::endl << "program compilation log: " << GLH::GetProgramInfoLog(m_ProgramHandle) << std::endl
        << std::endl << "vertex shader compilation log: " << GLH::GetShaderInfoLog(vs) << std::endl
        << std::endl << "fragment shader compilation log: " << GLH::GetShaderInfoLog(fs);
        
        Debug::error(message.str());
        //throw GDK::Exception(shortMessage);
        
    }
    
}

ShaderProgram::~ShaderProgram()
{
    if (m_ProgramHandle > 0)
        glDeleteProgram(m_ProgramHandle);
    
}

std::string ShaderProgram::getName(){return m_Name;}
GFXuint ShaderProgram::getHandle(){return m_ProgramHandle;}
