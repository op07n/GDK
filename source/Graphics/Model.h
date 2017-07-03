// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MODEL_H
#define GDK_GFX_MODEL_H

//gdk inc
#include "ShaderProgram.h"
#include "Mesh.h"
//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
         Represents a 3D object. Contains a Mesh, a set of uniform collections, a shader, animations, a skeleton.
         */
		class Model final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Model&);
            
            // Data members
            //TODO: refer to G2Dj GraphicsObject
            
		public:
            
			// Mutating operators
			Model& operator=(const Model&) = delete;
			
			// Constructors, destructors
            Model(const Model&, const ShaderProgram&);
			Model() = delete;
			Model(const Model&) = delete;
			~Model() = default;
			
		};
        
		std::ostream& operator<< (std::ostream&, const GFX::Model&);
        
	}

}

#endif /* GDK_GFX_MODEL_H  */
