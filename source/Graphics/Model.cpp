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
    << "Name: "          << a.m_Name                 << ", "
    << "Mesh: "          << *a.m_Mesh.get()          << ", "
    << "ShaderProgram: " << *a.m_ShaderProgram.get() << ", "
    << "m_Textures: "    << a.m_Textures             << ", "
    << "m_Floats: "      << a.m_Floats               << ", "
    << "m_Vector2s: "    << a.m_Vector2s             << ", "
    << "m_Vector3s: "    << a.m_Vector3s             << ", "
    << "m_Vector4s: "    << a.m_Vector4s
    << "}"; return s;

}

Model::Model(const std::string &aName, const std::shared_ptr<Mesh> &aMesh, const std::shared_ptr<ShaderProgram> &aShaderProgram)
: m_Name(aName)
, m_Mesh(aMesh)
, m_ShaderProgram(aShaderProgram)
{}

void Model::draw()
{
    GFXuint programHandle = m_ShaderProgram.get()->draw();
    
    m_Textures.bind(programHandle);
    
    m_Mesh.get()->draw(programHandle);
    
}

void Model::setTexture(const std::string &aUniformName, const std::shared_ptr<Texture> &aTexture){m_Textures.put(aUniformName, aTexture);}
