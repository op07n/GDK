// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-31.
#ifndef GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H
#define GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H

//gdk inc
#include "EntityComponentSystem/Physics2D/CollisionInfo.h"

namespace GDK{namespace ECS{class SceneGraph;}}

namespace GDK
{
    namespace ECS
    {
        namespace Physics2D
        {
            /*!
            Implement this interface if you want your component to listen to physics2d events
            */
            class ComponentInterface
            {
                friend ECS::Physics2D::Phy2DSceneGraph;
                
                virtual void OnTriggerEnter(const GDK::Physics2D::CollisionInfo &) {}
                virtual void OnTriggerExit (const GDK::Physics2D::CollisionInfo &) {}
                
                virtual void OnCollisionEnter(const GDK::Physics2D::CollisionInfo &) {}
                virtual void OnCollisionExit (const GDK::Physics2D::CollisionInfo &) {}
                
            public:
                virtual ~ComponentInterface() = default;
            };
        }
    }
}

#endif /* GDK_ECS_PHYSICS2D_COMPONENTINTERFACE_H  */
