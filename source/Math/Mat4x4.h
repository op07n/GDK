// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#ifndef GDK_MATH_MAT4x4_H
#define GDK_MATH_MAT4x4_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        /*!
         used to store 3D transformations.
         */
        struct Mat4x4 final
        {
            // Data members
            float
            m00, m01, m02, m03,
            m10, m11, m12, m13,
            m20, m21, m22, m23,
            m30, m31, m32, m33;
            
            // Mutating operators
            Mat4x4& operator=(const Mat4x4&) = default;
            
            // Constructors & Destructors
            Mat4x4();
            Mat4x4
            (
                const float& a00, const float& a01, const float& a02, const float& a03,
                const float& a10, const float& a11, const float& a12, const float& a13,
                const float& a20, const float& a21, const float& a22, const float& a23,
                const float& a30, const float& a31, const float& a32, const float& a33
            );
            Mat4x4(const Mat4x4&) = default;
            ~Mat4x4() = default;
            
            // Special values
            static const Mat4x4 Identity;
            
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Mat4x4&);
        
    }
    
}

#endif /* GDK_MATH_MAT4x4_H */
