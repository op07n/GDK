//
//  Quaternion.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-27.
//
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
        
        struct Quaternion
        {
            //Data members
            float x, y, z, w;
            
            // Euler convenience
            void setFromEuler(const Vector3& aEulers);
            Math::Vector3 getEuler(void);
            
            // Constructors & Destructors
            Quaternion();
            Quaternion(const Vector3&);
            /*Quaternion(const btQuaternion &aBulletQuaternion);*/
            Quaternion(const float& aX, const float& aY, const float& aZ, const float& aW);
            Quaternion(const Quaternion&) = default;
            ~Quaternion() = default;
            
            // Special values
            static const Quaternion Identity;
            
        };
        
        std::ostream& operator<< (std::ostream&, const Math::Quaternion&);
        
    }
    
}

#endif /* GDK_MATH_QUATERNION_H */
