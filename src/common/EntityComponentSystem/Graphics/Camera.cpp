// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#include "Camera.h"
#include "Debug/Logger.h"
#include "EntityComponentSystem/GameObject.h"
#include "Graphics/Model.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace GDK::ECS::GFX;

static constexpr char TAG[] = "Camera";

std::ostream& GDK::ECS::GFX::operator<<(std::ostream& s, const ECS::GFX::Camera& a)
{
    (void)a;
    
    s.clear(); s
    << "{"
    << TAG << "'s: " << "operator<< has not been implemented"
    // << "m_Member: " << a.m_Member << ", "
    << "}";
    
    return s;
}

void Camera::draw(const Math::IntVector2& aFrameBufferSize) noexcept
{
    if (auto gameObject = getGameObject().lock())
        m_Camera.setViewMatrix(gameObject->getPosition(), gameObject->getRotation());
    
    m_Camera.draw(aFrameBufferSize);
    
}

void Camera::initialize()  {}
void Camera::update()      {}
void Camera::fixedUpdate() {}

// accessors
//viewportpos
void Camera::setViewportPosition(const Math::Vector2 &a)
{
    m_Camera.setViewportPosition(a);
}

void Camera::setViewportPosition(const float x, const float y)
{
    m_Camera.setViewportPosition(x,y);
}

Math::Vector2 Camera::getViewportPosition() const
{
    return m_Camera.getViewportPosition();
}

void Camera::setViewportSize(const Math::Vector2 &a)
{
    m_Camera.setViewportSize(a);
}

void Camera::setViewportSize(const float x, const float y)
{
    m_Camera.setViewportSize(x,y);
}

Math::Vector2 Camera::getViewportSize() const
{
    return m_Camera.getViewportSize();
}

const Math::Mat4x4 &Camera::getProjectionMatrix() const
{
    return m_Camera.getProjectionMatrix();
}

const Math::Mat4x4 &Camera::getViewMatrix() const
{
    return m_Camera.getViewMatrix();
}
