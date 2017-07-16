// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_TEXTUREMANAGER_H
#define GDK_GFX_TEXTUREMANAGER_H

//gdk inc
#include "ResourceManager.h"
#include "Texture.h"
//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for TextureManager
    	 */
        class TextureManager final : public ResourceManager<Texture>
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::TextureManager&);
			
			// Data members
            
            
		public:
			// Accessors
			
			// Public methods
			
			// Mutating operators
			TextureManager& operator=(const TextureManager&) = default;
			
			// Constructors, destructors
            TextureManager();
			TextureManager(const TextureManager&) = default;
			TextureManager(TextureManager&&) = default;
			virtual ~TextureManager() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::TextureManager&);
        
	}

}

#endif /* GDK_GFX_TEXTUREMANAGER_H  */
