// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-08-02.
#ifndef GDK_ECS_PHYSICS2D_SIMPLECOLLIDER_H
#define GDK_ECS_PHYSICS2D_SIMPLECOLLIDER_H

//gdk inc
#include "EntityComponentSystem/Physics2D/Collider.h"
//3rdpart
#include <Collision/Shapes/b2Shape.h>
#include <Box2D/Dynamics/b2Fixture.h>
//std inc
#include <iosfwd>
#include <vector>

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            No description provided for SimpleCollider component
            */
            template<typename T>
            class SimpleCollider : public Collider
            {
                static_assert(std::is_base_of<b2Shape, T>::value == true, "T must be a kind of Shape");
                
            protected:
                // Data members
                T m_Shape;
                b2FixtureDef m_FixtureDefinition;
                
                virtual void buildShape() override
                {
                    m_FixtureDefinition.density = getDensity();
                    m_FixtureDefinition.friction = getFriction();
                    m_FixtureDefinition.restitution = getRestitution();
                    m_FixtureDefinition.isSensor = getColliderType() == Collider::Type::Trigger ? true : false;
                    
                }
                
            public:
                // Accessors
                virtual std::vector<b2FixtureDef> getFixtures() override final {return {m_FixtureDefinition};}
                
                // Public methods

                // Constructors, destructors
                SimpleCollider(const std::weak_ptr<GameObject> &a) : Collider(a){}

            };
            
        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_SIMPLECOLLIDER_H  */
