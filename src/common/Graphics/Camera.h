// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-08.
#ifndef GDK_GFX_CAMERA_H
#define GDK_GFX_CAMERA_H

//gdk inc
#include "Color.h"
#include "Math/Vector2.h"
#include "Math/Mat4x4.h"
//std inc
#include <iosfwd>

namespace GDK{namespace Math{struct IntVector2;}}
namespace GDK{namespace Math{struct Vector3;}}
namespace GDK{namespace Math{struct Quaternion;}}

namespace GDK
{
    namespace GFX
    {
        /*!
         Position, orientation and perspective from which Model(s) are drawn
         */
        class Camera final
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::Camera&) noexcept;
            
        public:
            /// Describes camera clear behaviour
            enum class ClearMode
            {
                Nothing,
                Color,
                DepthOnly
            };
            /// The camera's projection mode
            enum class ProjectionMode
            {
                Perspective,
                Orthographic
            };
            
        private:
            // Data members
            Math::Mat4x4   m_ViewMatrix        = Math::Mat4x4::Identity;
            Math::Mat4x4   m_ProjectionMatrix  = Math::Mat4x4::Identity;
            
            ClearMode      m_ClearMode         = ClearMode::Color;
            Color          m_ClearColor        = Color::CornflowerBlue;
            
            Math::Vector2  m_ViewportPosition  = Math::Vector2::Zero;
            Math::Vector2  m_ViewportSize      = Math::Vector2(1.,1.);
            
            ProjectionMode m_ProjectionMode    = ProjectionMode::Perspective;
            Math::Vector2  m_OrthoSize         = {10,10};
            float          m_FieldOfView       = 90.;
            float          m_NearClippingPlane = 0.001f;
            float          m_FarClippingPlane  = 20.;
            
            //RenderTexture m_RenderTexture;
            
        public:
            // Accessors
            void setViewportPosition(const Math::Vector2&) noexcept;
            void setViewportPosition(const float &x, const float &y) noexcept;
            Math::Vector2 getViewportPosition() const noexcept;
            
            void setViewportSize(const Math::Vector2&) noexcept;
            void setViewportSize(const float &x, const float &y) noexcept;
            Math::Vector2 getViewportSize() const noexcept;
            
            //void setOrthographicProjection(const Math::Vector2 &aOrthoSize, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio);
            //void setPerspectiveProjection(const float &aFieldOfView, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio);
            const Math::Mat4x4& getProjectionMatrix() const noexcept;
            
            void setViewMatrix(const Math::Vector3 &aWorldPos, const Math::Quaternion &aRotation) noexcept;
            const Math::Mat4x4& getViewMatrix() const noexcept;
            
            // Public methods
            void draw(const Math::IntVector2& aFrameBufferSize);
            
            // Mutating operators
            Camera& operator=(const Camera&) = delete;
      
            // Constructors, destructors
            Camera() noexcept;
            Camera(const Camera&) = delete;
            Camera(Camera&&) noexcept = default;
            ~Camera() noexcept = default;
            
        };

        std::ostream& operator<< (std::ostream&, const GFX::Camera&) noexcept;
        
    }

}

#endif /* GDK_GFX_CAMERA_H  */
