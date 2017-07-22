// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#ifndef GDK_EXCEPTION_H
#define GDK_EXCEPTION_H

//std inc
#include <stdexcept>
#include <string>

namespace GDK
{
    /*!
     Basic GDK exception. All GDK exceptions inherit from this.
     This allows users to differentiate between nonGDK and GDK exceptions.
     */
    class Exception : public std::runtime_error
    {
		
	public:
        // Mutating operators
		Exception& operator=(const Exception&) = default;
        
		// Constructors, destructors
        Exception(const std::string &aMessage = "");
		Exception(const Exception&) = default;
        Exception(Exception&&) = default;
		~Exception() = default;
			
	};

	std::ostream& operator<< (std::ostream&, const Exception&);
    
}

#endif /* GDK_EXCEPTION_H  */
