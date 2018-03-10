// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "Source.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Audio;

static constexpr char TAG[] = "Source";

std::ostream &GDK::ECS::Audio::operator<<(std::ostream &s, const GDK::ECS::Audio::Source &a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

void Source::initialize()
{

}

void Source::update()
{

}

void Source::fixedUpdate()
{

}
