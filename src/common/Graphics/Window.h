// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#ifndef GDK_GRAPHICS_WINDOW_H
#define GDK_GRAPHICS_WINDOW_H

//GDK inc
#include "Math/IntVector2.h"
//std inc
#include <functional>
#include <string>
#include <memory>

struct GLFWwindow;

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
            friend std::ostream& operator<< (std::ostream& stream, const GFX::Window&) noexcept;
            
            std::string m_Title = {};
            std::shared_ptr<GLFWwindow> m_HandleToGLFWWindow = {};
            
            std::function<void(const Window&)> m_OnInit         = nullptr;
            std::function<void(const Window&)> m_OnUpdate       = nullptr;
            std::function<void(const Window&)> m_OnDraw         = nullptr;
            std::function<void(const Window&)> m_OnWantsToClose = nullptr;
            
        public:
            // Accessors
            std::string getTitle() const noexcept;
            Math::IntVector2 getFramebufferSize() const noexcept;
            std::weak_ptr<GLFWwindow> getHandleToGLFWWindow() const noexcept;
            
            void setTitle(const std::string&) noexcept;
            
            // Public methods
            void update();
            void draw();
            
            // Mutating operators
            Window& operator=(Window&) = delete;
            
            /*!
             POD for constructing new Windows
             */
            struct ConstructionParameters
            {
                std::function<void(const Window&)> onInit         = nullptr;
                std::function<void(const Window&)> onUpdate       = nullptr;
                std::function<void(const Window&)> onDraw         = nullptr;
                std::function<void(const Window&)> onWantsToClose = nullptr;
                
                bool fullscreen = false;
                bool resizeable = false;
                
                std::string name = "GDK Window";
                
                Math::IntVector2 windowSize = {800,600};
                
            };
            
            // Constructors & Destructors
            Window(const ConstructionParameters&);
            Window(const Window&) = delete;
            Window(Window&&) noexcept;
            ~Window() noexcept;
            
        };
        
        std::ostream& operator<< (std::ostream& stream, const GFX::Window&) noexcept;
        
    }
    
}

#endif /* GDK_GRAPHICS_WINDOW_H */
