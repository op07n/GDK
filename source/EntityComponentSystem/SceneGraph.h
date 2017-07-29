// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENEGRAPH_H
#define GDK_ECS_SCENEGRAPH_H

//std inc
#include <iosfwd>

namespace GDK{namespace ECS{class Scene;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         Defines a scene capability. ECS abstraction of a Renderer or Physics Engine etc.
         */
        class SceneGraph
        {
            friend std::ostream& operator<< (std::ostream&, const ECS::SceneGraph&);
            friend Scene;
      
            // Data members
            Scene* m_MyScene;
            
            virtual void draw()        = 0;
            virtual void fixedUpdate() = 0;
            virtual void update()      = 0;
            
            virtual void OnComponentAddedToAGameObject()     = 0;
            virtual void OnComponentRemovedFromAGameObject() = 0;
            
        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            SceneGraph& operator=(const SceneGraph&) = delete;
      
            // Constructors, destructors
        private:
            SceneGraph(Scene*);
        public:
            SceneGraph() = delete;
            SceneGraph(const SceneGraph&) = delete;
            SceneGraph(SceneGraph&&) = delete;
            virtual ~SceneGraph() = default;
      
        };

        std::ostream& operator<< (std::ostream&, const ECS::SceneGraph&);
        
    }

}

#endif /* GDK_ECS_SCENEGRAPH_H  */
