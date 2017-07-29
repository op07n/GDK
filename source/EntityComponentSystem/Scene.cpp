// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "Scene.h"
//gdkinc
#include "GameObject.h"
#include "SceneGraph.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

std::ostream& GDK::ECS::operator<<(std::ostream& s, const ECS::Scene& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Scene's: " << "operator<< has not been implemented"
    << "}"; return s;

}

std::weak_ptr<GameObject> Scene::getGameObject(const std::string &aGameObjectName)
{
    for(size_t i = 0, s = m_GameObjects.size(); i < s; i++)
        if (m_GameObjects[i]->getName() == aGameObjectName)
            return std::weak_ptr<GameObject>(m_GameObjects[i]);
    
    return std::weak_ptr<GameObject>();
    
}

std::weak_ptr<GameObject> Scene::addGameObject()
{
    m_GameObjects.push_back(std::shared_ptr<GameObject>(new GameObject(this)));
    return m_GameObjects.back();
    
}

void Scene::draw()
{
    for(size_t i = 0, s = m_SceneGraphs.size(); i < s; i++)
        m_SceneGraphs[i]->draw();
    
}

void Scene::fixedUpdate()
{
    switch(m_SceneState)
    {
        case State::Active:
        for(size_t i = 0, s = m_GameObjects.size(); i < s; i++)
            m_GameObjects[i]->fixedUpdate();
            
        for(size_t i = 0, s = m_SceneGraphs.size(); i < s; i++)
            m_SceneGraphs[i]->fixedUpdate();
        break;
            
        default:
        break;
            
    }
    
}

void Scene::update()
{
    switch(m_SceneState)
    {
        case State::Active:
        for(size_t i = 0, s = m_GameObjects.size(); i < s; i++)
            m_GameObjects[i]->update();
            
        for(size_t i = 0, s = m_SceneGraphs.size(); i < s; i++)
            m_SceneGraphs[i]->update();
        break;
            
        default:
        break;
            
    }
    
}

void Scene::OnSceneGraphAdded(const std::weak_ptr<SceneGraph> &aSceneGraph)
{
    throw GDK::Exception("OnSceneGraphRemoved not supported");
    
}

void Scene::OnSceneGraphRemoved(const std::weak_ptr<SceneGraph> &aSceneGraphRemoved)
{
    throw GDK::Exception("OnSceneGraphRemoved not supported");
    
}
