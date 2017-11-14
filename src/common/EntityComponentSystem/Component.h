// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_COMPONENT_H
#define GDK_ECS_COMPONENT_H

//gdk inc

//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace ECS{class GameObject;}}
namespace GDK{namespace ECS{class Transform;}}
namespace GDK{namespace ECS{class Scene;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         Encapsulates behaviour and data used to manipulate GameObjects
         */
        class Component : public std::enable_shared_from_this<Component>
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Component&) noexcept;
            friend GDK::ECS::GameObject;
      
            // Data members
            std::weak_ptr<GameObject> m_GameObject = {};
            bool m_DidInit = false;
            
        protected:
            ///called once per component instance, as early as possible
            virtual void initialize() {}
            ///called every update frame
            virtual void update() {}
            ///called every fixedupdate frame
            virtual void fixedUpdate() {}
            ///Another component was added to my gameobject
            virtual void onOtherComponentAddedToMyGameObject(const std::weak_ptr<Component> &aNewComponent) {}
            ///Another component was removed from my gameobject
            virtual void onOtherComponentRemovedFromMyGameObject(const std::weak_ptr<Component> &aOtherComponent) {}
            ///This component instance was added to a gameobject
            virtual void onAddedToGameObject(const std::weak_ptr<GameObject>&) {}
            //virtual void onRemovedFromGameObject(const std::weak_ptr<GameObject>&) {}
            
        public:
            // Accessors
            std::weak_ptr<GameObject> getGameObject() const noexcept;
            
            // Mutating operators
            Component& operator=(const Component&) = delete;
      
        protected:
            // Constructors, destructors
            Component() noexcept = default;
        private:
            Component(const Component&) = delete;
            Component(Component&&) = delete;
        public:
            virtual ~Component() noexcept = default;
        };

        std::ostream& operator<< (std::ostream&, const ECS::Component&) noexcept;
    }
}

#endif /* GDK_ECS_COMPONENT_H  */
