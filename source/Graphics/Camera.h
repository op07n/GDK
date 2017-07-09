// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-08.
#ifndef GDK_GFX_CAMERA_H
#define GDK_GFX_CAMERA_H

//gdk inc
#include "Color.h"
#include "../Math/IntVector2.h"
//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for Camera
    	 */
		class Camera final
		{
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
			friend std::ostream& operator<< (std::ostream&, const GFX::Camera&);
            
            // Data members
            ClearMode m_ClearMode;
            Color m_ClearColor;
            
            Math::IntVector2 m_ViewportPosition;
            Math::IntVector2 m_ViewportSize;
            
            ProjectionMode m_ProjectionMode;
            float m_FieldOfView;
            float m_NearClippingPlane;
            float m_FarClippingPlane;
            
            //RenderTexture m_RenderTexture;
            
		public:
            // Accessors
            void setViewportPosition(const Math::IntVector2&);
            void setViewportPosition(const int &x, const int &y);
            Math::IntVector2 getViewportPosition();
            
            void setViewportSize(const Math::IntVector2&);
            void setViewportSize(const int &x, const int &y);
            Math::IntVector2 getViewportSize();
            
            
            // Public methods
            void draw();
            
			// Mutating operators
			Camera& operator=(const Camera&) = delete;
			
			// Constructors, destructors
			Camera();
			Camera(const Camera&) = delete;
			~Camera() = default;
            
		};

		std::ostream& operator<< (std::ostream&, const GFX::Camera&);
        
	}

}

#endif /* GDK_GFX_CAMERA_H  */
