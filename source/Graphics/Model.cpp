// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "Model.h"
#include "../Debug/Logger.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Model& a)
{
    s.clear(); s << "{"
    << "Name: " << a.m_Name << ", "
    << "Mesh: " << *a.m_Mesh.get() << ", "
    << "ShaderProgram: " << *a.m_ShaderProgram.get()
    << "}"; return s;

}

Model::Model(const std::string &aName, const std::shared_ptr<Mesh> &aMesh, const std::shared_ptr<ShaderProgram> &aShaderProgram)
: m_Name(aName)
, m_Mesh(aMesh)
, m_ShaderProgram(aShaderProgram)
{}

void Model::draw()
{
    m_Mesh.get()->draw(m_ShaderProgram.get()->draw());
    
}
