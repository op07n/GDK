#include "Texture.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::Texture& aTexture)
{
    stream.clear();
    stream << "{" << "{CLASSNAME}'s operator<< has not been implemented" << "}";
    return stream;

}
