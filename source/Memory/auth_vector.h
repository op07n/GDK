// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_MEMORY_AUTH_VECTOR_H
#define GDK_MEMORY_AUTH_VECTOR_H

//std inc
#include <iosfwd>
#include <vector>

namespace GDK
{
    namespace Memory
    {
        /*!
         No description provided for auth_vector
         */
        class auth_vector final
        {
            friend std::ostream& operator<< (std::ostream&, const Memory::auth_vector&);
      
            // Data members

        public:
            // Accessors
      
            // Public methods
      
            // Mutating operators
            auth_vector& operator=(const auth_vector&) = delete;
      
            // Constructors, destructors
            auth_vector() = delete;
            auth_vector(const auth_vector&) = delete;
            auth_vector(auth_vector&&) = delete;
            ~auth_vector() = delete;
      
        };

        std::ostream& operator<< (std::ostream&, const Memory::auth_vector&);
        
    }

}

#endif /* GDK_MEMORY_AUTH_VECTOR_H  */
