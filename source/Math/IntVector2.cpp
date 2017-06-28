#include "IntVector2.h"

using namespace GDK;
using namespace Math;

// Special values
const IntVector2 IntVector2::Zero;

//Contructors
IntVector2::IntVector2(const int &aX, const int &aY)
: x(aX)
, y(aY)
{}

Vector2 IntVector2::toVector2()
{
    return new Vector2(x,y);

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
