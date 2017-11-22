// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "GameObject.h"
//gdk inc
#include "Component.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream &GDK::ECS::operator<<(std::ostream &s, const ECS::GameObject &a) noexcept
{
    (void)a;
    
    s.clear(); s
    << "{"
    << "GameObject's: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

GameObject::GameObject(const std::weak_ptr<Scene> &aScene) noexcept
: m_MyScene(aScene)
{}

void GameObject::update() const noexcept
{
    for (auto component : m_Components)
    {
        if (!component->m_DidInit)
        {
            component->initialize();
            component->m_DidInit = true;
        }
        
        component->update();
    }
}

void GameObject::fixedUpdate() const noexcept
{
    for (auto component : m_Components)
    {
        if (!component->m_DidInit)
        {
            component->initialize();
            component->m_DidInit = true;
                
        }
            
        component->fixedUpdate();
    }
}

std::weak_ptr<Component> GameObject::getComponent(const size_t aIndex) const noexcept
{
    return m_Components[aIndex];
}

size_t  GameObject::getComponentCount() const noexcept
{
    return m_Components.size();
}

std::string GameObject::getName() const noexcept
{
    return m_Name;
}

std::weak_ptr<Scene> GameObject::getScene() const noexcept
{
    return m_MyScene;
}

void GameObject::setName(const std::string &aName) noexcept
{
    m_Name = aName;
}

void GameObject::setPosition(const Math::Vector3 &aPosition) noexcept
{
    m_Position = aPosition;
}

void GameObject::setPosition(const float aX,const float aY, const float aZ) noexcept
{
    m_Position.x = aX;
    m_Position.y = aY;
    m_Position.z = aZ;
}

void GameObject::setScale(const Math::Vector3 &aScale) noexcept
{
    m_Scale = aScale;
}

void GameObject::setRotation(const Math::Quaternion &aRotation) noexcept
{
    m_Rotation = aRotation;
}

Math::Vector3 GameObject::getPosition() const noexcept
{
    return m_Position;
}

Math::Vector3 GameObject::getScale() const noexcept
{
    return m_Scale;
}

Math::Quaternion GameObject::getRotation() const noexcept
{
    return m_Rotation;
}
