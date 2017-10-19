// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_SHADERPROGRAMMANAGER_H
#define GDK_GFX_SHADERPROGRAMMANAGER_H

//gdk inc
#include "Memory/resource_manager.h"
#include "Graphics/ShaderProgram.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace GFX
    {
        /*!
         Instantiates, destroys and serves shader objects to the program
         */
        class ShaderProgramManager final : public resource_manager<ShaderProgram>
        {
            friend std::ostream& operator<< (std::ostream&, const GFX::ShaderProgramManager&) noexcept;
            
        public:
            // Mutating operators
            ShaderProgramManager& operator=(const ShaderProgramManager&) = default;
      
            // Constructors, destructors
            ShaderProgramManager() noexcept;
            ShaderProgramManager(const ShaderProgramManager&) = default;
            ShaderProgramManager(ShaderProgramManager&&) = default;
            virtual ~ShaderProgramManager() noexcept = default;
      
        };

        std::ostream& operator<< (std::ostream&, const GFX::ShaderProgramManager&) noexcept;
        
    }

}

#endif /* GDK_GFX_SHADERPROGRAMMANAGER_H  */
