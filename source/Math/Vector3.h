#ifndef GDK_MATH_VECTOR3_H
#define GDK_MATH_VECTOR3_H
/*
 * Vector3
 *
 */
//std inc
#include <iosfwd>

class btVector3;

namespace GDK
{
    namespace Math
    {
        struct Vector3
        {
            float x, y, z;
            
            float length(void);
            void normalize(void);
            void normalizeAndScale(const float &aScalar);
            
            //Non mutating operators
            Vector3 operator+(const Vector3 &aVector);
            Vector3 operator-(const Vector3 &aVector);
            Vector3 operator*(const float &aScalar);
            Vector3 operator*(const float &aScalar) const;
            
            //Mutating operators
            void operator+=(const Vector3 &aVector);
            void operator-=(const Vector3 &aVector);
            void operator*=(const float &aScalar);
            Vector3& operator=(const Vector3 &aVector) = default;
            
            static const Vector3 Up;
            static const Vector3 Down;
            static const Vector3 Left;
            static const Vector3 Right;
            static const Vector3 Forward;
            static const Vector3 Backward;
            static const Vector3 Zero;
            
            Vector3();
            Vector3(const float &aScalar);
            Vector3(const float &aX, const float &aY, const float &aZ);
            /*Vector3(const btVector3 &aBulletVector);*/
            Vector3(const Vector3&) = default;
            ~Vector3() = default;
            
        };
        
        std::ostream& operator<< (std::ostream& stream, const Math::Vector3& aVector3);
        
    }
    
}

#endif /* GDK_MATH_VECTOR3_H */
