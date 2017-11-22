// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#include "GraphicsComponent.h"
//std inc
#include <iostream>

using namespace GDK::ECS::GFX;

static constexpr char TAG[] = "GraphicsComponent";

std::ostream &GDK::ECS::GFX::operator<<(std::ostream &s, const ECS::GFX::GraphicsComponent &a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}
