// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_ECS_GFX_CAMERA_H
#define GDK_ECS_GFX_CAMERA_H

//gdk inc
#include "EntityComponentSystem/Graphics/GraphicsComponent.h"
#include "Graphics/Camera.h"
//std inc
#include <iosfwd>

namespace GDK{namespace ECS{namespace GFX{class GraphicsScene;}}}

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
                friend GDK::ECS::GFX::GraphicsScene;
                
                GDK::GFX::Camera m_Camera;
                
                void draw(const Math::IntVector2& aFrameBufferSize);
                
            protected:
                virtual void initialize()  override final;
                virtual void update()      override final;
                virtual void fixedUpdate() override final;
      
            public:
                // Accessors
                void setViewportPosition(const Math::Vector2&);
                void setViewportPosition(const float &x, const float &y);
                Math::Vector2 getViewportPosition();
                
                void setViewportSize(const Math::Vector2&);
                void setViewportSize(const float &x, const float &y);
                Math::Vector2 getViewportSize();
                
                const Math::Mat4x4& getProjectionMatrix() const;
                
                void setViewMatrix(const Math::Vector3 &aWorldPos, const Math::Quaternion &aRotation);
                const Math::Mat4x4& getViewMatrix() const;
                
                // Constructors, destructors
                Camera(const std::weak_ptr<GameObject> &a) : GraphicsComponent(a) {};
                
            };

            std::ostream& operator<< (std::ostream&, const ECS::GFX::Camera&);
        
        }
        
    }

}

#endif /* GDK_ECS_GFX_CAMERA_H  */
