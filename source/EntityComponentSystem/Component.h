// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_COMPONENT_H
#define GDK_ECS_COMPONENT_H

//gdk inc
//#include "EntityComponentSystem/GameObject.h"
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
        class Component //: public std::enable_shared_from_this<GameObject>
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Component&);
            friend GDK::ECS::GameObject;
      
            // Data members
            std::weak_ptr<GameObject> m_GameObject;
            bool m_DidInit = false;
            
        protected:
            ///called once per component instance, as early as possible
            virtual void initialize() = 0;
            ///called every update frame
            virtual void update() = 0;
            ///called every fixedupdate frame
            virtual void fixedUpdate() = 0;
            
            ///Another component was added to my gameobject
            virtual void onOtherComponentAddedToMyGameObject(const std::weak_ptr<Component> &aNewComponent){}
            virtual void onOtherComponentRemovedFromMyGameObject(const std::weak_ptr<Component> &aOtherComponent){}
            
        public:
            // Accessors
            std::weak_ptr<GameObject> getGameObject();
            
            // Mutating operators
            Component& operator=(const Component&) = delete;
      
        protected:
            // Constructors, destructors
            Component(const std::weak_ptr<GameObject>&);
        private:
            Component() = delete;
            Component(const Component&) = delete;
            Component(Component&&) = delete;
        public:
            virtual ~Component() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::Component&);
        
    }

}

#endif /* GDK_ECS_COMPONENT_H  */
