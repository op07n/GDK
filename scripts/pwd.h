// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_PWD_H
#define GDK_GFX_PWD_H

//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for pwd
    	 */
		class pwd final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::pwd&);
			
			// Data members

		public:
			// Accessors
			
			// Public methods
			
			// Mutating operators
			pwd& operator=(const pwd&) = delete;
			
			// Constructors, destructors
			pwd() = delete;
			pwd(const pwd&) = delete;
			pwd(pwd&&) = delete;
			~pwd() = delete;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::pwd&);
        
	}

}

#endif /* GDK_GFX_PWD_H  */
