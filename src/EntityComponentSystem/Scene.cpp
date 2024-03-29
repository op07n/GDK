// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#include "Scene.h"
//gdkinc
#include "Debug/Exception.h"
#include "Debug/Logger.h"
#include "GameObject.h"
#include "SceneGraph.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

static constexpr char TAG[] = "Scene";

std::ostream &GDK::ECS::operator<<(std::ostream &s, const ECS::Scene &a)
{
    s.clear(); s
    << "{"
    << "Scene's: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

std::weak_ptr<GameObject> Scene::getGameObject(const std::string &aGameObjectName) const
{
    for (auto pGameObject : m_GameObjects)
        if (pGameObject->getName() == aGameObjectName)
            return std::weak_ptr<GameObject>(pGameObject);
    
    return std::weak_ptr<GameObject>();
}

std::weak_ptr<GameObject> Scene::addGameObject()
{
    m_GameObjects.push_back(std::shared_ptr<GameObject>(new GameObject(std::weak_ptr<Scene>(shared_from_this()))));
    
    return m_GameObjects.back();
}

void Scene::draw(const Math::IntVector2 &aFrameBufferSize)
{
    for(auto pSceneGraph : m_SceneGraphs)
        pSceneGraph->draw(aFrameBufferSize);
}

void Scene::fixedUpdate()
{
    switch(m_SceneState)
    {
        case State::Active:
            for(auto pGameObject : m_GameObjects)
                pGameObject->fixedUpdate();
            
            for (auto pScene : m_SceneGraphs)
                pScene->fixedUpdate();
            
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
            for(auto pGameObject : m_GameObjects)
                pGameObject->update();
            
            for(auto pSceneGraph : m_SceneGraphs)
                pSceneGraph->update();
            
            break;
            
        default:
            break;
    }
}

void Scene::OnComponentAddedToAGameObject(const std::weak_ptr<Component> &aComponent)
{
    //parseRequireSceneGraphsAnnotation(aComponent);
    
    for (auto pSceneGraph : m_SceneGraphs)
        pSceneGraph->OnComponentAddedToAGameObject(aComponent);
}

void Scene::OnComponentRemovedFromAGameObject(const std::weak_ptr<Component> &)
{
    throw GDK::Exception(TAG, "OnComponentAddedToAGameObject not supported");
}

void Scene::OnSceneGraphAdded(const std::weak_ptr<SceneGraph> &aSceneGraph)
{
    throw GDK::Exception(TAG, "OnSceneGraphRemoved not supported");
}

void Scene::OnSceneGraphRemoved(const std::weak_ptr<SceneGraph> &aSceneGraphRemoved)
{
    throw GDK::Exception(TAG, "OnSceneGraphRemoved not supported");
}

void Scene::logError()
{
    Debug::error(TAG, "user attempted to add a duplicate kind of scenegraph to the scene: ",m_Name);
}

Scene::Scene(const std::string &aName)
: m_Name(aName)
{}
