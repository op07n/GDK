// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_SHADERPROGRAM_H
#define GDK_GFX_SHADERPROGRAM_H

//std inc
#include <iosfwd>
#include <string>
//gfx inc
#include "DataTypes.h"

namespace GDK
{
	namespace GFX
	{
		/*!
		 ShaderProgram specifies drawing behaviours at the programmable stages in the OpenGL
         programmable pipeline.
    	 */
        class ShaderProgram
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::ShaderProgram&);
            
            // Data members
            std::string m_Name;
            GFXuint m_ProgramHandle;
            
            
		public:
            // Accessors
            std::string getName();
            GFXuint getHandle();
            
			// Mutating operators
			ShaderProgram& operator=(const ShaderProgram&) = delete;
			
			// Constructors, destructors
            ShaderProgram() = delete;
            ShaderProgram(const std::string &aName,const std::string &aVertexSource,const std::string &aFragmentSource);
			ShaderProgram(const ShaderProgram&) = delete;
			~ShaderProgram();
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::ShaderProgram&);
        
	}

}

#endif /* GDK_GFX_SHADERPROGRAM_H  */