// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-01.
#ifndef GDK_DEBUG_EXCEPTION_H
#define GDK_DEBUG_EXCEPTION_H

//std inc
#include <stdexcept>

namespace GDK
{
	namespace Debug
	{
		/*!
		 No description provided for Exception
    	 */
        class Exception : public std::runtime_error
        {
		
		public:
			// Mutating operators
			Exception& operator=(const Exception&) = default;
			
			// Constructors, destructors
			Exception() = default;
			Exception(const Exception&) = default;
			~Exception() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const Debug::Exception&);
        
	}

}

#endif /* GDK_DEBUG_EXCEPTION_H  */
