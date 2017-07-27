// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_COMPONENT_H
#define GDK_ECS_COMPONENT_H

//gdk inc
//#include "UniformCollection.h"
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
         No description provided for Component
         */
        class Component
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Component&);
            //friend ???
			
            // Data members
            std::weak_ptr<GameObject> m_GameObject;
            //std::weak_ptr<Transform>  m_Transform;
            bool m_DidInit = false;

            ///called before being added to gameobject
            void OnAddedToGameObjectSuper(const std::weak_ptr<GameObject>& aGameObject);
            ///called before being removed from gameobject
            void OnRemovedFromGameObjectSuper();
            
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
            //std::weak_ptr<Transform>  getTransform() {return m_Transform; }
            
            // Mutating operators
            Component& operator=(const Component&) = delete;
			
            // Constructors, destructors
            Component() = delete;
            Component(const Component&) = delete;
            Component(Component&&) = delete;
            ~Component() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::Component&);
        
	}

}

#endif /* GDK_ECS_COMPONENT_H  */
