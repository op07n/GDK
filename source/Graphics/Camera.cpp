// © ${YEAR} Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on ${DATE}.
#include "Camera.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Camera& a)
{
    s.clear();
    s << "{" 
    << "Camera's operator<< has not been implemented" 
    << "}";
    return s;

}

