// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-26.
#ifndef GDK_ECS_SCENEGRAPH_H
#define GDK_ECS_SCENEGRAPH_H

//std inc
#include <iosfwd>
#include <memory>

namespace GDK{namespace ECS{class Scene;}}
namespace GDK{namespace ECS{class Component;}}
namespace GDK{namespace Math{struct IntVector2;}}

namespace GDK
{
    namespace ECS
    {
        /*!
         Defines a scene capability. ECS abstraction of a Renderer or Physics Engine etc.
         */
        class SceneGraph
        {
            friend std::ostream& operator<< (std::ostream &, const ECS::SceneGraph &);
            friend Scene;
      
            // Data members
            Scene *m_MyScene = nullptr;
            
        protected:
            Scene *getMyScene() const {return m_MyScene;}
            
            virtual void draw(const Math::IntVector2 &aFrameBufferSize) = 0;
            virtual void fixedUpdate() = 0;
            virtual void update()      = 0;
            
            virtual void OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component> &) = 0;
            virtual void OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component> &) = 0;
            
        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            SceneGraph &operator=(const SceneGraph &) = delete;
            SceneGraph &operator=(SceneGraph &&) = delete;
      
            // Constructors, destructors
        protected:
            SceneGraph(Scene *);
        private:
            SceneGraph() = delete;
            SceneGraph(const SceneGraph &) = delete;
            SceneGraph(SceneGraph &&) = delete;
        public:
            virtual ~SceneGraph() = default;
      
        };

        std::ostream &operator<< (std::ostream &, const ECS::SceneGraph &);
    }
}

#endif /* GDK_ECS_SCENEGRAPH_H  */
