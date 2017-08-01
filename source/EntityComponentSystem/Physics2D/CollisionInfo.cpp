// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "CollisionInfo.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Physics2D;

std::ostream& GDK::Physics2D::operator<<(std::ostream& s, const Physics2D::CollisionInfo& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "CollisionInfo's: " << "operator<< has not been implemented"
    << "}"; return s;

}

CollisionInfo::CollisionInfo(const std::weak_ptr<Collider> &aMine, const std::weak_ptr<Collider> &aOther, const Math::Vector2 &aCollisionPoint)
: mine(aMine)
, other(aOther)
, collisionPoint(aCollisionPoint)
{}
