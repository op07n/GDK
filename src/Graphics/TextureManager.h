// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-15.
#ifndef GDK_GFX_TEXTUREMANAGER_H
#define GDK_GFX_TEXTUREMANAGER_H

//gdk inc
#include "Memory/resource_manager.h"
#include "Texture.h"
//std inc
#include <iosfwd>

namespace GDK
{
    namespace GFX
    {
        /*!
         Instantiates, destroys and serves Texture objects to the program
         */
        class TextureManager final : public resource_manager<Texture>
        {
            friend std::ostream &operator<< (std::ostream &, const GFX::TextureManager &);
      
        public:
            // Mutating operators
            TextureManager &operator=(const TextureManager &) = default;
            TextureManager &operator=(TextureManager &&) = default;
      
            // Constructors, destructors
            TextureManager();
            TextureManager(const TextureManager &) = default;
            TextureManager(TextureManager &&) = default;
            virtual ~TextureManager() = default;
        };

        std::ostream &operator<< (std::ostream &, const GFX::TextureManager &);
    }
}

#endif /* GDK_GFX_TEXTUREMANAGER_H  */
