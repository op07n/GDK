// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-23.
#ifndef GDK_INPUT_MOUSE_H
#define GDK_INPUT_MOUSE_H

//std inc
#include <iosfwd>
#include <memory>

class GLFWwindow;
namespace GDK{namespace GFX{class Window;}}
namespace GDK{namespace Math{class Vector2;}}

namespace GDK
{
	namespace Input
	{
		/*!
		 No description provided for Mouse
    	 */
		class Mouse final
		{
			friend std::ostream& operator<< (std::ostream&, const Input::Mouse&);
			
			// Data members
            std::weak_ptr<GLFWwindow> m_HandleToGLFWWindow;

		public:
			enum class Button
            {
                Left,
                Right,
                Middle,
                Four,
                Five,
                Six,
                Seven,
                Eight
                
            };
            
            // Public methods
            /// Check if the button is being held down
            bool getButtonDown(const Button &aKeyCode);
            /// Check if the button was just pressed
            bool getButton(const Button &aKeyCode);
            /// Viewcoordinate of curosr
            Math::Vector2 getCursorPosition();
            
            
			// Mutating operators
			Mouse& operator=(const Mouse&) = default;
			
			// Constructors, destructors
            Mouse(const GFX::Window&);
			Mouse() = delete;
			Mouse(const Mouse&) = default;
			Mouse(Mouse&&) = default;
			~Mouse() = default;
			
		};

		std::ostream& operator<< (std::ostream&, const Input::Mouse&);
        
	}

}

#endif /* GDK_INPUT_MOUSE_H  */
