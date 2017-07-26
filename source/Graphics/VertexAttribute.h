// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_VERTEXATTRIBUTE_H
#define GDK_GFX_VERTEXATTRIBUTE_H

//std inc
#include <iosfwd>
#include <string>

namespace GDK
{
	namespace GFX
	{
		/*!
		 A vertex attribute is a component of a vertex (eg: position, uv, normal, color).
         Vertexes are made up of an arbitrary set of components.
    	 */
		struct VertexAttribute final
		{
            // Data members
            const std::string name;
            const int size;
            
			// Mutating operators
			VertexAttribute& operator=(const VertexAttribute&) = default;
			
			// Constructors, destructors
			VertexAttribute() = delete;
            VertexAttribute(const std::string &aName, const int &aSize);
			VertexAttribute(const VertexAttribute&) = default;
            VertexAttribute(VertexAttribute&&) = default;
			~VertexAttribute() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::VertexAttribute&);
        
	}

}

#endif /* GDK_GFX_VERTEXATTRIBUTE_H  */
