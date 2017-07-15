// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#include "Plane.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Math;

// Stringify
std::ostream& GDK::Math::operator<< (std::ostream &s, const Math::Plane &a)
{
    s.clear(); s << "{"
    << "position: " << a.position << ", "
    << "normal: "   << a.normal
    << "}"; return s;
    
}

// Constructors
Plane::Plane(const Vector3& aPosition, const Vector3& aNormal)
: position(aPosition)
, normal(aNormal)
{}
