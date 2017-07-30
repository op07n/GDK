// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#include "Mesh.h"
//gdk inc
#include "EntityComponentSystem/Graphics/Camera.h"
#include "EntityComponentSystem/GameObject.h"
#include "Graphics/Model.h"
#include "Memory/default_ptr.h"
#include "Graphics/Model.h"
#include "DefaultResources.h"
#include "Debug/Logger.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS::GFX;

std::ostream& GDK::ECS::GFX::operator<<(std::ostream& s, const ECS::GFX::Mesh& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Mesh's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Mesh::draw(const std::weak_ptr<Camera> &aCamera)
{
    if (auto gameObject = getGameObject().lock())
    {
        m_Model.setModelMatrix(gameObject->getPosition(), gameObject->getRotation());
        
        if (auto camera = aCamera.lock())
            m_Model.draw(camera->getViewMatrix(), camera->getProjectionMatrix());
        
    }
    
}

void Mesh::initialize(){}
void Mesh::update(){}
void Mesh::fixedUpdate(){}

// Constructors, destructors
Mesh::Mesh(const std::weak_ptr<GameObject> &aGameObject)
: GDK::ECS::GFX::GraphicsComponent(aGameObject)
{}

// Accessors
void Mesh::setMesh(const Memory::default_ptr<GDK::GFX::Mesh> &a){m_Model.setMesh(a);}

void Mesh::setTexture(const std::string &aUniformName, const Memory::default_ptr<GDK::GFX::Texture> &aTexture){m_Model.setTexture(aUniformName,aTexture);}
void Mesh::setFloat  (const std::string &aUniformName, const std::shared_ptr<float>                 &aFloat  ){m_Model.setFloat(aUniformName,aFloat);  }
void Mesh::setVector2(const std::string &aUniformName, const std::shared_ptr<Math::Vector2>         &aVector2){m_Model.setVector2(aUniformName,aVector2);}
void Mesh::setVector3(const std::string &aUniformName, const std::shared_ptr<Math::Vector3>         &aVector3){m_Model.setVector3(aUniformName,aVector3);}
void Mesh::setVector4(const std::string &aUniformName, const std::shared_ptr<Math::Vector4>         &aVector4){m_Model.setVector4(aUniformName,aVector4);}
void Mesh::setMat4x4 (const std::string &aUniformName, const Math::Mat4x4                           &aMat4x4 ){m_Model.setMat4x4(aUniformName,aMat4x4); }
