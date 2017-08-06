// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_SCENEGRAPH_H
#define GDK_ECS_PHYSICS2D_SCENEGRAPH_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
#include "Physics2D/Dynamics/b2World.h"
//std inc
#include <iosfwd>
#include <vector>
#include <memory>

namespace GDK{namespace ECS{namespace Physics2D{class Rigidbody;}}}
class b2Body;

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
                friend Rigidbody;
                
                // Data members
                const float c_UpdateInterval;
                
                b2World m_B2DWorld;
                b2Body  *m_WorldOriginBody;
                
                std::vector<std::weak_ptr<Rigidbody>> m_Rigidbodies;
                
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
                SceneGraph(Scene *a);

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::SceneGraph&);

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_SCENEGRAPH_H  */
