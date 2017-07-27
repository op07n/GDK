// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "Component.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::Component& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Component's: " << "operator<< has not been implemented"
    << "}"; return s;

}
