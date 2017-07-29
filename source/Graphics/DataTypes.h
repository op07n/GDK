// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-02.
#ifndef GDK_GFX_DATATYPES_H
#define GDK_GFX_DATATYPES_H

namespace GDK
{
    namespace GFX
    {
        /*!
         Sizes of datatypes used throughout GDK::Graphics headers.
         These must match their OpenGL equivalents, so definitions should be platform specific.
         GFX types are used instead of GL to avoid unnecessary propagation of gl headers.
         */
        using GFXint   = int;
        using GFXuint  = unsigned int;
        using GFXfloat = float;
        using GFXbyte  = unsigned char;
        
    }

}

#endif /* GDK_GFX_DATATYPES_H  */
