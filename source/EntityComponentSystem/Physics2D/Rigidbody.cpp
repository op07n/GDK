// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "Rigidbody.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Physics2D;

std::ostream& GDK::ECS::Physics2D::operator<<(std::ostream& s, const GDK::ECS::Physics2D::Rigidbody& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Rigidbody's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Rigidbody::initialize()
{


}

void Rigidbody::update()
{


}

void Rigidbody::fixedUpdate()
{


}
