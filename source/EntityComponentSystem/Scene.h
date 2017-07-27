// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENE_H
#define GDK_ECS_SCENE_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for Scene
         */
        class Scene final
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::Scene&);
			
            // Data members

        public:
            // Accessors
			
            // Public methods
			
            // Mutating operators
            Scene& operator=(const Scene&) = delete;
			
            // Constructors, destructors
            Scene() = delete;
            Scene(const Scene&) = delete;
            Scene(Scene&&) = delete;
            ~Scene() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const ECS::Scene&);
        
	}

}

#endif /* GDK_ECS_SCENE_H  */
