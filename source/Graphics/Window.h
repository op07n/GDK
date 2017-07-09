// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#ifndef GDK_GRAPHICS_WINDOW_H
#define GDK_GRAPHICS_WINDOW_H

//GDK inc
#include "../Math/IntVector2.h"
//std inc
#include <functional>
#include <string>

class GLFWwindow;

namespace GDK
{
    namespace GFX
    {
        /*!
         Represents a Window within a desktop windowing system.
         
         Window is responsible for initalizing the graphics context and cleaning it up.
         GLEW, GLFW libs are initialized at construction time of the first window.
         They are cleaned up in the destructor of the last window.
         
         call update whenever you want to process the window's messages.
         call draw whenver you want to update the window's graphics.
         
         */
        class Window final
        {
            friend std::ostream& operator<< (std::ostream& stream, const GFX::Window&);
            
            std::string m_Title;
            GLFWwindow* m_HandleToGLFWWindow;
            
            std::function<void(void)> m_OnInit;
            std::function<void(void)> m_OnUpdate;
            std::function<void(void)> m_OnDraw;
            std::function<void(Window*)> m_OnWantsToClose;
            
        public:
            std::string getTitle();
            void setTitle(const std::string&);
            
            void update();
            void draw();
            
            // Nonmutating operators
            bool operator==(const Window&) = delete;
            
            // Mutating operators
            Window& operator=(Window&) = delete;
            
            /*!
             POD for constructing new Windows
             */
            struct ConstructionParameters
            {
                std::function<void(void)> onInit;
                std::function<void(void)> onUpdate;
                std::function<void(void)> onDraw;
                std::function<void(Window*)> onWantsToClose;
                
                bool fullscreen;
                bool resizeable;
                
                std::string name;
                Math::IntVector2 windowSize;
                
                ConstructionParameters();
                
            };
            
            // Constructors & Destructors
            Window(const ConstructionParameters&);
            Window(const Window&) = delete;
            //Window(Window&&);
            ~Window();
            
        };
        
        std::ostream& operator<< (std::ostream& stream, const GFX::Window&);
        
    }
    
}

#endif /* GDK_GRAPHICS_WINDOW_H */
