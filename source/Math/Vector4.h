//
//  Vector3.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-27.
//
#ifndef GDK_MATH_VECTOR4_H
#define GDK_MATH_VECTOR4_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        struct Vector3;
        
        struct Vector4
        {
            // Data members
            float x, y, z, w;
            
            //Mutating operators
            Vector4& operator+=(const Vector4 &aVector);
            Vector4& operator*=(const float &aScalar);
            Vector4& operator=(const Vector4 &) = default;
            
            // Constructors & Destructors
            Vector4();
            Vector4(const Vector3 &, const float &aW = 1.);
            Vector4(const float&);
            Vector4(const Vector4&) = default;
            ~Vector4() = default;
            
        };
        
        std::ostream& operator<< (std::ostream& stream, const Math::Vector4& aVector4);
        
    }
    
}

#endif /* GDK_MATH_VECTOR4_H */
