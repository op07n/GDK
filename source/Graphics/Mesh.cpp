#include "Mesh.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::Mesh& aMesh)
{
    stream.clear();
    stream << "{" << "Mesh's operator<< has not been implemented" << "}";
    return stream;

}

// Accessors
GFXuint Mesh::getHandle(){return m_VertexBufferHandle;}
int Mesh::getVertexCount(){return m_VertexCount;}
