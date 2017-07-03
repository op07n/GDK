// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MESH_H
#define GDK_GFX_MESH_H

//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 No description provided for Mesh
    	 */
		class Mesh
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Mesh&);
		
		public:
			// Mutating operators
			Mesh& operator=(const Mesh&) = default;
			
			// Constructors, destructors
			Mesh() = default;
			Mesh(const Mesh&) = default;
			~Mesh() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::Mesh&);
        
	}

}

#endif /* GDK_GFX_MESH_H  */
