// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_CHECKEREDTEXTUREOFDEATH_H
#define GDK_GFX_CHECKEREDTEXTUREOFDEATH_H

//gdk inc
#include "Texture.h"
#include "ShaderProgram.h"
#include "Mesh.h"

namespace GDK
{
	namespace GFX
	{
        namespace DefaultResources
        {
            /// Creates the checkeredTextureOfDeath.
            /// Very low resolution tiled texture, alternating white a blue.
            /// Useful as a fallback when the intended texture has failed to load.
            Texture createCheckeredTextureOfDeath();
            
            /// Creates the PinkShaderOfDeath.
            /// Muls verts through standard MVP but colors all frags an obnoxious fluorescent pink.
            /// Useful as a fallback shader.
            ShaderProgram createPinkShaderOfDeath();
            
            /// Basic alphacutoff shader
            ShaderProgram createAlphaCutOff();
            
            /// Make a basic quad
            Mesh createQuad();
            
        }
		
	}

}

#endif /* GDK_GFX_CHECKEREDTEXTUREOFDEATH_H  */
