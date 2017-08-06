// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_GAMEOBJECT_H
#define GDK_ECS_GAMEOBJECT_H

//gkd inc
#include "Math/Vector3.h"
#include "Math/Quaternion.h"
#include "EntityComponentSystem/Scene.h"
#include "EntityComponentSystem/Component.h"
//std inc
#include <iosfwd>
#include <string>
#include <memory>
#include <vector>

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
            std::string m_Name = "Unnamed";
            std::weak_ptr<Scene> m_MyScene;
            std::vector<std::shared_ptr<Component>> m_Components  = {};
            
            Math::Vector3    m_Position = Math::Vector3::Zero;
            Math::Vector3    m_Scale    = {1.f,1.f,1.f};
            Math::Quaternion m_Rotation = Math::Quaternion::Identity;
            
            void update();
            void fixedUpdate();
            
        public:
            // Accessors
            std::string getName();
            Math::Vector3 getPosition();
            Math::Vector3 getScale();
            Math::Quaternion getRotation();
            std::weak_ptr<Scene> getScene();
            std::weak_ptr<Component> getComponent(const size_t &aIndex);
            size_t getComponentCount();
            
            void setName(const std::string &aName);
            void setPosition(const Math::Vector3&);
            void setPosition(const float &aX,const float &aY, const float &aZ);
            void setScale(const Math::Vector3&);
            void setRotation(const Math::Quaternion&);
            
            // Public methods
            template<class T>
            std::weak_ptr<T> addComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                if (auto scene = m_MyScene.lock())
                {
                    std::shared_ptr<T> spNewT(new T(std::weak_ptr<GameObject>(shared_from_this())));
                    std::weak_ptr<T> wpNewT(spNewT);
                    
                    m_Components.push_back(std::static_pointer_cast<Component>(spNewT));
                    
                    scene->OnComponentAddedToAGameObject(wpNewT);
                    
                    for(size_t i = 0,s = m_Components.size()-1; i < s; i++)
                        m_Components[i]->onOtherComponentAddedToMyGameObject(wpNewT);
                    
                    return wpNewT;
                    
                }
                    
                return {};
                
            }
            
            template<class T>
            void removeComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                if (auto scene = m_MyScene.lock())
                    for (size_t i=0;i<m_Components.size();i++)
                        if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        {
                            std::weak_ptr<Component>removedComponent(m_Components[i]);
                            
                            scene->OnComponentRemovedFromAGameObject(removedComponent);
                            
                            for(size_t j;j<m_Components.size();j++)
                                if (j != i)
                                    m_Components[j]->onOtherComponentRemovedFromMyGameObject(removedComponent);
                            
                            m_Components.erase(m_Components.begin()+i);
                            
                        }
                
            }
            
            template<class T>
            std::weak_ptr<T> getComponent()
            {
                for (size_t i=0;i<m_Components.size();i++)
                    if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        return std::weak_ptr<T>(std::dynamic_pointer_cast<T>(m_Components[i]));
                
                return {};
                
            }
            
            template<class T>
            std::vector<std::weak_ptr<T>> getComponents()
            {
                std::vector<std::weak_ptr<T>> components;
                
                //for (size_t i=0;i<m_Components.size();i++)
                //    if (std::dynamic_pointer_cast<T>(m_Components[i]))//if (auto currentComponent = std::dynamic_pointer_cast<T>(m_Components[i]))
               //         components.push_back(std::weak_ptr<T>(m_Components[i]));
                
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
