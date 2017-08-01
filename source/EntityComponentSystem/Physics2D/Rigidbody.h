// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_RIGIDBODY_H
#define GDK_ECS_PHYSICS2D_RIGIDBODY_H

//gdk inc
#include "EntityComponentSystem/Component.h"
#include "Debug/Exception.h"
//std inc
#include <iosfwd>

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
                friend std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::Rigidbody&);
      
                // Data members

            protected:
                // Component interface
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;

            public:
                // Accessors
      
                // Public methods

                // Constructors, destructors
                Rigidbody(const std::weak_ptr<GameObject> &a) : Component(a) {throw GDK::Exception("Rigidbody is a stub!");}

            };

            std::ostream& operator<< (std::ostream&, const GDK::ECS::Physics2D::Rigidbody&);

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_RIGIDBODY_H  */
