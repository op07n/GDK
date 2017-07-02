#include "GraphicsResource.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::GraphicsResource& aGraphicsResource)
{
    stream.clear();
    stream << "{" << aGraphicsResource.m_Name << "}";
    return stream;

}

std::string GraphicsResource::getName() const {return m_Name;}
void GraphicsResource::setName(const std::string &aName) {m_Name=aName;}
