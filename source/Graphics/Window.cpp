#include "Window.h"
//std
#include <iostream>
//third-party
#include <glew/include/GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
//gdk
#include "Color.h"

using namespace GDK;
using namespace GFX;

const glm::vec2 SCREEN_SIZE(800, 600);
GLFWwindow* gWindow = NULL;

void OnError(int errorCode, const char* msg)
{
    throw std::runtime_error(msg);
    
}

Window::Window()
{
    std::cout << "GDK::Graphics::Graphics()\n";
    
    // initialise GLFW
    glfwSetErrorCallback(OnError);
    if(!glfwInit())
        throw std::runtime_error("glfwInit failed");
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    gWindow = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "OpenGL Tutorial", NULL, NULL);
    if(!gWindow)
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    
    // GLFW settings
    glfwMakeContextCurrent(gWindow);
    
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
    
    glClearColor(GFX::Color::CornflowerBlue.r, GFX::Color::CornflowerBlue.g, GFX::Color::CornflowerBlue.b, GFX::Color::CornflowerBlue.a); // Tradtion since XNA
    
    // run while the window is open
    while(!glfwWindowShouldClose(gWindow))
    {
        // process pending events
        glfwPollEvents();
        
        // draw one frame
        //Render();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(gWindow);
        
    }
    
    // clean up and exit
    glfwTerminate();
    
}
