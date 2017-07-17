// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_SHADERPROGRAMMANAGER_H
#define GDK_GFX_SHADERPROGRAMMANAGER_H

//gdk inc
#include "ResourceManager.h"
#include "../Graphics/ShaderProgram.h"
//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for ShaderProgramManager
    	 */
		class ShaderProgramManager final : public ResourceManager<ShaderProgram>
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::ShaderProgramManager&);
			
			// Data members

		public:
			// Accessors
			
			// Public methods
			
			// Mutating operators
			ShaderProgramManager& operator=(const ShaderProgramManager&) = default;
			
			// Constructors, destructors
			ShaderProgramManager();
			ShaderProgramManager(const ShaderProgramManager&) = default;
			ShaderProgramManager(ShaderProgramManager&&) = default;
			virtual ~ShaderProgramManager() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::ShaderProgramManager&);
        
	}

}

#endif /* GDK_GFX_SHADERPROGRAMMANAGER_H  */