// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#include "GraphicsScene.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;
using namespace GFX;

std::ostream& GDK::ECS::GFX::operator<<(std::ostream& s, const ECS::GFX::GraphicsScene& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "GraphicsScene's: " << "operator<< has not been implemented"
    << "}"; return s;

}
