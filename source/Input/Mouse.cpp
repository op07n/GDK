// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 17-07-23.
#include "Mouse.h"
//gdk inc
#include "Debug/Exception.h"
#include "Debug/Logger.h"
#include "Math/Vector2.h"
#include "Graphics/Window.h"
//thirdparty inc
#include <GLFW/glfw3.h>
//std inc
#include <iostream>

using namespace GDK;
using namespace Input;

std::ostream& GDK::Input::operator<<(std::ostream& s, const Input::Mouse& a)
{
    s.clear(); s << "{"
    // << "m_Member: " << a.m_Member << ", "
    << "Mouse's: " << "operator<< has not been implemented"
    << "}"; return s;

}

static int glfwMouseButtonFromButton(const Mouse::Button &a)
{
    switch(a)
    {
            
        case Mouse::Button::Left:   return GLFW_MOUSE_BUTTON_LEFT;
        case Mouse::Button::Right:  return GLFW_MOUSE_BUTTON_RIGHT;
        case Mouse::Button::Middle: return GLFW_MOUSE_BUTTON_MIDDLE;
        case Mouse::Button::Four:   return GLFW_MOUSE_BUTTON_4;
        case Mouse::Button::Five:   return GLFW_MOUSE_BUTTON_5;
        case Mouse::Button::Six:    return GLFW_MOUSE_BUTTON_6;
        case Mouse::Button::Seven:  return GLFW_MOUSE_BUTTON_7;
        case Mouse::Button::Eight:  return GLFW_MOUSE_BUTTON_8;
        
    }
    
}

bool Mouse::getButtonDown(const Button &aButton)
{
    if (auto ptr = m_HandleToGLFWWindow.lock())
        return glfwGetMouseButton(ptr.get(), glfwMouseButtonFromButton(aButton));
    
    throw GDK::Exception("The mouse's window has died!");
    
}

Math::Vector2 Mouse::getCursorPosition()
{
    if (auto ptr = m_HandleToGLFWWindow.lock())
    {
        double x,y;
        glfwGetCursorPos(ptr.get(),&x,&y);
        return Math::Vector2((float)x,(float)y);
        
    }
    
    throw GDK::Exception("The mouse's window has died!");
    
}

bool Mouse::getButton(const Button &aKeyCode)
{
    throw GDK::Exception("Mouse::getButton(const Button &aKeyCode) not implemented");

}

Mouse::Mouse(const GFX::Window &aWindow)
: m_HandleToGLFWWindow(aWindow.getHandleToGLFWWindow())
{}
