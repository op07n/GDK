// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_COMPONENT_H
#define GDK_ECS_COMPONENT_H

//gdk inc
#include "EntityComponentSystem/GameObject.h"
//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace ECS{class GameObject;}}
namespace GDK{namespace ECS{class Transform;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         Encapsulates behaviour and data used to manipulate GameObjects
         */
        class Component
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Component&);
            friend GDK::ECS::GameObject;
			
            // Data members
            std::weak_ptr<GameObject> m_GameObject;
            bool m_DidInit = false;
            
        protected:
            ///called once per component instance, as early as possible
            virtual void initialize();
            ///called every update frame
            virtual void update();
            ///called every fixedupdate frame
            virtual void fixedUpdate();
            
        public:
            // Accessors
            std::weak_ptr<GameObject> getGameObject();
            
            // Mutating operators
            Component& operator=(const Component&) = delete;
			
            // Constructors, destructors
        private:
            Component(const std::weak_ptr<GameObject>&);
        public:
            Component(const Component&) = delete;
            Component(Component&&) = delete;
            ~Component() = default;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::Component&);
        
	}

}

#endif /* GDK_ECS_COMPONENT_H  */
