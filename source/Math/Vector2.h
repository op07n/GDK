//
//  Vector2.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-26.
//
#ifndef GDK_MATH_VECTOR2_H
#define GDK_MATH_VECTOR2_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        struct Vector2
        {
            // Data members
            float x, y;
            
            // Non mutating operations
            float length(void) const;
            float getAspectRatio(void);
            
            // Mutating operations
            void normalize(void);
            /*void normalizeAndScale(const float &aScalar);*/
            
            // Non mutating operators
            Vector2 operator+(const Vector2 &aVector);
            Vector2 operator-(const Vector2 &aVector);
            Vector2 operator*(const float &aScalar);
            Vector2 operator*(const float &aScalar) const;
            
            // Mutating operators
            Vector2& operator+=(const Vector2 &aVector);
            Vector2& operator-=(const Vector2 &aVector);
            Vector2& operator*=(const float &aScalar);
            Vector2& operator=(const Vector2 &aVector) = default;
            
            // Constructors & Destructors
            Vector2();
            Vector2(const float &aScalar);
            Vector2(const float &aX, const float &aY);
            /*Vector2(const b2Vec2 &aBox2DVector);*/
            Vector2(const Vector2&) = default;
            ~Vector2() = default;
            
            // Special values
            static const Vector2 Up;
            static const Vector2 Down;
            static const Vector2 Left;
            static const Vector2 Right;
            static const Vector2 Zero;
            
        };
        
        std::ostream& operator<< (std::ostream& stream, const Math::Vector2& aVector2);
        
    }
    
}

#endif /* GDK_MATH_VECTOR2_H */
