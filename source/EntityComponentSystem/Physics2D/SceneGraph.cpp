// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#include "SceneGraph.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS;
using namespace GDK::ECS::Physics2D;

std::ostream& GDK::ECS::Physics2D::operator<<(std::ostream& s, const GDK::ECS::Physics2D::SceneGraph& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "SceneGraph's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void ECS::Physics2D::SceneGraph::draw(const Math::IntVector2 &aFrameBufferSize)
{


}

void ECS::Physics2D::SceneGraph::fixedUpdate()
{


}

void ECS::Physics2D::SceneGraph::update()
{


}

void ECS::Physics2D::SceneGraph::OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &a)
{


}

void ECS::Physics2D::SceneGraph::OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &a)
{


}
