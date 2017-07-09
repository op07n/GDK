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

using namespace GDK;
using namespace GFX;

std::ostream& GDK::GFX::operator<<(std::ostream& s, const GFX::Camera& a)
{
    s.clear();
    s << "{" 
    << "Camera's operator<< has not been implemented" 
    << "}";
    return s;

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
