// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_GRAPHICSSCENE_H
#define GDK_ECS_GFX_GRAPHICSSCENE_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace ECS
    {
        namespace GFX
        {
            /*!
             No description provided for GraphicsScene
             */
            class GraphicsScene final : public ECS::SceneGraph
            {
                friend std::ostream& operator<< (std::ostream&, const ECS::GFX::GraphicsScene&);

                // Data members
                
            protected:
                
                // SceneGraph interface
                virtual void draw()        override final;
                virtual void fixedUpdate() override final;
                virtual void update()      override final;
                
                virtual void OnComponentAddedToAGameObject()     override final;
                virtual void OnComponentRemovedFromAGameObject() override final;
                
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::GraphicsScene&);
        
        }
        
    }

}

#endif /* GDK_ECS_GFX_GRAPHICSSCENE_H  */
