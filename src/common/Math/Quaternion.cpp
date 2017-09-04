// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-27.
#include "Quaternion.h"
//math inc
#include "Vector3.h"
//implementation inc
#include <glm/gtc/quaternion.hpp>
//std inc
#include <iostream>

using namespace GDK;
using namespace Math;

//static const
const Quaternion Quaternion::Identity = Quaternion();

//stringify
std::ostream& GDK::Math::operator<< (std::ostream& s, const Math::Quaternion& a)
{
    s.clear(); s << "{"
    << "x: " << a.x << ", "
    << "y: " << a.y << ", "
    << "z: " << a.z << ", "
    << "w: " << a.w
    << "}"; return s;
    
}

//ctors
Quaternion::Quaternion() noexcept : x(0.), y(0.), z(0.), w(1.)
{}

Quaternion::Quaternion(const Vector3 &aEulerAngles) noexcept
{
    setFromEuler(aEulerAngles);
    
}
#include "Math/Trigonometry.h"
//Euler convenience
void Quaternion::setFromEuler(const Vector3 &aaEulerAngles)
{
    Vector3 aEulerAngles = aaEulerAngles;
    //aEulerAngles *= Math::Trig::PI/180.f;
    
    glm::quat quat;
    quat = glm::rotate(quat, aEulerAngles.x, glm::vec3(1.0f, 0.0f, 0.0f));
    quat = glm::rotate(quat, aEulerAngles.y, glm::vec3(0.0f, 1.0f, 0.0f));
    quat = glm::rotate(quat, aEulerAngles.z, glm::vec3(0.0f, 0.0f, 1.0f));
    
    x = quat.x;
    y = quat.y;
    z = quat.z;
    w = quat.w;
    
}

Vector3 Quaternion::toEuler(void) const
{
    glm::quat quaternion(w, x, y, z);
    glm::vec3 euler = glm::eulerAngles(quaternion);
    
    //euler *= 180.f/Math::Trig::PI;
    
    return Vector3
    (
     euler.x,
     euler.y,
     euler.z
     
     );
    
}
