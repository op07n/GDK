// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#include "Model.h"
#include "../Debug/Logger.h"
#include "../Math/Mat4x4.h"
#include "Camera.h"
#include "GL.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;
using namespace Math;

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
, m_Textures()
, m_Floats()
, m_Vector2s()
, m_Vector3s()
, m_Vector4s()
{}

void Model::draw(const Camera& aCamera)
{
    GFXuint programHandle = m_ShaderProgram.get()->draw();
    
    //bind this model's uniforms
    m_Textures.bind(programHandle);
    m_Floats.bind(programHandle);
    m_Vector2s.bind(programHandle);
    m_Vector3s.bind(programHandle);
    m_Vector4s.bind(programHandle);
    
    //bind standard uniforms
    Mat4x4 p = aCamera.getProjectionMatrix();
    Mat4x4 v = aCamera.getViewMatrix();
    Mat4x4 m = getModelMatrix();
    Mat4x4 mvp = p * v * m;
    GLH::BindMatrix4x4(programHandle, "_MVP", mvp);
    
    m_Mesh.get()->draw(programHandle);
    
}

Math::Mat4x4 Model::getModelMatrix() const
{
    return Mat4x4();
    
}

// Accessors
void Model::setTexture(const std::string &aUniformName, const std::shared_ptr<Texture> &aTexture){m_Textures.put(aUniformName, aTexture);}
void Model::setFloat  (const std::string &aUniformName, const std::shared_ptr<float> &aFloat){m_Floats.put(aUniformName,aFloat);}
void Model::setVector2(const std::string &aUniformName, const std::shared_ptr<Vector2> &aVector2){m_Vector2s.put(aUniformName,aVector2);}
void Model::setVector3(const std::string &aUniformName, const std::shared_ptr<Vector3> &aVector3){m_Vector3s.put(aUniformName,aVector3);}
void Model::setVector4(const std::string &aUniformName, const std::shared_ptr<Vector4> &aVector4){m_Vector4s.put(aUniformName,aVector4);}
