// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_ECS_SCENEMANAGER_H
#define GDK_ECS_SCENEMANAGER_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        /*!
         No description provided for SceneManager
         */
        class SceneManager final
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::SceneManager&);
      
            // Data members

        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            SceneManager& operator=(const SceneManager&) = delete;
      
            // Constructors, destructors
            SceneManager() = delete;
            SceneManager(const SceneManager&) = delete;
            SceneManager(SceneManager&&) = delete;
            ~SceneManager() = delete;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::SceneManager&);
        
    }

}

#endif /* GDK_ECS_SCENEMANAGER_H  */
