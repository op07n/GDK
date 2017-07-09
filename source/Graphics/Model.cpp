// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "Model.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& stream, const GFX::Model& aModel)
{
    stream.clear();
    stream << "{" << "Model's operator<< has not been implemented" << "}";
    return stream;

}

Model::Model(const std::string &aName, const Mesh &aMesh, ShaderProgram &aShaderProgram)
: m_Name(aName)
, m_Mesh(aMesh)
, m_ShaderProgram(aShaderProgram)
{}
