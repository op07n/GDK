// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-27.
#ifndef GDK_MATH_QUATERNION_H
#define GDK_MATH_QUATERNION_H

//std inc
#include <iosfwd>

class btQuaternion;

namespace GDK
{
    namespace Math
    {
        struct Vector3;
        
        /*!
         Used to represent 3d rotations in a way insusceptible to gimblal lock (unlike Vector3)
         */
        struct Quaternion final
        {
            //Data members
            float x = 0.0f, y = 0.0f, z = 0.0f, w = 1.0f;
            
            // Euler convenience
            void setFromEuler(const Vector3& aEulers) noexcept;
            Math::Vector3 toEuler(void) const noexcept;
            
            // Mutating operators
            Quaternion& operator=(const Quaternion&) noexcept = default;
            
            // Constructors & Destructors
            Quaternion(const Vector3&) noexcept;
            Quaternion(const float& aX, const float& aY, const float& aZ, const float& aW) noexcept;
            Quaternion() noexcept;
            Quaternion(const Quaternion&) noexcept = default;
            Quaternion(Quaternion&&) noexcept = default;
            ~Quaternion() noexcept = default;
            
            // Special values
            static const Quaternion Identity;
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Quaternion&) noexcept;
    }
}

#endif /* GDK_MATH_QUATERNION_H */
