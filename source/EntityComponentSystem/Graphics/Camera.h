// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_CAMERA_H
#define GDK_ECS_GFX_CAMERA_H

//gdk inc
#include "EntityComponentSystem/Graphics/GraphicsComponent.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        namespace GFX
        {
            /*!
            No description provided for Camera
            */
            class Camera final : public GraphicsComponent
            {
                friend std::ostream& operator<< (std::ostream&, const ECS::GFX::Camera&);
      
            protected:
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;
      
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::Camera&);
        
        }
        
    }

}

#endif /* GDK_ECS_GFX_CAMERA_H  */
