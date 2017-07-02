#include "Window.h"
//thirdpart inc
#include <glew/include/GL/glew.h>
#include <GLFW/glfw3.h>
//gdk inc
#include "Color.h"
#include "../Utilities/Exception.h"
#include "../Debug/Logger.h"
#include "../Math/IntVector2.h"

using namespace GDK;
using namespace GFX;

int s_InstanceCount = 0;

void initGLFW()
{
    Debug::log("Initializing GLFW");
    
    // initialise GLFW
    glfwSetErrorCallback([] (int,const char* msg) {throw GDK::Exception(msg);});
    if(!glfwInit())
        throw GDK::Exception("glfwInit failed");
    
}

void destroyGLFW()
{
    Debug::log("Destroying GLFW");
    glfwTerminate();
    
}

void initGLEW()
{
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK)
        throw GDK::Exception("glewInit failed");
    
    // log device info
    Debug::log("OpenGL version: ", glGetString(GL_VERSION));
    Debug::log("GLSL version: "  , glGetString(GL_SHADING_LANGUAGE_VERSION));
    Debug::log("Vendor: "        , glGetString(GL_VENDOR));
    Debug::log("Renderer: "      , glGetString(GL_RENDERER));
    
}

GLFWwindow* initGLFWWindow(const Math::IntVector2 &aScreenSize, const std::string &aName)
{
    if (s_InstanceCount <= 0)
        initGLFW();
    
    GLFWwindow* aGLFWWindow = nullptr;
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, true);
    
    static int s_InstanceCounter = 0;
    s_InstanceCounter++;
    
    aGLFWWindow = glfwCreateWindow(aScreenSize.x, aScreenSize.y, aName.c_str(), nullptr, nullptr);
    if(!aGLFWWindow)
        throw GDK::Exception("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    
    glfwMakeContextCurrent(aGLFWWindow);
    
    initGLEW();
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw GDK::Exception("OpenGL 3.2 API is not available.");
    
    if (s_InstanceCounter == 0)
    glClearColor(GFX::Color::CornflowerBlue.r, GFX::Color::CornflowerBlue.g, GFX::Color::CornflowerBlue.b, GFX::Color::CornflowerBlue.a); // Tradtion since XNA
    else
        glClearColor(1,0,0,1);
    
    return aGLFWWindow;
    
}

Window::ConstructionParameters::ConstructionParameters()
: onUpdate(nullptr)
, onDraw(nullptr)
, onWantsToClose(nullptr)
, fullscreen(false)
, resizeable(false)
, name("GDK Window")
, windowSize(Math::IntVector2(800,600))
{}

Window::Window(const ConstructionParameters& aParams)
: m_HandleToGLFWWindow(initGLFWWindow(aParams.windowSize,aParams.name))
, m_OnUpdate(aParams.onUpdate)
, m_OnDraw(aParams.onDraw)
, m_OnWantsToClose(aParams.onWantsToClose)
{
    if (aParams.onWantsToClose == nullptr)
        throw GDK::Exception("A GFX::Window's wantsToClose event was not handled!");
    
    ++s_InstanceCount;
    
}

Window::Window(Window&& aOther)
{
    m_HandleToGLFWWindow = aOther.m_HandleToGLFWWindow;
    m_OnUpdate = aOther.m_OnUpdate;
    m_OnDraw = aOther.m_OnDraw;
    m_OnWantsToClose = aOther.m_OnWantsToClose;
    
    aOther.m_HandleToGLFWWindow = nullptr;
    
}

Window::~Window()
{
    if (m_HandleToGLFWWindow != nullptr)
    {
        glfwDestroyWindow(m_HandleToGLFWWindow);
        --s_InstanceCount;
    
    }
    
    if (s_InstanceCount <= 0)
        destroyGLFW();
    
}

/*bool Window::operator==(const Window& aOther)
{
    if (m_HandleToGLFWWindow == aOther.m_HandleToGLFWWindow)
        return true;
    
    return false;
    
}*/

void Window::draw()
{
    glfwMakeContextCurrent(m_HandleToGLFWWindow);
    
    if (m_OnDraw != nullptr)
        m_OnDraw();
    
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(m_HandleToGLFWWindow);
    
}

void Window::update()
{
    if(m_HandleToGLFWWindow == nullptr || glfwWindowShouldClose(m_HandleToGLFWWindow))//glfwWindowShouldClose(m_HandleToGLFWWindow)
    {
        if (m_OnWantsToClose != nullptr)
            m_OnWantsToClose(this);
        
    }
    else
    {
        glfwMakeContextCurrent(m_HandleToGLFWWindow);
        
        if (m_OnUpdate != nullptr)
            m_OnUpdate();
        
        glfwPollEvents();
        
    }
    
}
