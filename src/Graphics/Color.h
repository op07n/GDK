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
            Color();
            Color(const float aR, const float aG, const float aB, const float aA = 1.);
            Color(const Color &) = default;
            Color(Color &&) = default;
            ~Color() = default;
            
            // Non-mutating operators
            bool operator==(const Color &aOther) const;

            // Mutating operators
            Color& operator=(const Color &aColor) = default;
            Color& operator=(Color &&aColor) = default;
            
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
        
        std::ostream &operator<< (std::ostream &stream, const GFX::Color &aColor);
    }
}

#endif /* GDK_GFX_COLOR_H */
