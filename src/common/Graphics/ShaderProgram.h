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
        class ShaderProgram final
        {
            friend std::ostream &operator<< (std::ostream &, const GFX::ShaderProgram &) noexcept;
            
            // Data members
            std::string m_Name = {};
            GFXuint m_ProgramHandle = 0;
            
        public:
            // Public interface
            ///Setup the shader for drawing, emit a handle for use by meshes
            GFXuint draw() const noexcept;
            
            // Accessors
            std::string const &getName() const noexcept;
            GFXuint getHandle() const noexcept;
            
            // Mutating operators
            ShaderProgram &operator=(const ShaderProgram &) = delete;
            ShaderProgram &operator=(ShaderProgram &&) = delete;
      
            // Constructors, destructors
            ShaderProgram() = delete;
            ShaderProgram(const std::string &aName, const std::string &aVertexSource, const std::string &aFragmentSource);
            ShaderProgram(const ShaderProgram &) = delete;
            ShaderProgram(ShaderProgram &&) noexcept;
            ~ShaderProgram() noexcept;
        };

        std::ostream &operator<< (std::ostream &, const GFX::ShaderProgram &) noexcept;   
    }
}

#endif /* GDK_GFX_SHADERPROGRAM_H  */
