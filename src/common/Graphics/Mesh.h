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
            friend std::ostream& operator<< (std::ostream&, const GFX::Mesh&) noexcept;
            
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
            
            /*
             Determines the primitive type used at the primitive assembly stage.
             */
            enum class PrimitiveMode
            {
                Triangles,
                Lines,
                Points
            };
            
        private:
            // Data members
            std::string   m_Name = {};
            
            GFXuint       m_IndexBufferHandle = 0;
            GFXsizei      m_IndexCount        = 0;
            
            GFXuint       m_VertexBufferHandle = 0;
            GFXsizei      m_VertexCount        = 0;
            
            VertexFormat  m_VertexFormat = VertexFormat::Pos3uv2;
            
            PrimitiveMode m_PrimitiveMode = PrimitiveMode::Triangles;
            
        public:
            // Accessors
            std::string getName() const noexcept;
            GFXuint getHandle() const noexcept;
            
            // Public functions
            void draw(const GFXuint aShaderProgramHandle) const noexcept;
            void updateVertexData(const std::vector<GFXfloat> &aNewVertexData, const VertexFormat &aNewVertexFormat, const Mesh::Type &aNewType = Type::Dynamic) noexcept;
            
            // Mutating operators
            Mesh& operator=(const Mesh&) = default;
      
            // Constructors, destructors
            Mesh(const std::string &aName, const Mesh::Type &aType, const VertexFormat &aVertexFormat, const std::vector<GFXfloat> &aVertexData, const std::vector<GFXushort> &aIndexData = std::vector<GFXushort>(), const PrimitiveMode &aPrimitiveMode = PrimitiveMode::Triangles);
            Mesh() = delete;
            Mesh(const Mesh&) = delete;
            Mesh(Mesh&&);
            ~Mesh();
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::Mesh&) noexcept;
        
    }

}

#endif /* GDK_GFX_MESH_H  */
