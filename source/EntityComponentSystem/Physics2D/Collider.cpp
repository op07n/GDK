// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-08-01.
#include "Collider.h"
//gkd inc
#include "Math/Vector3.h"
#include "EntityComponentSystem/GameObject.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Physics2D;

std::ostream& GDK::ECS::Physics2D::operator<<(std::ostream& s, const GDK::ECS::Physics2D::Collider& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Collider's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Collider::checkForTransformScaleChange()
{
    if (auto gameObject = getGameObject().lock())
    {
        Math::Vector3 scale = gameObject.get()->getScale();
        
        if (b_ScaleBuffer != scale)
            requestShapeRebuildOnNextTick();
        
        b_ScaleBuffer = scale;
        
    }
    
}

void Collider::initialize()
{
    requestShapeRebuildOnNextTick();

}

void Collider::update()
{
    checkForTransformScaleChange();
    
    if (m_RebuildShape)
    {
        buildShape();
        m_RebuildShape = false;
        
    }

}

// Accessors
Collider::Type Collider::getType() const
{
    return m_ColliderType;
}
float Collider::getFriction() const
{
    return m_Friction;
}
float Collider::getDensity() const
{
    return m_Density;
}
float Collider::getRestitution() const
{
    return m_Restitution;
}
bool Collider::getDrawDebugLines() const
{
    return m_DrawDebugLines;
}

void Collider::setType(const Collider::Type &aColliderType)
{
    m_ColliderType=aColliderType;
    requestShapeRebuildOnNextTick();
}
void Collider::setDrawDebugLines(const bool &aBoolean)
{
    m_DrawDebugLines=aBoolean;
    requestShapeRebuildOnNextTick();
}
void Collider::setFriction(const float &aFriction)
{
    m_Friction=aFriction;
    requestShapeRebuildOnNextTick();
}
void Collider::setDensity(const float &aDensity)
{
    m_Density=aDensity;
    requestShapeRebuildOnNextTick();
}
void Collider::setRestitution(const float &aRestitution)
{
    m_Restitution=aRestitution;
    requestShapeRebuildOnNextTick();
}
void Collider::setOffset(const float &aX, const float &aY)
{
    m_Offset.x = aX;
    m_Offset.y = aY;
    
    requestShapeRebuildOnNextTick();
}
