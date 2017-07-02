#include "ShaderProgram.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::ShaderProgram& aShaderProgram)
{
    stream.clear();
    stream << "{" << aShaderProgram.getName() << "}";
    return stream;

}
