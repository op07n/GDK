// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_TEXTURE_H
#define GDK_GFX_TEXTURE_H

//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for Texture
    	 */
		class Texture
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Texture&);
		
		public:
			// Mutating operators
			Texture& operator=(const Texture&) = default;
			
			// Constructors, destructors
			Texture() = default;
			Texture(const Texture&) = default;
			~Texture() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::Texture&);
        
	}

}

#endif /* GDK_GFX_TEXTURE_H  */
