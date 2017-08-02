// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#ifndef GDK_MATH_PLANE_H
#define GDK_MATH_PLANE_H

//std inc
#include <iosfwd>
//math inc
#include "Vector3.h"

namespace GDK
{
    namespace Math
    {
        /*!
         Describes an infinite plane in 3space.
         */
        struct Plane final
        {
            // Data members
            Vector3 position, normal;
            
            // Mutating operators
            Plane& operator=(const Plane&) = default;
            
            // Constructors & Destructors
            Plane(const Vector3& aPosition, const Vector3& aNormal) noexcept;
            Plane() noexcept = delete;
            Plane(const Plane&) noexcept = default;
            Plane(Plane&&) noexcept = default;
            ~Plane() noexcept = default;
            
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Plane&);
        
    }
    
}

#endif /* GDK_MATH_PLANE_H */
