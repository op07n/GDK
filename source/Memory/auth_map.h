// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-29.
#ifndef GDK_MEMORY_AUTH_MAP_H
#define GDK_MEMORY_AUTH_MAP_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace Memory
    {
        /*!
         No description provided for auth_map
         */
        class auth_map final
        {
            friend std::ostream& operator<< (std::ostream&, const Memory::auth_map&);
			
            // Data members

        public:
            // Accessors
			
            // Public methods
			
            // Mutating operators
            auth_map& operator=(const auth_map&) = delete;
			
            // Constructors, destructors
            auth_map() = delete;
            auth_map(const auth_map&) = delete;
            auth_map(auth_map&&) = delete;
            ~auth_map() = delete;
			
        };

        std::ostream& operator<< (std::ostream&, const Memory::auth_map&);
        
	}

}

#endif /* GDK_MEMORY_AUTH_MAP_H  */
