// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_VERTEXFORMAT_H
#define GDK_GFX_VERTEXFORMAT_H

//gdk inc
#include "VertexAttribute.h"
//std inc
#include <iosfwd>
#include <map>
#include <string>
#include <vector>

namespace GDK
{
	namespace GFX
	{
		/*!
		 Vertex data is arbitrary and user defined. Vertexformat is used to inform the
         device how to interpret the vertex data in your mesh. An example of a typical format would be
         something like this: {Position,UV,Normal,Tangent}. The important thing is that this matches
         the actual vertex data in the mesh's vertex buffer.
    	 */
		class VertexFormat final
		{
			friend std::ostream& operator<< (std::ostream&, const GFX::VertexFormat&);
		
            // Data members
            std::map<std::string,int> m_Format;
            int m_NumberOfAttributes;
            int m_TotalNumberOfAttributeComponents;
            
		public:
            // Accessors
            int getSumOfAttributeComponents();
            int getNumberOfAttributes();
            int getAttributeSize(const std::string &aAttributeName);
            std::vector<std::string> getNames();
            
			// Mutating operators
			VertexFormat& operator=(const VertexFormat&) = delete;
			
			// Constructors, destructors
            VertexFormat(const std::vector<VertexAttribute> &aAttributes);
            VertexFormat() = delete;
			VertexFormat(const VertexFormat&) = delete;
			~VertexFormat() = default;
            
            // Special values
            static VertexFormat Pos3uv2;
            static VertexFormat Pos3;
			
		};

		std::ostream& operator<< (std::ostream&, const GFX::VertexFormat&);
        
	}

}

#endif /* GDK_GFX_VERTEXFORMAT_H  */
