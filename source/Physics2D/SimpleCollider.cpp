// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "SimpleCollider.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Physics2D;

std::ostream& GDK::Physics2D::operator<<(std::ostream& s, const Physics2D::SimpleCollider& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "SimpleCollider's: " << "operator<< has not been implemented"
    << "}"; return s;

}
