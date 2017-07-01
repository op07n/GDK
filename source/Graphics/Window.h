// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#ifndef GDK_GRAPHICS_WINDOW_H
#define GDK_GRAPHICS_WINDOW_H

//GDK inc
#include "../Utilities/Macros.h"

class GLFWwindow;

namespace GDK
{
    namespace GFX
    {
        /*!
         Create a graphics window. Initalizes an OpenGL context for drawing.
         */
        class Window
        {
            GLFWwindow* gWindow;
            
        public:
            // Mutating operators
            Window& operator=(const Window&) = delete;
            
            // Constructors & Destructors
            Window();
            Window(const Window&) = delete;
            ~Window();
        
        };
        
    }
    
}

#endif /* GDK_GRAPHICS_WINDOW_H */
