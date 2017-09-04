// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#include "GraphicsScene.h"
//gdk inc
#include "EntityComponentSystem/Graphics/Camera.h"
#include "EntityComponentSystem/Graphics/GraphicsScene.h"
//std inc
#include <iostream>

using namespace GDK::ECS::GFX;

std::ostream& GDK::ECS::GFX::operator<<(std::ostream& s, const ECS::GFX::GraphicsScene& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "GraphicsScene's: " << "operator<< has not been implemented"
    << "}"; return s;

}

void GraphicsScene::OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    if (auto ptr = a.lock())
    {
        if (auto newDrawable = std::dynamic_pointer_cast<GraphicsScene::Drawable>(ptr))
            m_Drawables.push_back(newDrawable);
        
        else if (auto newCamera = std::dynamic_pointer_cast<Camera>(ptr))
            m_Cameras.push_back(newCamera);
        
    }
    
}

void GraphicsScene::OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &a)
{
    if (auto removedComponent = a.lock())
    {
        if (auto removedDrawable = std::dynamic_pointer_cast<GraphicsScene::Drawable>(removedComponent))
        {
            for (size_t i = 0; i < m_Drawables.size(); i++)
                if (auto currentDrawable = m_Drawables[i].lock())
                    if (currentDrawable == removedDrawable)
                        m_Drawables.erase(m_Drawables.begin()+i);
            
        }
        
        else if (auto removedCamera = std::dynamic_pointer_cast<Camera>(removedComponent))
        {
            for (size_t i = 0; i < m_Cameras.size(); i++)
                if (auto currentCamera = m_Cameras[i].lock())
                    if (currentCamera == removedCamera)
                        m_Cameras.erase(m_Cameras.begin()+i);
            
        }
        
    }
    
}

void GraphicsScene::draw(const Math::IntVector2 &aFrameBufferSize)
{
    for(size_t i = 0, s = m_Cameras.size(); i < s; i++)
    {
        if (auto camera = m_Cameras[i].lock())
            camera->draw(aFrameBufferSize);
        else
            m_Cameras.erase(m_Cameras.begin()+i);
        
        for(size_t j = 0, t = m_Drawables.size(); j < t; j++)
            if (auto drawable = m_Drawables[j].lock())
                drawable->draw(std::weak_ptr<Camera>(m_Cameras[i]));
            else
                m_Drawables.erase(m_Drawables.begin()+j);
        
    }
    
}
