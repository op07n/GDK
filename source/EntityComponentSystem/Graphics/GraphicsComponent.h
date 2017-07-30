// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_GRAPHICSCOMPONENT_H
#define GDK_ECS_GFX_GRAPHICSCOMPONENT_H

//gdk inc
#include "EntityComponentSystem/Component.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        namespace GFX
        {
            /*!
             No description provided for GraphicsComponent
             */
            class GraphicsComponent : public ECS::Component
            {
                friend std::ostream& operator<< (std::ostream&, const ECS::GFX::GraphicsComponent&);
                
            protected:
                GraphicsComponent(const std::weak_ptr<GameObject> &aGameObject);
                
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::GraphicsComponent&);
            
        }
        
    }

}

#endif /* GDK_ECS_GFX_GRAPHICSCOMPONENT_H  */
