// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MODEL_H
#define GDK_GFX_MODEL_H

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
            
		public:
            
			// Mutating operators
			Model& operator=(const Model&) = delete;
			
			// Constructors, destructors
			Model() = default;
			Model(const Model&) = delete;
			~Model() = default;
			
		};
        
		std::ostream& operator<< (std::ostream&, const GFX::Model&);
        
	}

}

#endif /* GDK_GFX_MODEL_H  */
