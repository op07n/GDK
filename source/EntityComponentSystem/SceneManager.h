// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_ECS_SCENEMANAGER_H
#define GDK_ECS_SCENEMANAGER_H

//gdk inc
#include "EntityComponentSystem/Scene.h"
//std inc
#include <iosfwd>
#include <string>
#include <memory>
#include <map>

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for SceneManager
         */
        class SceneManager final
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::SceneManager&);
      
            // Data members
            std::map<std::string, std::shared_ptr<Scene>> m_Scenes;

        public:
            // Accessors
            std::weak_ptr<Scene> addScene(const std::string &aName);
            std::weak_ptr<Scene> getScene(const std::string &aName);
            
            // Public methods
            void erase(const std::string &aName);
            
            void update();
            void fixedUpdate();
            void draw(const Math::IntVector2 &aFrameBufferSize);
            
            // Mutating operators
            SceneManager& operator=(const SceneManager&) = delete;
      
            // Constructors, destructors
            SceneManager() = default;
            SceneManager(const SceneManager&) = delete;
            SceneManager(SceneManager&&) = default;
            ~SceneManager() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::SceneManager&);
        
    }

}

#endif /* GDK_ECS_SCENEMANAGER_H  */
