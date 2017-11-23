// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-27.
#include "Quaternion.h"
//math inc
#include "Vector3.h"
#include "Math/Trigonometry.h"
//implementation inc
#include <glm/gtc/quaternion.hpp>
//std inc
#include <iostream>

using namespace GDK;
using namespace Math;

//static const
const Quaternion Quaternion::Identity = Quaternion();

//stringify
std::ostream &GDK::Math::operator<< (std::ostream &s, const Math::Quaternion &a) noexcept
{
    s.clear(); s
    << "{"
    << "x: " << a.x << ", "
    << "y: " << a.y << ", "
    << "z: " << a.z << ", "
    << "w: " << a.w
    << "}";
    
    return s;
}

//ctors
Quaternion::Quaternion() noexcept : x(0.f), y(0.f), z(0.f), w(1.f)
{}

Quaternion::Quaternion(const Vector3 &aEulerAngles) noexcept
{
    setFromEuler(aEulerAngles);
}

//Euler convenience
void Quaternion::setFromEuler(const Vector3 &aEulerAngles) noexcept
{
    Vector3 eulerAngles = aEulerAngles;
    
    glm::quat quat;
    
    quat = glm::rotate(quat, eulerAngles.x, glm::vec3(1.f, 0.f, 0.f));
    quat = glm::rotate(quat, eulerAngles.y, glm::vec3(0.f, 1.f, 0.f));
    quat = glm::rotate(quat, eulerAngles.z, glm::vec3(0.f, 0.f, 1.f));
    
    x = quat.x;
    y = quat.y;
    z = quat.z;
    w = quat.w;
}

Vector3 Quaternion::toEuler() const noexcept
{
    glm::quat quaternion(w, x, y, z);
    
    glm::vec3 euler = glm::eulerAngles(quaternion);
    
    return {euler.x, euler.y, euler.z};
}
