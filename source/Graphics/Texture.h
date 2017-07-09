// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_TEXTURE_H
#define GDK_GFX_TEXTURE_H

//gdk inc
#include "DataTypes.h"
//std inc
#include <iosfwd>
#include <string>

namespace GDK
{
	namespace GFX
	{
		/*!
		 Texture represents an image. RGBA, 2D.
    	 */
		class Texture final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Texture&);
            
            // Data members
            std::string m_Name;
            GFXuint m_Handle;
		
		public:
            // Accessors
            std::string getName();
            GFXuint getHandle();
            
			// Mutating operators
			Texture& operator=(const Texture&) = delete;
			
			// Constructors, destructors
			Texture() = delete;
            Texture(const std::string &aName,std::vector<GFXbyte>& aTextureData /*GFXuint repeatmode = 0, GFXuint magfilter = 0*/);
			Texture(const Texture&) = delete;
            Texture(Texture&&);
			~Texture();
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::Texture&);
        
	}

}

#endif /* GDK_GFX_TEXTURE_H  */
