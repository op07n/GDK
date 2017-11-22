// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#include "SceneManager.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace ECS;

static constexpr char TAG[] = "SceneManager";

std::ostream &GDK::ECS::operator<<(std::ostream &s, const ECS::SceneManager &a) noexcept
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

std::weak_ptr<Scene> SceneManager::addScene(const std::string &aName) noexcept
{
    auto newScene = std::make_shared<Scene>(Scene(aName));
    m_Scenes.insert({aName,newScene});
    
    return std::weak_ptr<Scene>(newScene);
}

std::weak_ptr<Scene> SceneManager::getScene(const std::string &aName) const
{
    return std::weak_ptr<Scene>(m_Scenes.at(aName));
}

void SceneManager::update()
{
    for (auto &pair : m_Scenes)
        pair.second->update();
}

void SceneManager::fixedUpdate()
{
    for (auto &pair : m_Scenes)
        pair.second->fixedUpdate();
}

void SceneManager::draw(const Math::IntVector2 &aFrameBufferSize)
{
    for (auto &pair : m_Scenes)
        pair.second->draw(aFrameBufferSize);
}

void SceneManager::remove(const std::string &aName) noexcept
{
    m_Scenes.erase(aName);
}
