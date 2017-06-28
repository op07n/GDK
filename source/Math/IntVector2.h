//
//  IntVector2.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-27.
//
#ifndef GDK_MATH_INTVECTOR2_H
#define GDK_MATH_INTVECTOR2_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        public class IntVector2
        {
            // Data members
            int x,y;
            
            Vector2 toVector2();
            
            // Mutating operators
            IntVector2& operator+=(const IntVector2 &);
            IntVector2& operator-=(const IntVector2 &);
            IntVector2& operator*=(const float &);
            IntVector2& operator=(const IntVector2 &) = default;
            
            // Constructors & Destructors
            IntVector2() = default;
            IntVector2(const int &aX, const int &aY);
            
            // Special values
            static const IntVector2 Zero;
            
        }
        
        std::ostream& operator<< (std::ostream& stream, const Math::IntVector2& aIntVector2);
        
    }
    
}

#endif /* GDK_MATH_INTVECTOR2_H */
