// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "Listener.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Audio;

std::ostream& GDK::ECS::Audio::operator<<(std::ostream& s, const GDK::ECS::Audio::Listener& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Listener's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Listener::initialize()
{


}

void Listener::update()
{


}

void Listener::fixedUpdate()
{


}
