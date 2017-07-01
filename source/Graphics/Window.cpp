#include "Window.h"
//std
//#include <iostream>
//third-party
#include <glew/include/GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
//gdk
#include "Color.h"
#include "../Utilities/Exception.h"
#include "../Debug/Logger.h"

using namespace GDK;
using namespace GFX;

const glm::vec2 SCREEN_SIZE(800, 600);
//GLFWwindow* gWindow = NULL;

void initGLFW()
{
    //Debug::log("Initializing GLFW");
    
    // initialise GLFW
    glfwSetErrorCallback([] (int,const char* msg) {throw GDK::Exception(msg);});
    if(!glfwInit())
        throw GDK::Exception("glfwInit failed");
    
}

GLFWwindow* initGLFWWindow()
{
    GLFWwindow* aGLFWWindow = nullptr;
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    aGLFWWindow = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "OpenGL Tutorial", NULL, NULL);
    if(!aGLFWWindow)
        throw GDK::Exception("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    
    return aGLFWWindow;
    
}

Window::Window()
//: gWindow(initGLFWWindow())
{
    initGLFW();
    
    gWindow = initGLFWWindow();
    
    // GLFW settings
    glfwMakeContextCurrent(gWindow);
    
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK)
        throw GDK::Exception("glewInit failed");
    
    // print out some info about the graphics drivers
    /*Debug::log("OpenGL version: ", glGetString(GL_VERSION));
    Debug::log("GLSL version: ", glGetString(GL_SHADING_LANGUAGE_VERSION));
    Debug::log("Vendor: ", glGetString(GL_VENDOR));
    Debug::log("Renderer: ", glGetString(GL_RENDERER));
    */
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw GDK::Exception("OpenGL 3.2 API is not available.");
    
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

Window::~Window()
{
    
    
}
