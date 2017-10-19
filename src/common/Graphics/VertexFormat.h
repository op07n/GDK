// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_VERTEXFORMAT_H
#define GDK_GFX_VERTEXFORMAT_H

//gdk inc
#include "DataTypes.h"
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
            friend std::ostream& operator<< (std::ostream&, const GFX::VertexFormat&) noexcept;
    
            // Data members
            std::vector<VertexAttribute> m_Format = {};
            int m_SumOfAttributeComponents = 0;
            
        public:
            // Public methods
            void enableAttributes(const GFXuint &aShaderProgramHandle) noexcept;
            int getSumOfAttributeComponents() const noexcept;
            
            // Mutating operators
            VertexFormat& operator=(const VertexFormat&) = default;
      
            // Constructors, destructors
            VertexFormat(const std::vector<VertexAttribute> &aAttributes) noexcept;
            VertexFormat() = delete;
            VertexFormat(const VertexFormat&) = default;
            VertexFormat(VertexFormat&&) = default;
            ~VertexFormat() = default;
            
            // Special values
            static const VertexFormat Pos3uv2Norm3;
            static const VertexFormat Pos3uv2;
            static const VertexFormat Pos3;
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::VertexFormat&) noexcept;
        
    }

}

#endif /* GDK_GFX_VERTEXFORMAT_H  */
