// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#ifndef GDK_GFX_COLOR_H
#define GDK_GFX_COLOR_H

//std inc
#include <iosfwd>

namespace GDK
{
    namespace GFX
    {
        /*!
         Represents a 4 channel color: {Red, Green, Blue, Alpha}.
         */
        struct Color final
        {
            // Data
            float r = 0.f, g = 0.f, b = 0.f, a = 0.f;
            
            // instancing rules
            Color() noexcept;
            Color(const float aR, const float aG, const float aB, const float aA = 1.) noexcept;
            Color(const Color &) noexcept = default;
            Color(Color &&) noexcept = default;
            ~Color() noexcept = default;
            
            // Mutating operators
            Color& operator=(const Color &aColor) noexcept = default;
            Color& operator=(Color &&aColor) noexcept = default;
            
            // Special colors
            static const Color Black;
            static const Color White;
            static const Color Red;
            static const Color Green;
            static const Color DarkGreen;
            static const Color Blue;
            static const Color DeathlyPink;
            static const Color CornflowerBlue;
        };
        
        std::ostream &operator<< (std::ostream &stream, const GFX::Color &aColor) noexcept;
    }
}

#endif /* GDK_GFX_COLOR_H */
