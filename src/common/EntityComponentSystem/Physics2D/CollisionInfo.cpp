// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "CollisionInfo.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Physics2D;

static constexpr char TAG[] = "Physics2D";

std::ostream &GDK::Physics2D::operator<<(std::ostream &s, const Physics2D::CollisionInfo &a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

CollisionInfo::CollisionInfo(const std::weak_ptr<ECS::Physics2D::Collider> &aMine, const std::weak_ptr<ECS::Physics2D::Collider> &aOther, const Math::Vector2 &aCollisionPoint)
: mine(aMine)
, other(aOther)
, collisionPoint(aCollisionPoint)
{}
