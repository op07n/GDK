// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-08-01.
#ifndef GDK_ECS_PHYSICS2D_COLLIDER_H
#define GDK_ECS_PHYSICS2D_COLLIDER_H

//gdk inc
#include "EntityComponentSystem/Component.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
//std inc
#include <iosfwd>
#include <vector>

class b2FixtureDef;

namespace GDK{namespace ECS{namespace Physics2D{class SceneGraph;}}}
namespace GDK{namespace ECS{namespace Physics2D{class Rigidbody; }}}

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
             Abstract baseclass of all collider components
            */
            class Collider : public Component
            {
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::Collider&);
                friend Physics2D::SceneGraph;
                friend Physics2D::Rigidbody;
                /*!
                 Is this a physics object or is it used to detect physics objects? 
                */
            public:
                enum class Type
                {
                    Collidable,
                    Trigger,
                    
                };
                
            private:
                // Data members
                Math::Vector2 m_Offset;
                
                bool m_RebuildShape = false;
                bool m_DrawDebugLines = true;
                
                Math::Vector3 b_ScaleBuffer;
                
                //fixture def data
                float m_Friction = 0.2f;
                float m_Restitution = 0.0f;
                float m_Density = 1.0f;
                
                Collider::Type m_ColliderType = Collider::Type::Collidable;
                
                void checkForTransformScaleChange();
                
            protected:
                void requestShapeRebuildOnNextTick(){m_RebuildShape = true;}
                
                // Component interface
                virtual void initialize() override final;
                virtual void update() override final;
                virtual void fixedUpdate() override final {}
                
                // Collider interface
                virtual std::vector<b2FixtureDef> getFixtures() = 0;
                virtual void buildShape() = 0;
                
            public:
                // Accessors
                Collider::Type getType() const;
                float getDensity() const;
                float getFriction() const;
                float getRestitution() const;
                Math::Vector2 getOffset() const;
                bool  getDrawDebugLines() const;
                Collider::Type getColliderType() const;
                
                void setType(const Collider::Type &aColliderType);
                void setDensity(const float &aDensity);
                void setFriction(const float &aFriction);
                void setRestitution(const float &aRestitution);
                void setOffset(const float &aX, const float &aY);
                void setDrawDebugLines(const bool &a);
                
                // Constructors, destructors
                Collider(const std::weak_ptr<GameObject> &a) : Component(a) {}

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::Collider&);

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_COLLIDER_H  */
