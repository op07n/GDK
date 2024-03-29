// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-26.
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

//stringify
std::ostream &GDK::Math::operator<<(std::ostream &s, const Math::Vector2 &a)
{
    s.clear(); s
    << "{"
    << "x: " << a.x << ", "
    << "y: " << a.y
    << "}";
    
    return s;
}

//ctors
Vector2::Vector2(const float aX, const float aY)
: x(aX)
, y(aY)
{}

Vector2::Vector2(const float aScalar)
: x(aScalar)
, y(aScalar)
{}

//operators
bool Vector2::operator==(const Vector2 &a) const
{
    return x == a.x && y == a.y ? true : false;
}

bool Vector2::operator!=(const Vector2 &a) const
{
    return x != a.x || y != a.y ? true : false;
}

Vector2 Vector2::operator+(const Vector2 &aVector) const
{
    return {aVector.x + x, aVector.y + y};
}

Vector2 Vector2::operator-(const Vector2 &aVector) const
{
    return {aVector.x - x, aVector.y - y};
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

Vector2 Vector2::operator*(const float aScalar) const
{
    return {x * aScalar, y * aScalar};
}

Vector2& Vector2::operator*=(const float aScalar)
{
    x *= aScalar;
    y *= aScalar;
    
    return *this;
}

float Vector2::length() const
{
    return sqrtf( (x * x) + (y * y) );
}

void Vector2::normalize()
{
    float magnitude = Vector2::length();
    
    if (magnitude == 0.0f) // n/0 case
        return;
    
    x /= magnitude;
    y /= magnitude;
}

float Vector2::getAspectRatio() const
{
    return x / y;
}
