// © ${YEAR} Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on ${DATE}.
#include "Camera.h"
//std inc
#include <iostream>
//gdk inc
#include "GL.h"
#include "Color.h"
#include "../Math/IntVector2.h"
#include "../Math/Vector2.h"
#include "../Math/Mat4x4.h"
#include "../Debug/Logger.h"
#include "../Debug/Exception.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Camera& a)
{
    s.clear(); s << "{"
    << "m_ViewMatrix:\n"       << a.m_ViewMatrix        // << ", "
    << "m_ProjectionMatrix:\n" << a.m_ProjectionMatrix  // << ", "
    << "m_ViewportPosition: "  << a.m_ViewportPosition  << ", "
    << "m_ViewportSize: "      << a.m_ViewportSize      << ", "
    << "m_FieldOfView: "       << a.m_FieldOfView       << ", "
    << "m_NearClippingPlane: " << a.m_NearClippingPlane << ", "
    << "m_FarClippingPlane: "  << a.m_FarClippingPlane
    << "}"; return s;

}

Camera::Camera()
: m_ViewMatrix()
, m_ProjectionMatrix()
, m_ClearMode(ClearMode::Color)
, m_ClearColor(Color::CornflowerBlue)
, m_ViewportPosition(Math::Vector2::Zero)
, m_ViewportSize(Math::Vector2(1.,1.))
, m_ProjectionMode(ProjectionMode::Perspective)
, m_FieldOfView(90.)
, m_NearClippingPlane(0.001f)
, m_FarClippingPlane(20.)
, m_OrthoSize(10,10)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    
}

static inline void calculateOrthographicProjection(Math::Mat4x4& aProjectionMatrix, const Math::Vector2 &aOrthoSize, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio)
{
    throw GDK::Exception("Camera::setOrthographicProjection not implemented!");
    
}

static inline void calculatePerspectiveProjection(Math::Mat4x4& aProjectionMatrix, const float &aFieldOfView, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio)
{
    aProjectionMatrix.setPerspective(aFieldOfView, aNearClippingPlane, aFarClippingPlane, aViewportAspectRatio);
    
}

void Camera::draw(const Math::IntVector2& aFrameBufferSize)
{
    Math::IntVector2 viewportPixelPosition(aFrameBufferSize*m_ViewportPosition);
    Math::IntVector2 viewportPixelSize(aFrameBufferSize*m_ViewportSize);
    
    GLH::Viewport(viewportPixelPosition, viewportPixelSize);
    GLH::Scissor (viewportPixelPosition, viewportPixelSize);
    
    switch(m_ProjectionMode)
    {
        case ProjectionMode::Perspective:
        calculatePerspectiveProjection(m_ProjectionMatrix,m_FieldOfView,m_NearClippingPlane,m_FarClippingPlane,m_ViewportSize.getAspectRatio());
        break;
            
        case ProjectionMode::Orthographic:
        calculateOrthographicProjection(m_ProjectionMatrix,m_OrthoSize,m_NearClippingPlane,m_FarClippingPlane,m_ViewportSize.getAspectRatio());
        break;
            
    }
    
    switch(m_ClearMode)
    {
        case ClearMode::Color:
        GLH::ClearColor(m_ClearColor);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;
            
        case ClearMode::DepthOnly:
        glClear(GL_DEPTH_BUFFER_BIT);
        break;
            
        default:
        case ClearMode::Nothing:
        break;
            
    }
    
}

void Camera::setViewMatrix(const Math::Vector3 &aWorldPos, const Math::Quaternion &aRotation)
{
    m_ViewMatrix.setIdentity();
    m_ViewMatrix.rotate(aRotation);
    m_ViewMatrix.translate(aWorldPos);
    
}

// accessors
//viewportpos
void Camera::setViewportPosition(const Math::Vector2 &a){m_ViewportPosition=a;}
void Camera::setViewportPosition(const float &x, const float &y){m_ViewportPosition.x=x;m_ViewportPosition.y=y;}
Math::Vector2 Camera::getViewportPosition(){return m_ViewportPosition;}
//viewportsize
void Camera::setViewportSize(const Math::Vector2 &a){m_ViewportSize=a;}
void Camera::setViewportSize(const float &x, const float &y){m_ViewportSize.x=x;m_ViewportSize.y=y;}
Math::Vector2 Camera::getViewportSize(){return m_ViewportSize;}
//projmat
const Math::Mat4x4& Camera::getProjectionMatrix()const{return m_ProjectionMatrix;}
//viewmat
const Math::Mat4x4& Camera::getViewMatrix()const{return m_ViewMatrix;}
