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

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::Component& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Component's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void Component::OnAddedToGameObjectSuper(const std::weak_ptr<GameObject>& aGameObject)
{
    m_GameObject = aGameObject;
    //m_Transform  = aGameObject.get().getTransform();
    
}

void Component::OnRemovedFromGameObjectSuper()
{
    m_GameObject = std::weak_ptr<GameObject>();

}

std::weak_ptr<GameObject> Component::getGameObject(){return m_GameObject;}
