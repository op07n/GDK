// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-28.
#ifndef GDK_MATH_MAT4x4_H
#define GDK_MATH_MAT4x4_H

//std inc
#include <iosfwd>

namespace GDK{namespace Math{struct Vector2;}}
namespace GDK{namespace Math{struct Vector3;}}
namespace GDK{namespace Math{struct Quaternion;}}

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
            float m[4][4] = {};
            
            // Mutating operations
            void setIdentity();
            
            void setOrthographic(const Math::Vector2 &aOrthoSize, const float aNearClippingPlane, const float aFarClippingPlane, const float aViewportAspectRatio);
            void setPerspective(const float aFieldOfView, const float aNearClippingPlane, const float aFarClippingPlane, const float aViewportAspectRatio);
            
            void translate(const Vector3 &aTranslation);
            void rotate(const Quaternion &aRotation);
            void scale(const Vector3 &aScale);
            void transpose();
            void set
            (
                const float& a00, const float& a01, const float& a02, const float& a03,
                const float& a10, const float& a11, const float& a12, const float& a13,
                const float& a20, const float& a21, const float& a22, const float& a23,
                const float& a30, const float& a31, const float& a32, const float& a33
            );
            
            // Non-mutating operators
            Mat4x4 operator*(const Mat4x4&);
            
            // Mutating operators
            Mat4x4& operator=(const Mat4x4&) = default;
            Mat4x4& operator*=(const Mat4x4&);
            
            // Constructors & Destructors
            Mat4x4
            (
                const float& a00, const float& a01, const float& a02, const float& a03,
                const float& a10, const float& a11, const float& a12, const float& a13,
                const float& a20, const float& a21, const float& a22, const float& a23,
                const float& a30, const float& a31, const float& a32, const float& a33
            );
            Mat4x4();
            Mat4x4(const Mat4x4&) = default;
            Mat4x4(Mat4x4&&) = default;
            ~Mat4x4() = default;
            
            // Special values
            static const Mat4x4 Identity;
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Mat4x4&);
    }
}

#endif /* GDK_MATH_MAT4x4_H */
