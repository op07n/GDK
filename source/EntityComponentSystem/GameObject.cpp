// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "GameObject.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::GameObject& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "GameObject's: " << "operator<< has not been implemented"
    << "}"; return s;

}
