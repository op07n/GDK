// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "Component.h"
//gdk inc
#include "GameObject.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

static constexpr char TAG[] = "Component";

std::ostream &GDK::ECS::operator<<(std::ostream &s, const ECS::Component &a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

std::weak_ptr<GameObject> Component::getGameObject() const
{
    return m_GameObject;
}
