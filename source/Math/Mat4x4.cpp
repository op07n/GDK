// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#include "Mat4x4.h"
//gdk inc
#include "../Math/Vector2.h"
#include "../Math/Vector3.h"
#include "../Math/Quaternion.h"
#include "../Debug/Exception.h"
//#include "../Debug/Logger.h"
//thirdparty inc
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <glm/gtc/quaternion.hpp>
//std inc
#include <iostream>
#include <math.h>

using namespace GDK;
using namespace Math;

//static const
const Mat4x4 Mat4x4::Identity = Mat4x4();

//Stringify
std::ostream& GDK::Math::operator<< (std::ostream &s, const Math::Mat4x4& aMat)
{
    s.clear();
    s
    << "{" << aMat.m00 << ", " << aMat.m01 << ", " << aMat.m02 << ", " << aMat.m03 << "}\n"
    << "{" << aMat.m10 << ", " << aMat.m11 << ", " << aMat.m12 << ", " << aMat.m13 << "}\n"
    << "{" << aMat.m20 << ", " << aMat.m21 << ", " << aMat.m22 << ", " << aMat.m23 << "}\n"
    << "{" << aMat.m30 << ", " << aMat.m31 << ", " << aMat.m32 << ", " << aMat.m33 << "}\n";
    
    return s;
    
}

void Mat4x4::setIdentity()
{
    m00 = 1.; m01 = 0.; m02 = 0.; m03 = 0.;
    m10 = 0.; m11 = 1.; m12 = 0.; m13 = 0.;
    m20 = 0.; m21 = 0.; m22 = 1.; m23 = 0.;
    m30 = 0.; m31 = 0.; m32 = 0.; m33 = 1.;

}

void Mat4x4::setOrthographic(const Math::Vector2 &aOrthoSize, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio)
{
    throw GDK::Exception("Mat4x4::setOrthographic not implemented!");
    
}

void Mat4x4::translate(const Vector3 &a)
{
    m30 = m00 * a.x + m10 * a.y + m20 * a.z + m30;
    m31 = m01 * a.x + m11 * a.y + m21 * a.z + m31;
    m32 = m02 * a.x + m12 * a.y + m22 * a.z + m32;
    m33 = m03 * a.x + m13 * a.y + m23 * a.z + m33;
    
}

void Mat4x4::rotate(const Quaternion &aRotation)
{
    glm::quat quat;
    quat.x = aRotation.x;
    quat.y = aRotation.y;
    quat.z = aRotation.z;
    quat.w = aRotation.w;
    
    glm::mat4 mat4 = glm::mat4_cast(quat);
    
    Mat4x4 rotationMatrix
    (
     /*mat4[0][0],
     mat4[0][1],
     mat4[0][2],
     mat4[0][3],
    
     mat4[1][0],
     mat4[1][1],
     mat4[1][2],
     mat4[1][3],
    
     mat4[2][0],
     mat4[2][1],
     mat4[2][2],
     mat4[2][3],
    
     mat4[3][0],
     mat4[3][1],
     mat4[3][2],
     mat4[3][3]*/
     
     mat4[0][0],
     mat4[1][0],
     mat4[2][0],
     mat4[3][0],
     
     mat4[0][1],
     mat4[1][1],
     mat4[2][1],
     mat4[3][1],
     
     mat4[0][2],
     mat4[1][2],
     mat4[2][2],
     mat4[3][2],
     
     mat4[0][3],
     mat4[1][3],
     mat4[2][3],
     mat4[3][3]
     
    
    );
    
    *this = rotationMatrix * *this;
    
}

void Mat4x4::scale(const Vector3 &aPosition)
{
    throw GDK::Exception("Mat4x4::scale not implemented!");
    
}

void Mat4x4::setPerspective(const float &aFieldOfView, const float &aNearClippingPlane, const float &aFarClippingPlane, const float &aViewportAspectRatio)
{
    float tanHalfFovy = (float)tan(aFieldOfView * 0.5f);
    m00 = 1.0f / (aViewportAspectRatio * tanHalfFovy);
    m01 = 0.0f;
    m02 = 0.0f;
    m03 = 0.0f;
    m10 = 0.0f;
    m11 = 1.0f / tanHalfFovy;
    m12 = 0.0f;
    m13 = 0.0f;
    m20 = 0.0f;
    m21 = 0.0f;
    m22 =-(aFarClippingPlane + aNearClippingPlane) / (aFarClippingPlane - aNearClippingPlane);
    m23 =-1.0f;
    m30 = 0.0f;
    m31 = 0.0f;
    m32 =-2.0f * aFarClippingPlane * aNearClippingPlane / (aFarClippingPlane - aNearClippingPlane);
    m33 = 0.0f;
    
}

// Constructors
Mat4x4::Mat4x4()
: m00(1.), m01(0.), m02(0.), m03(0.)
, m10(0.), m11(1.), m12(0.), m13(0.)
, m20(0.), m21(0.), m22(1.), m23(0.)
, m30(0.), m31(0.), m32(0.), m33(1.)
{}

Mat4x4::Mat4x4
(
 const float& a00, const float& a01, const float& a02, const float& a03,
 const float& a10, const float& a11, const float& a12, const float& a13,
 const float& a20, const float& a21, const float& a22, const float& a23,
 const float& a30, const float& a31, const float& a32, const float& a33
)
: m00(a00), m01(a01), m02(a02), m03(a03)
, m10(a10), m11(a11), m12(a12), m13(a13)
, m20(a20), m21(a21), m22(a22), m23(a23)
, m30(a30), m31(a31), m32(a32), m33(a33)
{}

Mat4x4& Mat4x4::operator*=(const Mat4x4& a)
{
    m00 = m00 * a.m00 + m10 * a.m01 + m20 * a.m02 + m30 * a.m03;
    m01 = m01 * a.m00 + m11 * a.m01 + m21 * a.m02 + m31 * a.m03;
    m02 = m02 * a.m00 + m12 * a.m01 + m22 * a.m02 + m32 * a.m03;
    m03 = m03 * a.m00 + m13 * a.m01 + m23 * a.m02 + m33 * a.m03;
    m10 = m00 * a.m10 + m10 * a.m11 + m20 * a.m12 + m30 * a.m13;
    m11 = m01 * a.m10 + m11 * a.m11 + m21 * a.m12 + m31 * a.m13;
    m12 = m02 * a.m10 + m12 * a.m11 + m22 * a.m12 + m32 * a.m13;
    m13 = m03 * a.m10 + m13 * a.m11 + m23 * a.m12 + m33 * a.m13;
    m20 = m00 * a.m20 + m10 * a.m21 + m20 * a.m22 + m30 * a.m23;
    m21 = m01 * a.m20 + m11 * a.m21 + m21 * a.m22 + m31 * a.m23;
    m22 = m02 * a.m20 + m12 * a.m21 + m22 * a.m22 + m32 * a.m23;
    m23 = m03 * a.m20 + m13 * a.m21 + m23 * a.m22 + m33 * a.m23;
    m30 = m00 * a.m30 + m10 * a.m31 + m20 * a.m32 + m30 * a.m33;
    m31 = m01 * a.m30 + m11 * a.m31 + m21 * a.m32 + m31 * a.m33;
    m32 = m02 * a.m30 + m12 * a.m31 + m22 * a.m32 + m32 * a.m33;
    m33 = m03 * a.m30 + m13 * a.m31 + m23 * a.m32 + m33 * a.m33;
    
    return *this;
    
}

Mat4x4 Mat4x4::operator*(const Mat4x4 &a)
{
    Mat4x4 r(*this);
    r *= a;
    return r;
    
}
