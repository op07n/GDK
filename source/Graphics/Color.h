//
//  Color.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-25.
//

#ifndef GDK_GFX_COLOR_H
#define GDK_GFX_COLOR_H

namespace GDK
{
    namespace GFX
    {
        struct Color
        {
        public:
            // Data
            float r,g,b,a;
            
            // instancing rules
            Color(const float &aR = 0, const float &aG = 0, const float &aB = 0, const float &aA = 0);
            Color() = delete;
            Color(const Color&) = default;
            ~Color() = default;
            
            // Special colors
            static const Color Black;
            static const Color White;
            static const Color Red;
            static const Color Green;
            static const Color DarkGreen;
            static const Color Blue;
            static const Color DeathlyPink;
            static const Color CornflowerBlue;
            
            /*
            @Override public String toString(){return "Color: { r: "+r+", g: "+g+", b: "+b+", a: "+a+" }";}
            */
            
        };
        
    }
    
}

#endif /* GDK_GFX_COLOR_H */
