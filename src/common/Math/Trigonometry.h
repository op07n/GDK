// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-22.
#ifndef GDK_MATH_TRIGONOMETRY_H
#define GDK_MATH_TRIGONOMETRY_H

namespace GDK
{
    namespace Math
    {
        /*!
         Trigonometry functions
         */
        namespace Trig
        {
            extern const float PI;
            
            float cos(const float&) noexcept;
            float sin(const float&) noexcept;
            float abs(const float&) noexcept;
            
            namespace Double
            {
                extern const double PI;
                
                double cos(const double&) noexcept;
                double sin(const double&) noexcept;
                double abs(const double&) noexcept;
            }
        }
    }
}

#endif /* GDK_MATH_TRIGONOMETRY_H  */
