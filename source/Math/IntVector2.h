/**
 * @file   example_action.h
 * @Author Me (me@example.com)
 * @date   September, 2008
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 */

//!  A test class.
/*!
 \IntVector2.h
 \GDK
 \
 \Created by Joseph Cameron on 2017-06-27.
*/
/** Brief description which ends at this dot. Details follow
 *  here.
 */
#ifndef GDK_MATH_INTVECTOR2_H
#define GDK_MATH_INTVECTOR2_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Math
    {
        struct Vector2;
        
        struct IntVector2
        {
            // Data members
            //! An enum.
            /*! More detailed enum description. */
            int x,y;
            
            /*!
             \brief Converts IntVector2 to a (float) Vector2
             */
            Vector2 toVector2();
            
            // Non mutating operators
            IntVector2 operator+(const IntVector2&);
            IntVector2 operator-(const IntVector2&);
            IntVector2 operator*(const float &aScalar);
            IntVector2 operator*(const float &aScalar) const;
            
            // Mutating operators
            IntVector2& operator+=(const IntVector2&);
            IntVector2& operator-=(const IntVector2&);
            IntVector2& operator*=(const float&);
            IntVector2& operator=(const IntVector2&) = default;
            
            // Constructors & Destructors
            IntVector2() = default;
            IntVector2(const int &aX, const int &aY);
            IntVector2(const IntVector2&) = default;
            ~IntVector2() = default;
            
            // Special values
            static const IntVector2 Up;
            static const IntVector2 Down;
            static const IntVector2 Left;
            static const IntVector2 Right;
            static const IntVector2 Zero;
            
        };
        
        std::ostream& operator<< (std::ostream&, const Math::IntVector2&);
        
    }
    
}

#endif /* GDK_MATH_INTVECTOR2_H */
