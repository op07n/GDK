// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "GameObject.h"
//gdk inc
#include "Component.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::GameObject& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "GameObject's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void GameObject::update()
{
    for(size_t i=0, s=m_Components.size();i<s;i++)
        if (m_Components[i])
        {
            if (!m_Components[i]->m_DidInit)
            {
                m_Components[i]->initialize();
                m_Components[i]->m_DidInit = true;
                
            }
            
            m_Components[i]->update();
            
        }
    
}

void GameObject::fixedUpdate()
{
    for(size_t i=0, s=m_Components.size();i<s;i++)
        if (m_Components[i])
        {
            if (!m_Components[i]->m_DidInit)
            {
                m_Components[i]->initialize();
                m_Components[i]->m_DidInit = true;
                
            }
            
            m_Components[i]->fixedUpdate();
            
        }
    
}

std::weak_ptr<Component> GameObject::getComponent(const int &aIndex){return m_Components[aIndex];}
size_t GameObject::getComponentCount(){return m_Components.size();}
std::string GameObject::getName(){return m_Name;}
std::weak_ptr<Scene> GameObject::getScene(){return m_MyScene;}

void GameObject::setName(const std::string &aName){m_Name = aName;}

GameObject::GameObject(Scene *aScene)
{}
