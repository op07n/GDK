// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "SceneGraph.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::SceneGraph& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "SceneGraph's: " << "operator<< has not been implemented"
    << "}"; return s;

}

SceneGraph::SceneGraph(Scene *a)
: m_MyScene(a)
{}
