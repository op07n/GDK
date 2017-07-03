// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_MESH_H
#define GDK_GFX_MESH_H

//gdk inc
#include "DataTypes.h"
#include "VertexFormat.h"
//std inc
#include <iosfwd>

namespace GDK
{
	namespace GFX
	{
		/*!
		 Vertex data representing a 3D graphical object
    	 */
		class Mesh
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Mesh&);
            
            // Data members
            GFXuint m_VertexBufferHandle;
            int m_VertexCount;
            VertexFormat m_VertexFormat;
            
		public:
            // Accessors
            GFXuint getHandle();
            int getVertexCount();
            
            void draw(const GFXuint aShaderProgramHandle);
            
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
