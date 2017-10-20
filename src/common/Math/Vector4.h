// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created 2017-06-27.
#ifndef GDK_MATH_VECTOR4_H
#define GDK_MATH_VECTOR4_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        struct Vector3;
        
        /*!
         Like Vector3 but allows w to != 1. Used in Vector vs Mat4x4 operations
         */
        struct Vector4 final
        {
            // Data members
            float x = 0.0f, y = 0.0f, z = 0.0f, w = 1.0f;
            
            //Mutating operators
            bool operator==(const Vector4&) const noexcept;
            bool operator!=(const Vector4&) const noexcept;
            Vector4& operator+=(const Vector4&) noexcept;
            Vector4& operator*=(const float&) noexcept;
            Vector4& operator=(const Vector4&) noexcept = default;
            
            // Constructors & Destructors
            Vector4(const Vector3& aVector3, const float &aW = 1.) noexcept;
            Vector4(const float &aX, const float &aY, const float &aZ, const float &aW) noexcept;
            Vector4() noexcept;
            Vector4(const Vector4&) noexcept = default;
            Vector4(Vector4&&) noexcept = default;
            ~Vector4() noexcept = default;
            
            // Special values
            static const Vector4 Zero;
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Vector4&) noexcept;
    }
}

#endif /* GDK_MATH_VECTOR4_H */
