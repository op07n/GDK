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
            float x = 0.f, y = 0.f;
            
            // Non mutating operations
            /// squareroot of the sum of the 2nd power of the components
            float length() const noexcept;
            
            /// X/Y
            float getAspectRatio() const noexcept;
            
            // Mutating operations
            /// Set length to 1
            void normalize() noexcept;
            
            // Non mutating operators
            bool operator==(const Vector2&) const noexcept;
            bool operator!=(const Vector2&) const noexcept;
            Vector2 operator+(const Vector2&) const noexcept;
            Vector2 operator-(const Vector2&) const noexcept;
            Vector2 operator*(const float) const noexcept;
            
            // Mutating operators
            Vector2& operator+=(const Vector2&) noexcept;
            Vector2& operator-=(const Vector2&) noexcept;
            Vector2& operator*=(const float) noexcept;
            Vector2& operator=(const Vector2&) noexcept = default;
            
            // Constructors & Destructors
            Vector2(const float) noexcept;
            Vector2(const float aX, const float aY) noexcept;
            Vector2() noexcept = default;
            Vector2(const Vector2 &) noexcept = default;
            Vector2(Vector2 &&) noexcept = default;
            ~Vector2() noexcept = default;
            
            // Special values
            static const Vector2 Up;
            static const Vector2 Down;
            static const Vector2 Left;
            static const Vector2 Right;
            static const Vector2 Zero;
        };
        
        std::ostream &operator<< (std::ostream &, const Math::Vector2 &) noexcept;
    }
}

#endif /* GDK_MATH_VECTOR2_H */
