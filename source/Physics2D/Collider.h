// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_PHYSICS2D_COLLIDER_H
#define GDK_PHYSICS2D_COLLIDER_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Physics2D
    {
        /*!
         No description provided for Collider
         */
        class Collider final
        {
            friend std::ostream& operator<< (std::ostream&, const Physics2D::Collider&);
      
            // Data members

        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            Collider& operator=(const Collider&) = delete;
      
            // Constructors, destructors
            Collider() = delete;
            Collider(const Collider&) = delete;
            Collider(Collider&&) = delete;
            ~Collider() = delete;
      
        };

        std::ostream& operator<< (std::ostream&, const Physics2D::Collider&);
        
    }

}

#endif /* GDK_PHYSICS2D_COLLIDER_H  */
