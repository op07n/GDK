// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_SCENEGRAPH_H
#define GDK_ECS_PHYSICS2D_SCENEGRAPH_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
#include "Debug/Exception.h"
//std inc
#include <iosfwd>

namespace GDK{namespace Physics2D{class CollisionInfo;}}

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            No description provided for SceneGraph scenegraph
            */
            class SceneGraph final : public ECS::SceneGraph
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::SceneGraph&);
                
                // Data members

            protected:
                // SceneGraph interface
                virtual void draw(const Math::IntVector2 &aFrameBufferSize) override final;
                virtual void fixedUpdate() override final;
                virtual void update()      override final;
                
                virtual void OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component>&)     override final;
                virtual void OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component>&) override final;

            public:
                // Accessors
      
                // Public methods

                // Constructors, destructors
                SceneGraph(Scene *a) : ECS::SceneGraph(a){throw GDK::Exception("Physics2D::SceneGraph is a stub!");}

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::SceneGraph&);

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_SCENEGRAPH_H  */
