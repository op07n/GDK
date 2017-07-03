#include "VertexAttribute.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::VertexAttribute& a)
{
    stream.clear();
    stream << "{" << "Name: " << a.name << ", Size: " << a.size << "}";
    return stream;

}

VertexAttribute::VertexAttribute(const std::string &aName, const int &aSize)
: name(aName)
, size(aSize)
{}
