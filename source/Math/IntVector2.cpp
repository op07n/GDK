#include "IntVector2.h"
//math inc
#include "Vector2.h"
//std inc
#include <iostream>

using namespace GDK;
using namespace Math;

// Special values
const IntVector2 IntVector2::Up    = IntVector2( 0, 1);
const IntVector2 IntVector2::Down  = IntVector2( 0,-1);
const IntVector2 IntVector2::Left  = IntVector2(-1, 0);
const IntVector2 IntVector2::Right = IntVector2( 1, 0);
const IntVector2 IntVector2::Zero  = IntVector2( 0, 0);

//Contructors
IntVector2::IntVector2(const int &aX, const int &aY)
: x(aX)
, y(aY)
{}

Vector2 IntVector2::toVector2()
{
    return Vector2(x,y);
    
}

// Non mutating operators
IntVector2 IntVector2::operator+(const IntVector2 &aIntVector2)
{
    return IntVector2
    (
     x + aIntVector2.x,
     y + aIntVector2.y
     
    );
    
}

IntVector2 IntVector2::operator-(const IntVector2 &aIntVector2)
{
    return IntVector2
    (
     x - aIntVector2.x,
     y - aIntVector2.y
     
    );
    
}

IntVector2 IntVector2::operator*(const float &aScalar)
{
    return IntVector2
    (
     x * aScalar,
     y * aScalar
     
    );
    
}

IntVector2 IntVector2::operator*(const float &aScalar) const
{
    return IntVector2
    (
     x * aScalar,
     y * aScalar
     
    );
    
}

// Mutating operators
IntVector2& IntVector2::operator+=(const IntVector2 &aIntVector2)
{
    x += aIntVector2.x;
    y += aIntVector2.y;
    
    return *this;
    
}

IntVector2& IntVector2::operator-=(const IntVector2 &aIntVector2)
{
    x -= aIntVector2.x;
    y -= aIntVector2.y;
    
    return *this;
    
}

IntVector2& IntVector2::operator*=(const float &aScalar)
{
    x *= aScalar;
    y *= aScalar;
    
    return *this;
    
}

std::ostream& GDK::Math::operator<<(std::ostream& stream, const Math::IntVector2& aIntVector2)
{
    stream.clear();
    stream << "{" << aIntVector2.x << ", " << aIntVector2.y << ", " << "}";
    return stream;
    
}
