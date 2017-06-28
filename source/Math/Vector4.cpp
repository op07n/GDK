#include "Vector4.h"
//GDK inc
#include "Vector3.h"
//std inc
//#include <math.h>
#include <iostream>

using namespace GDK;
using namespace Math;

//Constructors
Vector4::Vector4()
: x(0.)
, y(0.)
, z(0.)
, w(1.)
{}

Vector4::Vector4(const float &aScalar)
: x(aScalar)
, y(aScalar)
, z(aScalar)
, w(aScalar)
{}

Vector4::Vector4(const Vector3 &aVector3, const float &aW)
: x(aVector3.x)
, y(aVector3.y)
, z(aVector3.z)
, w(aW)
{}

//Operators
Vector4& Vector4::operator+=(const Vector4 &aVector4)
{
    x += aVector4.x;
    y += aVector4.y;
    z += aVector4.z;
    w += aVector4.w;
    
    return *this;
    
}

Vector4& Vector4::operator*=(const float &aScalar)
{
    x *= aScalar;
    y *= aScalar;
    z *= aScalar;
    w *= aScalar;
    
    return *this;
    
}

std::ostream& GDK::Math::operator<<(std::ostream& stream, const Math::Vector4& aVector4)
{
    stream.clear();
    stream << "{" << aVector4.x << ", " << aVector4.y << ", " << aVector4.z << aVector4.z << "}";
    return stream;

}
