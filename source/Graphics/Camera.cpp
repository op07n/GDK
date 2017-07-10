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
#include "../Math/Mat4x4.h"

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Camera& a)
{
    s.clear(); s << "{"
    << "m_ViewportPosition: "  << a.m_ViewportPosition  << ", "
    << "m_ViewportSize: "      << a.m_ViewportSize      << ", "
    << "m_FieldOfView: "       << a.m_FieldOfView       << ", "
    << "m_NearClippingPlane: " << a.m_NearClippingPlane << ", "
    << "m_FarClippingPlane: "  << a.m_FarClippingPlane
    << "}"; return s;

}

Camera::Camera()
: m_ClearMode(ClearMode::Color)
, m_ClearColor(Color::CornflowerBlue)
, m_ViewportPosition(Math::IntVector2::Zero)
, m_ViewportSize(Math::IntVector2(300,300))
, m_ProjectionMode(ProjectionMode::Perspective)
, m_FieldOfView(90.)
, m_NearClippingPlane(0.001f)
, m_FarClippingPlane(20.)
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SCISSOR_TEST);
    
}

void Camera::draw()
{
    GLH::Viewport(m_ViewportPosition, m_ViewportSize);
    GLH::Scissor(m_ViewportPosition, m_ViewportSize);
    
    switch(m_ClearMode)
    {
        case ClearMode::Color:
        {
            GLH::ClearColor(m_ClearColor);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
        } break;
            
        case ClearMode::DepthOnly:
        {
            glClear(GL_DEPTH_BUFFER_BIT);
            
        } break;
            
        default:
        case ClearMode::Nothing:
        break;
            
    }
    
}


Math::Mat4x4 Camera::getProjectionMatrix() const
{
    switch(m_ProjectionMode)
    {
        default:
        case ProjectionMode::Perspective:
            return Math::Mat4x4();//b_ProjectionMatrixBuffer.perspectiveInPlace(m_FieldOfView, getViewportAspectRatio(), m_NearClippingPlane, m_FarClippingPlane);
        break;
            
        case ProjectionMode::Orthographic:
            return Math::Mat4x4();//b_ProjectionMatrixBuffer.orthographicInPlace(m_OrthoSize,m_NearClippingPlane,m_FarClippingPlane,getViewportAspectRatio());
        break;
            
    }
    
}

Math::Mat4x4 Camera::getViewMatrix() const
{
    return Math::Mat4x4();
    
}

//Trivial accessors
void Camera::setViewportPosition(const Math::IntVector2 &a){m_ViewportPosition=a;}
void Camera::setViewportPosition(const int &x, const int &y){m_ViewportPosition.x=x;m_ViewportPosition.y=y;}
void Camera::setViewportSize(const Math::IntVector2 &a){m_ViewportSize=a;}
void Camera::setViewportSize(const int &x, const int &y){m_ViewportSize.x=x;m_ViewportSize.y=y;}

Math::IntVector2 Camera::getViewportSize(){return m_ViewportSize;}
Math::IntVector2 Camera::getViewportPosition(){return m_ViewportPosition;}
