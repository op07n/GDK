#include "ShaderProgram.h"
//std inc
#include <iostream>

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
    //todo: talk to opengl
    
}
