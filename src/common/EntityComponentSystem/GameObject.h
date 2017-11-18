// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_GAMEOBJECT_H
#define GDK_ECS_GAMEOBJECT_H

//gkd inc
#include "EntityComponentSystem/Component.h"
#include "EntityComponentSystem/Scene.h"
#include "Math/Quaternion.h"
#include "Math/Vector3.h"
//std inc
#include <iosfwd>
#include <memory>
#include <string>
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
            friend std::ostream &operator<< (std::ostream &, const ECS::GameObject &) noexcept;
            friend GDK::ECS::Scene;
            
            // Data members
            std::string m_Name = "Unnamed";
            std::weak_ptr<Scene> m_MyScene = {};
            std::vector<std::shared_ptr<Component>> m_Components = {};
            
            Math::Vector3    m_Position = Math::Vector3::Zero;
            Math::Vector3    m_Scale    = {1.f,1.f,1.f};
            Math::Quaternion m_Rotation = Math::Quaternion::Identity;
            
            void update() const noexcept;
            void fixedUpdate() const noexcept;
            
        public:
            // Accessors
            std::string getName() const noexcept;
            Math::Vector3 getPosition() const noexcept;
            Math::Vector3 getScale() const noexcept;
            Math::Quaternion getRotation() const noexcept;
            std::weak_ptr<Scene> getScene() const noexcept;
            std::weak_ptr<Component> getComponent(const size_t aIndex) const noexcept;
            size_t const &&getComponentCount() const noexcept;
            
            void setName(const std::string &aName) noexcept;
            void setPosition(const Math::Vector3 &) noexcept;
            void setPosition(const float aX,const float aY, const float aZ) noexcept;
            void setScale(const Math::Vector3 &) noexcept;
            void setRotation(const Math::Quaternion &) noexcept;
            
            // Public methods
            template<class T>
            std::weak_ptr<T> addComponent() noexcept
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                if (auto pScene = m_MyScene.lock())
                {
                    std::weak_ptr<GameObject> wpThis = std::weak_ptr<GameObject>(shared_from_this());
                    
                    std::shared_ptr<T> spNewT(new T());
                    std::weak_ptr<T>   wpNewT(spNewT);
                    
                    std::shared_ptr<Component> spNewComponent = std::static_pointer_cast<Component>(spNewT);
                    
                    spNewComponent->m_GameObject = wpThis;
                    spNewComponent->onAddedToGameObject(wpThis);
                    
                    m_Components.push_back(std::static_pointer_cast<Component>(spNewT));
                    
                    pScene->OnComponentAddedToAGameObject(wpNewT);
                    
                    for (auto it = m_Components.begin(), end = m_Components.end()-1; it != end; ++it)
                        (*it)->onOtherComponentAddedToMyGameObject(wpNewT);
                    
                    return wpNewT;
                }
                    
                return {};
            }
            
            template<class T>
            void removeComponent() noexcept
            {
                static_assert(std::is_base_of<Component, T>::value == true, "T must be a kind of component");
                
                if (auto pScene = m_MyScene.lock())
                    for (size_t i = 0; i < m_Components.size(); i++)
                        if (std::dynamic_pointer_cast<T>(m_Components[i]))
                        {
                            std::weak_ptr<Component> removedComponent(m_Components[i]);
                            
                            pScene->OnComponentRemovedFromAGameObject(removedComponent);
                            
                            for(size_t j; j < m_Components.size(); j++)
                                if (j != i)
                                    m_Components[j]->onOtherComponentRemovedFromMyGameObject(removedComponent);
                            
                            m_Components.erase(m_Components.begin()+i);
                        }
            }
            
            template<class T>
            std::weak_ptr<T> getComponent() const noexcept
            {
                for (auto it = m_Components.begin(), end = m_Components.end(); it != end; ++it)
                    if (std::dynamic_pointer_cast<T>(*it))
                        return std::weak_ptr<T>(std::dynamic_pointer_cast<T>(*it));
                
                return {};
            }
            
            template<class T>
            std::vector<std::weak_ptr<T>> getComponents() const noexcept
            {
                std::vector<std::weak_ptr<T>> components;
                
                for (auto it = m_Components.begin(), end = m_Components.end(); it != end; ++it)
                    if (std::dynamic_pointer_cast<T>(*it))
                        components.push_back(std::weak_ptr<T>(std::dynamic_pointer_cast<T>(*it)));
                
                return components;
            }
            
            // Mutating operators
            GameObject &operator=(const GameObject &) noexcept = delete;
            GameObject &operator=(GameObject &&) noexcept = delete;
            
            // Constructors, destructors
        private:
            GameObject(const std::weak_ptr<Scene> &aScene) noexcept;
            GameObject() noexcept = delete;
            GameObject(const GameObject &) noexcept = delete;
            GameObject(GameObject &&) noexcept = delete;
        public:
            ~GameObject() noexcept = default;
        };

        std::ostream &operator<< (std::ostream &, const ECS::GameObject &) noexcept;
    }
}

#endif /* GDK_ECS_GAMEOBJECT_H  */
