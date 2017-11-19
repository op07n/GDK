// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_RIGIDBODY_H
#define GDK_ECS_PHYSICS2D_RIGIDBODY_H

//gdk inc
#include "EntityComponentSystem/Physics2D/Phy2DSceneGraph.h"
#include "EntityComponentSystem/Component.h"
#include "Physics2D/Dynamics/b2Fixture.h"
#include "Math/Vector3.h"
//std inc
#include <iosfwd>
#include <memory>

class b2Fixture;
class b2PrismaticJoint;

namespace GDK{namespace Math{struct Vector2;}}

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            No description provided for Rigidbody component
            */
            class Rigidbody final : public Component
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::Rigidbody&) noexcept;
                
            public:
                ///Prevent movement along the chosen axis
                enum class AxisFreezeMode
                {
                    X,
                    Y,
                    None
                };
                
                ///Type of rigidbody: does it move? Is it frozen?
                enum class Type
                {
                    Dynamic,
                    Kinematic,
                    Static
                };
                
            private:
                // Data members
                std::weak_ptr<Physics2D::Phy2DSceneGraph> m_MyPhysics2DScene = {};
                
                std::vector<b2Fixture*> m_Fixtures = {};
                b2BodyDef m_BodyDef = {};
                b2Body *m_Body = nullptr;
                b2PrismaticJoint *m_AxisFreezeJoint = nullptr;
                bool m_RebuildRequired  = true;
                
                Math::Vector3 m_ScaleBuffer    = Math::Vector3::Zero;
                Math::Vector3 m_RotationBuffer = Math::Vector3::Zero;
                Math::Vector3 m_PositionBuffer = Math::Vector3::Zero;
                
                void buildBody();
                void buildFixtures();
                void deleteAndClearFixtures();
                
            protected:
                // Component interface
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;
                
                virtual void onOtherComponentAddedToMyGameObject(const std::weak_ptr<Component> &aNewComponent) override final;
                virtual void onOtherComponentRemovedFromMyGameObject(const std::weak_ptr<Component> &aOtherComponent) override final;
                
                virtual void onAddedToGameObject(const std::weak_ptr<GameObject> &) override final;
                
            public:
                // Accessors
                Math::Vector2 getVelocity() const;
                
                void setVelocity(const Math::Vector2 &);
                void setVelocity(const float aX,const float aY);
                
                void setVelocityX(const float aX);
                void setVelocityY(const float aY);
                
                void normalizeVelocity();
                void scaleVelocity(const float aScalar);
                
                void applyImpulse(const float aX,const float aY);
                
                void applyForce(const Math::Vector2 &aForce);
                void applyForce(const float aX,const float aY);
                
                void applyTorque(const float aTorque);
                
                void setType(const Type aType);
                
                void freezeRotation(const bool aFreeze);
                
                void setLinearDamping(const float aLinearDamping);
                void setAngularDamping(const float aAngularDamping);
                
                bool isRotationFrozen();
                
                void setLinearVelocity(const float aX, const float aY);
                
                void setPosition(const float aX, const float aY, const float aZ);
                void setPosition(const float aX, const float aY);
                
                void setGravityScale(const float aScalar);
                
                void setRotation(const float aRotation);
                
                void clearForces();
      
                // methods
                void freezeAxis(const AxisFreezeMode);

                // Constructors, destructors
                virtual ~Rigidbody() noexcept;
            };

            std::ostream& operator<< (std::ostream &, const GDK::ECS::Physics2D::Rigidbody &) noexcept;
        }
    }
}

#endif /* GDK_ECS_PHYSICS2D_RIGIDBODY_H  */
