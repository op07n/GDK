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
            std::weak_ptr<Transform>  m_Transform;
            
            bool m_DidInit = false;

        protected:
            virtual void initialize()  = 0;
            virtual void update()      = 0;
            virtual void fixedUpdate() = 0;
            
        public:
            // Accessors
            
            
            // Public methods
            
            
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
