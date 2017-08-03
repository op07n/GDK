// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_GAMEOBJECT_H
#define GDK_ECS_GAMEOBJECT_H

//gkd inc
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "EntityComponentSystem/Scene.h"
//std inc
#include <iosfwd>
#include <string>
#include <memory>
#include <vector>

namespace GDK{namespace ECS{class Scene;}}
namespace GDK{namespace ECS{class Component;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         GameObject has a list of components and belongs to a scene
         */
        class GameObject final : public std::enable_shared_from_this<GameObject>
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
            friend GDK::ECS::Scene;
            
            // Data members
            std::string m_Name;
            std::weak_ptr<Scene> m_MyScene;
            std::vector<std::shared_ptr<Component>> m_Components;
            
            Math::Vector3 m_Position;
            Math::Vector3 m_Scale;
            Math::Quaternion m_Rotation;
            
            void update();
            void fixedUpdate();
            
        public:
            // Accessors
            std::string getName();
            std::weak_ptr<Scene> getScene();
            size_t getComponentCount();
            std::weak_ptr<Component> getComponent(const int &aIndex);
            
            void setPosition(const Math::Vector3&);
            void setScale   (const Math::Vector3&);
            void setRotation(const Math::Quaternion&);
            
            Math::Vector3    getPosition();
            Math::Vector3    getScale();
            Math::Quaternion getRotation();
            
            void setName(const std::string &aName);
            
            // Public methods
            template<class T>
            std::weak_ptr<T> addComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                //Add an instance of aComponentType to Components[]
                if (auto scene = m_MyScene.lock())
                {
                    auto newT = std::shared_ptr<T>(new T(std::weak_ptr<GameObject>(shared_from_this())));
                    
                    m_Components.push_back(std::static_pointer_cast<Component>(newT));
                    
                    std::weak_ptr<Component> newComponent(m_Components.back());
                    scene->OnComponentAddedToAGameObject(newComponent);
                    return std::weak_ptr<T>(newT);
                    
                }
                    
                return std::weak_ptr<T>();
                
            }
            
            template<class T>
            void removeComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                if (auto scene = m_MyScene.lock())
                    for (size_t i=0;i<m_Components.size();i++)
                        if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        {
                            scene->OnComponentRemovedFromAGameObject(std::weak_ptr<Component>(m_Components[i]));
                            m_Components.erase(m_Components.begin()+i);
                            
                        }
                
            }
            
            template<class T>
            std::weak_ptr<T> getComponent()
            {
                for (size_t i=0;i<m_Components.size();i++)
                    if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        return std::weak_ptr<T>(m_Components[i]);
                
            }
            
            template<class T>
            std::vector<std::weak_ptr<T>> getComponents()
            {
                std::vector<std::weak_ptr<T>> components;
                
                for (size_t i=0;i<m_Components.size();i++)
                    if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        components.push_back(std::weak_ptr<T>(m_Components[i]));
                
                return components;
                
            }
            
            // Mutating operators
            GameObject& operator=(const GameObject&) = delete;
      
            // Constructors, destructors
        private:
            GameObject(const std::weak_ptr<Scene> &aScene);
            GameObject() = delete;
            GameObject(const GameObject&) = delete;
            GameObject(GameObject&&) = delete;
        public:
            ~GameObject() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
    
    }

}

#endif /* GDK_ECS_GAMEOBJECT_H  */
