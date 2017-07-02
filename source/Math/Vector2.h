// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-26.
#ifndef GDK_MATH_VECTOR2_H
#define GDK_MATH_VECTOR2_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        /*!
         Useful for storing 2D position, speed, direction, normalized coordinates.
         */
        struct Vector2 final
        {
            // Data members
            float x, y;
            
            // Non mutating operations
            float length() const;
            float getAspectRatio() const;
            
            // Mutating operations
            void normalize();
            /*void normalizeAndScale(const float &aScalar);*/
            
            // Non mutating operators
            Vector2 operator+(const Vector2&);
            Vector2 operator-(const Vector2&);
            Vector2 operator*(const float&);
            Vector2 operator*(const float&) const;
            
            // Mutating operators
            Vector2& operator+=(const Vector2&);
            Vector2& operator-=(const Vector2&);
            Vector2& operator*=(const float&);
            Vector2& operator=(const Vector2&) = default;
            
            // Constructors & Destructors
            Vector2();
            Vector2(const float&);
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
        
        std::ostream& operator<< (std::ostream&, const Math::Vector2&);
        
    }
    
}

#endif /* GDK_MATH_VECTOR2_H */
