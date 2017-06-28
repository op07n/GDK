//
//  Mat4x4.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-28.
//
#ifndef GDK_MATH_MAT4x4_H
#define GDK_MATH_MAT4x4_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        struct Mat4x4
        {
            // Data members
            float
            m00, m01, m02, m03,
            m10, m11, m12, m13,
            m20, m21, m22, m23,
            m30, m31, m32, m33;
            
            // Non mutating operators
            
            // Mutating operators
            Mat4x4& operator=(const Mat4x4&) = default;
            
            // Constructors & Destructors
            Mat4x4();
            Mat4x4
            (
                const float&, const float&, const float&, const float&,
                const float&, const float&, const float&, const float&,
                const float&, const float&, const float&, const float&,
                const float&, const float&, const float&, const float&
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
