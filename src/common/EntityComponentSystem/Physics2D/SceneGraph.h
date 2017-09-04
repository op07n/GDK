// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_SCENEGRAPH_H
#define GDK_ECS_PHYSICS2D_SCENEGRAPH_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
#include "Physics2D/Dynamics/b2World.h"
#include "Physics2D/Dynamics/b2WorldCallbacks.h"
//std inc
#include <iosfwd>
#include <vector>
#include <memory>
#include <functional>

namespace GDK{namespace ECS{namespace Physics2D{class Rigidbody;}}}
namespace GDK{namespace ECS{namespace Physics2D{class Collider;}}}
namespace GDK{namespace Physics2D{class CollisionInfo;}}
namespace GDK{namespace Math{class Vector2;}}
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
                
                /*!
                 Hidden interface to b2World, listens for contact events
                 */
                struct ContactListener : public b2ContactListener
                {
                    using CallbackSignature = std::function<void(const bool &isBegin, b2Contact *aContact)>;
                    
                    CallbackSignature ContactHandler;
                    
                    virtual void BeginContact(b2Contact* contact) { ContactHandler(true, contact); }
                    virtual void EndContact(b2Contact* contact)   { ContactHandler(false,contact); }
                    
                };
                
                // Data members
                const float c_UpdateInterval = 1.f/60.f;
                
                std::vector<std::weak_ptr<Rigidbody>> m_Rigidbodies      = {};
                b2World                               m_B2DWorld         = b2World(b2Vec2(0,0));
                b2Body                                *m_WorldOriginBody = nullptr;
                ContactListener                       m_ContactListener  = {};
                
                void handleContact(const bool &isBegin, b2Contact *aContact);
                
                void invokeOnTriggerEnter  (const std::weak_ptr<Collider>&,const GDK::Physics2D::CollisionInfo&);
                void invokeOnTriggerExit   (const std::weak_ptr<Collider>&,const GDK::Physics2D::CollisionInfo&);
                void invokeOnCollisionEnter(const std::weak_ptr<Collider>&,const GDK::Physics2D::CollisionInfo&);
                void invokeOnCollisionExit (const std::weak_ptr<Collider>&,const GDK::Physics2D::CollisionInfo&);
                
            protected:
                // SceneGraph interface
                virtual void draw(const Math::IntVector2 &aFrameBufferSize) override final {}
                virtual void fixedUpdate() override final;
                virtual void update()      override final {};
                
                virtual void OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component>&)     override final;
                virtual void OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component>&) override final;

            public:
                // Accessors
                void setGraivty(const Math::Vector2&);
      
                // Public methods

                // Constructors, destructors
                SceneGraph(Scene *a);

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::SceneGraph&);

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_SCENEGRAPH_H  */
