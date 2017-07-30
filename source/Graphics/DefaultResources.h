// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_CHECKEREDTEXTUREOFDEATH_H
#define GDK_GFX_CHECKEREDTEXTUREOFDEATH_H

//gdk inc
#include "Texture.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Memory/default_ptr.h"

namespace GDK
{
    namespace GFX
    {
        namespace DefaultResources
        {
            /// Creates the checkeredTextureOfDeath.
            /// Very low resolution tiled texture, alternating white a blue.
            /// Useful as a fallback when the intended texture has failed to load.
            Memory::default_ptr<Texture> getCheckeredTextureOfDeath();
            
            /// Creates the PinkShaderOfDeath.
            /// Muls verts through standard MVP but colors all frags an obnoxious fluorescent pink.
            /// Useful as a fallback shader.
            Memory::default_ptr<ShaderProgram> getPinkShaderOfDeath();
            
            /// Basic alphacutoff shader
            Memory::default_ptr<ShaderProgram> getAlphaCutOff();
            
            /// Make a unit length quad
            Memory::default_ptr<Mesh> getQuad();
            
            /// Make a unit length cube
            Memory::default_ptr<Mesh> getCube();
            
        }
    
    }

}

#endif /* GDK_GFX_CHECKEREDTEXTUREOFDEATH_H  */
