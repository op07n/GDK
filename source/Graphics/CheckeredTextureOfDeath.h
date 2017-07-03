// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-03.
#ifndef GDK_GFX_CHECKEREDTEXTUREOFDEATH_H
#define GDK_GFX_CHECKEREDTEXTUREOFDEATH_H

//gdk inc
#include "Texture.h"

namespace GDK
{
	namespace GFX
	{
        namespace Fallbacks
        {
            /*!
             Creates the checkeredTextureOfDeath.
             Very low resolution tiled texture, alternating white a blue.
             Useful as a fallback when the intended texture has failed to load.
             */
            Texture createCheckeredTextureOfDeath();
            
        }
		
	}

}

#endif /* GDK_GFX_CHECKEREDTEXTUREOFDEATH_H  */
