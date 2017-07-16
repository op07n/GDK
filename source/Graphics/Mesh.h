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
#include <string>

namespace GDK
{
	namespace GFX
	{
		/*!
		 Vertex data representing a 3D graphical object
    	 */
		class Mesh final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::Mesh&);
            
            // Data members
            std::string m_Name;
            GFXuint m_VertexBufferHandle;
            int m_VertexCount;
            VertexFormat m_VertexFormat;
            
		public:
            /*!
             Hint to the graphics device about how the vertex data will be used.
             Generally, dynamic data (data that is likely to be frequently rewritten) will be placed
             in video memory with fast read write speeds while static will be placed in slower (and more plentiful)
             video memory. Exact behaviours are implementation specific.
             */
            enum class Type
            {
                Static,
                Dynamic
            };
            
            // Accessors
            std::string getName() const;
            GFXuint getHandle() const;
            
            // Public functions
            void draw(const GFXuint aShaderProgramHandle);
            void updateVertexData(const std::vector<GFXfloat> &aNewVertexData, const VertexFormat &aNewVertexFormat, const Mesh::Type &aNewType = Type::Dynamic);
            
			// Mutating operators
			Mesh& operator=(const Mesh&) = default;
			
			// Constructors, destructors
            Mesh(const std::string &aName, const std::vector<GFXfloat> &aVertexData, const VertexFormat &aVertexFormat, const Mesh::Type &aType);
			Mesh() = delete;
			Mesh(Mesh&&);
			~Mesh();
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::Mesh&);
        
	}

}

#endif /* GDK_GFX_MESH_H  */
