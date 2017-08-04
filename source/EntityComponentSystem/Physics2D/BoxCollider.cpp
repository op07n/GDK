// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-08-02.
#include "BoxCollider.h"

//3rd party
#include <Common/b2Math.h>
//std inc
#include <iostream>
#include <array>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Physics2D;

std::ostream& GDK::ECS::Physics2D::operator<<(std::ostream& s, const GDK::ECS::Physics2D::BoxCollider& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "BoxCollider's: " << "operator<< has not been implemented"
    << "}"; return s;
}
    
void BoxCollider::buildShape()
{
    if (auto ptr = getGameObject().lock())
    {
        Math::Vector3 scale = ptr->getScale();
        Math::Vector2 offset = getOffset();
        
        float hs(1./2.);
        
        std::array<b2Vec2,4> vertices
        ({{
            {(-hs +offset.x)*scale.x, (-hs +offset.y)*scale.z},
            {( hs +offset.x)*scale.x, (-hs +offset.y)*scale.z},
            {( hs +offset.x)*scale.x, ( hs +offset.y)*scale.z},
            {(-hs +offset.x)*scale.x, ( hs +offset.y)*scale.z},
        }});
        
        m_Shape.Set(&vertices[0], vertices.size());
        
        m_Shape.m_centroid.Set(offset.x, offset.y);
        
        SimpleCollider::buildShape();
            
    }
    
}
