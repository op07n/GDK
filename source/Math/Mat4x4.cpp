// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#include "Mat4x4.h"
//gdk inc
#include "../Math/Vector2.h"
#include "../Utilities/Exception.h"
//thirdparty inc
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
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

Mat4x4& Mat4x4::operator*(const Mat4x4&)
{
    return *this;
    
}
