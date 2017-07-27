// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_GAMEOBJECT_H
#define GDK_ECS_GAMEOBJECT_H

//std inc
#include <iosfwd>

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

        public:
            // Accessors
			
            // Public methods
			
            // Mutating operators
            GameObject& operator=(const GameObject&) = delete;
			
            // Constructors, destructors
            GameObject() = delete;
            GameObject(const GameObject&) = delete;
            GameObject(GameObject&&) = delete;
            ~GameObject() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::GameObject&);
        
	}

}

#endif /* GDK_ECS_GAMEOBJECT_H  */
