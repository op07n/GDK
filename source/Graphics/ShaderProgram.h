// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_SHADERPROGRAM_H
#define GDK_GFX_SHADERPROGRAM_H

//std inc
#include <iosfwd>
//gkd inc
#include "GraphicsResource.h"

namespace GDK
{
	namespace GFX
	{
		/*!
		 ShaderProgram specifies drawing behaviours at the programmable stages in the OpenGL
         programmable pipeline.
    	 */
        class ShaderProgram : public GraphicsResource
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::ShaderProgram&);
		
		public:
			// Mutating operators
			ShaderProgram& operator=(const ShaderProgram&) = default;
			
			// Constructors, destructors
			ShaderProgram() = default;
			ShaderProgram(const ShaderProgram&) = default;
			~ShaderProgram() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::ShaderProgram&);
        
	}

}

#endif /* GDK_GFX_SHADERPROGRAM_H  */
