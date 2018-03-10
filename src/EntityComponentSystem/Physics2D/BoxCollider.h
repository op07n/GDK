// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-08-02.
#ifndef GDK_ECS_PHYSICS2D_BOXCOLLIDER_H
#define GDK_ECS_PHYSICS2D_BOXCOLLIDER_H

//gdk inc
#include "EntityComponentSystem/Physics2D/SimpleCollider.h"
#include "EntityComponentSystem/GameObject.h"
#include "Math/Vector3.h"
#include "Physics2D/Collision/Shapes/b2PolygonShape.h"
//std inc
#include <iosfwd>

class b2PolygonShape;

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            No description provided for BoxCollider component
            */
            class BoxCollider final : public SimpleCollider<b2PolygonShape>
            {
                friend std::ostream &operator<< (std::ostream &, const GDK::ECS::Physics2D::BoxCollider &);
                
            protected:
                // Component interface
                virtual void buildShape() override final;
            };

            std::ostream &operator<< (std::ostream &, const GDK::ECS::Physics2D::BoxCollider &);
        }
    }
}

#endif /* GDK_ECS_PHYSICS2D_BOXCOLLIDER_H  */
