#include "test.h"

#include "Graphics/ShaderProgram.h"

using namespace GDK;
using namespace GFX;

//-- OpenGL mocks
GLint glCreateShader_value =  1;
GLuint glCreateProgram_value = 1;
bool glGetProgramiv_WillSucceed = true;

using GLint = int;
using GLsizei = int;
using GLuint = unsigned int;
using GLenum = unsigned int;
using GLchar = char;

void glUseProgram(GLuint program){}

void glLinkProgram(GLuint program){}

void glAttachShader(GLuint program, GLuint shader){}

GLuint glCreateShader(GLenum shaderType){return glCreateShader_value;}

void glGetProgramiv(GLuint program, GLenum pname, GLint* param){ glGetProgramiv_WillSucceed ? *param = GL_TRUE : GL_FALSE; }

void glShaderSource(GLuint shader, GLsizei count, const GLchar * const *string, const GLint *length){}

void glCompileShader(GLuint shader){}

GLuint glCreateProgram(){return glCreateProgram_value;}

void glDeleteProgram(GLuint program){}

//-- Debug::Logger mocks

#include <iostream>
#include <string>
#include "Debug/Logger.h"

namespace GDK { namespace Debug {
Logger Logger::s_GDKLogger
(
    [](const std::string &aMessage)
    {
    }
);

Logger Logger::s_GDKErrorLogger
(
    [](const std::string &aMessage)
    {
    }
);

Logger::Logger(const std::function<void(const std::string &)> &aLoggingBehaviourCallback) noexcept
: m_LoggingBehaviourCallback
(
    aLoggingBehaviourCallback == nullptr? [](const std::string &aMessage)
    {
    }
    : aLoggingBehaviourCallback
)
{}
}}

//-- GLH mocks
namespace GLH {
std::string GetShaderInfoLog(const GLuint aShaderStageHandle) noexcept
{   
    return "Infolog";
}

std::string GetProgramInfoLog(const GLuint aShaderProgramHandle) noexcept
{
    return "programlog";
}
}
//---------------------------------------------------------------------------------------------------

constexpr auto VERTEX_SHADER_SOURCE = R"V0G0N(
#version 150
//Uniforms
uniform mat4 _MVP;
    
//VertIn
in vec3 a_Position;
    
void main ()
{
    gl_Position = _MVP * vec4(a_Position,1.0);
}
)V0G0N";

constexpr auto FRAGMENT_SHADER_SOURCE = R"V0G0N(
#version 150
//FragOut
out vec4 out_Frag;
    
void main()
{
    out_Frag = vec4(1,0.2,0.8,1);
}
)V0G0N";

TEST_START
{ "Ctor: Successful construction", [&]()
{
    try
    {
        const auto shader = ShaderProgram("MyFancyShader", VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE);

        test_succeeded();
    }
    catch (std::exception ex)
    {
        
    }
}},

{ "Ctor: Failed construction", [&]()
{
    try
    {
        const auto shader = ShaderProgram("MyFancyShader", VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE);
    }
    catch (std::exception ex)
    {
        test_succeeded();
    }
}},

/*
{ "Example", [&]()
{
    
}},
*/

TEST_END
