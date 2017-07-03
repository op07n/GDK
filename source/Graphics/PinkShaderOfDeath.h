// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_PINKSHADEROFDEATH_H
#define GDK_GFX_PINKSHADEROFDEATH_H

#include "ShaderProgram.h"

namespace GDK
{
	namespace GFX
	{
        namespace Fallbacks
        {
            /*!
             Creates the PinkShaderOfDeath.
             Muls verts through standard MVP but colors all frags an obnoxious fluorescent pink.
             Useful as a fallback shader.
             */
            ShaderProgram createPinkShaderOfDeath();
        
        }
        
	}

}

#endif /* GDK_GFX_PINKSHADEROFDEATH_H  */
