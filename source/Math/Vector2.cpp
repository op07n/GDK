#include "Vector2.h"
//std inc
#include <math.h>
#include <iostream>

using namespace GDK;
using namespace Math;

//static const
const Vector2 Vector2::Up    = Vector2( 0.f, 1.f);
const Vector2 Vector2::Down  = Vector2( 0.f,-1.f);
const Vector2 Vector2::Left  = Vector2(-1.f, 0.f);
const Vector2 Vector2::Right = Vector2( 1.f, 0.f);
const Vector2 Vector2::Zero  = Vector2( 0.f, 0.f);

//ctors
Vector2::Vector2(const float &aX, const float &aY)
: x(aX)
, y(aY)
{}

Vector2::Vector2(const float &aScalar)
: x(aScalar)
, y(aScalar)
{}

Vector2::Vector2()
: x(0)
, y(0)
{}

/*Vector2::Vector2(const b2Vec2 &aBox2DVector)
: x(aBox2DVector())
, y(aBox2DVector())
{}*/

//operators
Vector2 Vector2::operator+(const Vector2 &aVector)
{
    return Vector2(aVector.x + x, aVector.y + y);
    
}

Vector2 Vector2::operator-(const Vector2 &aVector)
{
    return Vector2(aVector.x - x, aVector.y - y);
    
}

Vector2& Vector2::operator+=(const Vector2 &aVector)
{
    x += aVector.x;
    y += aVector.y;
    
    return *this;
    
}

Vector2& Vector2::operator-=(const Vector2 &aVector)
{
    x -= aVector.x;
    y -= aVector.y;
    
    return *this;
    
}

Vector2 Vector2::operator*(const float &aScalar)
{
    return Vector2
    (
     x * aScalar,
     y * aScalar
     
     );
    
}

Vector2 Vector2::operator*(const float &aScalar) const
{
    return Vector2
    (
     x * aScalar,
     y * aScalar
     
     );
    
}

Vector2& Vector2::operator*=(const float &aScalar)
{
    x *= aScalar;
    y *= aScalar;
    
    return *this;
    
}

std::ostream& GDK::Math::operator<<(std::ostream& stream, const Math::Vector2& aVector2)
{
    stream.clear();
    stream << "{" << aVector2.x << ", " << aVector2.y << ", " << "}";
    return stream;
    
}

float Vector2::length(void) const
{
    return sqrt( (x*x) + (y*y) );
    
}

void Vector2::normalize(void)
{
    float magnitude = Vector2::length();
    
    if (magnitude == 0.0f) // n/0 case
        return;
    
    x /= magnitude;
    y /= magnitude;
    
}

float Vector2::getAspectRatio(void)
{
    return x / y;
    
}
