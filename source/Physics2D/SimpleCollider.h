// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-30.
#ifndef GDK_PHYSICS2D_SIMPLECOLLIDER_H
#define GDK_PHYSICS2D_SIMPLECOLLIDER_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Physics2D
    {
        /*!
         No description provided for SimpleCollider
         */
        class SimpleCollider final
        {
            friend std::ostream& operator<< (std::ostream&, const Physics2D::SimpleCollider&);
      
            // Data members

        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            SimpleCollider& operator=(const SimpleCollider&) = delete;
      
            // Constructors, destructors
            SimpleCollider() = delete;
            SimpleCollider(const SimpleCollider&) = delete;
            SimpleCollider(SimpleCollider&&) = delete;
            ~SimpleCollider() = delete;
      
        };

        std::ostream& operator<< (std::ostream&, const Physics2D::SimpleCollider&);
        
    }

}

#endif /* GDK_PHYSICS2D_SIMPLECOLLIDER_H  */
