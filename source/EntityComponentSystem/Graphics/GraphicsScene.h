// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_GRAPHICSSCENE_H
#define GDK_ECS_GFX_GRAPHICSSCENE_H

//gdk inc
#include "EntityComponentSystem/SceneGraph.h"
//std inc
#include <iosfwd>
#include <vector>
#include <memory>

namespace GDK{namespace ECS{namespace GFX{class Camera;}}}

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
                
            public:
                class Drawable
                {
                    friend GraphicsScene;
                    
                protected:
                    virtual void draw(const std::weak_ptr<Camera> &aCamera) = 0;
                    
                public:
                    virtual ~Drawable() = default;
                    
                };
                
            private:
                // Data members
                std::vector<std::weak_ptr<Camera>>   m_Cameras;
                std::vector<std::weak_ptr<Drawable>> m_Drawables;
                
            protected:
                // SceneGraph interface
                virtual void draw()        override final;
                virtual void fixedUpdate() override final;
                virtual void update()      override final;
                
                virtual void OnComponentAddedToAGameObject(const std::weak_ptr<ECS::Component>&)     override final;
                virtual void OnComponentRemovedFromAGameObject(const std::weak_ptr<ECS::Component>&) override final;
                
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::GraphicsScene&);
        
        }
        
    }

}

#endif /* GDK_ECS_GFX_GRAPHICSSCENE_H  */
