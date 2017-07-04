// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-27.
#include "Quaternion.h"
//math inc
#include "Vector3.h"
//implementation inc
#include <glm/gtc/quaternion.hpp>
//#include <Bullet\btBulletDynamicsCommon.h>
//std inc
#include <iostream>

using namespace GDK;
using namespace Math;

//static const
const Quaternion Quaternion::Identity = Quaternion();

//ctors
Quaternion::Quaternion() : x(0.), y(0.), z(0.), w(1.)
{}

Quaternion::Quaternion(const Vector3 &aEulerAngles)
{
    setFromEuler(aEulerAngles);
    
}

/*Quaternion(const btQuaternion &aBulletQuaternion)
: x(aBulletQuaternion.x)
, y(aBulletQuaternion.y)
, z(aBulletQuaternion.z)
, w(aBulletQuaternion.w)
{}*/

//Euler convenience
void Quaternion::setFromEuler(const Vector3 &aEulerAngles)
{
    glm::quat quat;
    quat = glm::rotate(quat, aEulerAngles.x, glm::vec3(1.0f, 0.0f, 0.0f));
    quat = glm::rotate(quat, aEulerAngles.y, glm::vec3(0.0f, 1.0f, 0.0f));
    quat = glm::rotate(quat, aEulerAngles.z, glm::vec3(0.0f, 0.0f, 1.0f));
    
    x = quat.x;
    y = quat.y;
    z = quat.z;
    w = quat.w;
    
}

Vector3 Quaternion::toEuler(void)
{
    glm::quat quaternion(w, x, y, z);
    glm::vec3 euler = glm::eulerAngles(quaternion);
    
    return Vector3
    (
     euler.x,
     euler.y,
     euler.z
     
     );
    
}

std::ostream& GDK::Math::operator<< (std::ostream& stream, const Math::Quaternion& aQuaternion)
{
    stream << "{" << aQuaternion.x << ", " << aQuaternion.y << ", " << aQuaternion.z << ", " << aQuaternion.w << "}";
    return stream;
    
}

