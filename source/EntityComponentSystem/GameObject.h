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

#include "Debug/Exception.h"

namespace GDK{namespace ECS{class Scene;}}
namespace GDK{namespace ECS{class Component;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for GameObject
         */
        class GameObject final
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
			
            // Data members
            std::string m_Name;
            std::weak_ptr<Scene> m_MyScene;
            std::vector<std::shared_ptr<Component>> m_Components;
            
            Math::Vector3 position;
            Math::Vector3 scale;
            Math::Quaternion rotation;
            
        public:
            // Accessors
            std::string getName();
            std::weak_ptr<Scene> getScene();
            size_t getComponentCount();
            std::weak_ptr<Component> getComponent(const int &aIndex);
            
            void setName(const std::string &aName);
            
            // Public methods
            template<class T>
            std::weak_ptr<T> addComponent()
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                /*//Handle RequireComponent & RequireComponents annotations
                {
                    Annotation[] annotations = aComponentType.getAnnotations();
                    
                    for(int i=0,s=annotations.length;i<s;i++)
                        if (annotations[i].annotationType().equals(RequireComponents.class))
                        {
                            RequireComponents rc = (RequireComponents)annotations[i];
                            
                            for(int j=0,t=rc.value().length;j<t;j++)
                                if (getComponent(rc.value()[j])==null)
                                    addComponent(rc.value()[j]);
                                    
                        }
                        else if (annotations[i].annotationType().equals(RequireComponent.class))
                        {
                            RequireComponent rc = (RequireComponent)annotations[i];
                            
                            if (getComponent(rc.value())==null)
                                addComponent(rc.value());
                                
                        }
                    
                }*/
                
                //Add an instance of aComponentType to Components[]
                if (auto scene = m_MyScene.lock())
                {
                    m_Components.push_back(std::make_shared<Component>(new T(scene->getGameObject(this))));
                    
                    std::weak_ptr<Component> newComponent(m_Components.back());
                    scene->OnComponentAddedToAGameObject(newComponent);
                    return newComponent;
                    
                }
                    
                return std::weak_ptr<Component>();
                
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
            
            void update();
            void fixedUpdate();
			
            // Mutating operators
            GameObject& operator=(const GameObject&) = delete;
			
            // Constructors, destructors
            GameObject(const std::weak_ptr<Scene> &aScene);
            GameObject() = delete;
            GameObject(const GameObject&) = delete;
            GameObject(GameObject&&) = delete;
            ~GameObject() = default;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
        
	}

}

#endif /* GDK_ECS_GAMEOBJECT_H  */
