// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENE_H
#define GDK_ECS_SCENE_H

//std inc
#include <iosfwd>
#include <memory>
#include <string>

namespace GDK{namespace ECS{class GameObject;}}
namespace GDK{namespace ECS{class Component;}}

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
            friend GameObject;
			
            // Data members

            void OnComponentAddedToAGameObject(const std::weak_ptr<Component>&);
            void OnComponentRemovedFromAGameObject(const std::weak_ptr<Component>&);
            ///used to get weak ptr to "this"
            std::weak_ptr<GameObject> getGameObject(const GameObject*);
            
        public:
            // Accessors
            std::weak_ptr<GameObject> getGameObject(const std::string&);
			
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
