// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "SceneGraph.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream &s, const ECS::SceneGraph &a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << "SceneGraph's: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

SceneGraph::SceneGraph(Scene *a)
: m_MyScene(a)
{}
