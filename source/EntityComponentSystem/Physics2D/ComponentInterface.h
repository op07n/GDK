// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H
#define GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H

//gdk inc
#include "Physics2D/CollisionInfo.h"

namespace GDK{namespace ECS{class SceneGraph;}}

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            Implement this interface if you want to listen to physics2d events
            */
            class ComponentInterface
            {
                friend ECS::Physics2D::SceneGraph;
                
                virtual void OnCollisionEnter(const GDK::Physics2D::CollisionInfo&) = 0;
                virtual void OnCollisionExit (const GDK::Physics2D::CollisionInfo&) = 0;
                
            public:
                virtual ~ComponentInterface() = default;
                
            };

        }

    }

}

#endif /* GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H  */
