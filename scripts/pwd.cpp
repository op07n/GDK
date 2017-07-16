// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#include "pwd.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::pwd& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "pwd's: " << "operator<< has not been implemented"
    << "}"; return s;

}
