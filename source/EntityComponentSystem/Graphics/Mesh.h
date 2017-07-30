// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_MESH_H
#define GDK_ECS_GFX_MESH_H

//GDK inc
#include "EntityComponentSystem/Graphics/GraphicsComponent.h"
#include "EntityComponentSystem/Graphics/GraphicsScene.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        namespace GFX
        {
            /*!
            No description provided for Mesh
            */
            class Mesh final : public GraphicsComponent, public GraphicsScene::Drawable
            {
                friend std::ostream& operator<< (std::ostream&, const ECS::GFX::Mesh&);
                
            protected:
                // Drawable interface
                virtual void draw(const std::weak_ptr<Camera> &aCamera) override final;
                // Component interface
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;
      
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::Mesh&);
            
        }
        
    }

}

#endif /* GDK_ECS_GFX_MESH_H  */
