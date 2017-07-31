// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include ".h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Listener;

std::ostream& GDK::ECS::Listener::operator<<(std::ostream& s, const GDK::ECS::Listener::& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "'s: " << "operator<< has not been implemented"
    << "}"; return s;

}
