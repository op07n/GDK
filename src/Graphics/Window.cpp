// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#include "Window.h"
//gdk inc
#include "Color.h"
#include "Debug/Exception.h"
#include "Debug/Logger.h"
#include "GL.h"
#include "Math/IntVector2.h"
//thirdparty inc
#include <glfw/include/GLFW/glfw3.h> // must come after GL

using namespace GDK;
using namespace GFX;

static constexpr char TAG[] = "Window";

int s_InstanceCount = 0;

std::ostream &GDK::GFX::operator<< (std::ostream &s, const GFX::Window &a)
{
    s.clear(); s
    << "{"
    << "m_Title: "  << a.m_Title              << ", "
    << "m_Handle: " << a.m_HandleToGLFWWindow
    << "}";
    
    return s;
}

static inline void initGLFW()
{
    Debug::log(TAG, "Initializing GLFW");
    
    // initialise GLFW
    glfwSetErrorCallback([] (int,const char* msg) {throw GDK::Exception(TAG, msg);});
    if(!glfwInit())
        throw GDK::Exception(TAG, "glfwInit failed");
    
    //glfwSwapInterval(0);
}

static inline void destroyGLFW()
{
    Debug::log(TAG, "Destroying GLFW");
    glfwTerminate();
}

static inline void initGLEW()
{
    glewExperimental = GL_TRUE; //VAO gen and bind were unavailable in non experimental.
    
    if(glewInit() != GLEW_OK)
        throw GDK::Exception(TAG, "glewInit failed");
    
    while (glGetError()); //Clear errors.
    
    // log device info
    Debug::log(TAG, "OpenGL version: ", glGetString(GL_VERSION));
    Debug::log(TAG, "GLSL version: ",   glGetString(GL_SHADING_LANGUAGE_VERSION));
    Debug::log(TAG, "Vendor: ",         glGetString(GL_VENDOR));
    Debug::log(TAG, "Renderer: ",       glGetString(GL_RENDERER));
}

static inline GLFWwindow *initGLFWWindow(const Math::IntVector2 &aScreenSize, const std::string &aName)
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
    
    aGLFWWindow = glfwCreateWindow(aScreenSize.x, aScreenSize.y, aName.c_str(), nullptr, nullptr);
    
    if(!aGLFWWindow)
        throw GDK::Exception(TAG, "glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    
    glfwMakeContextCurrent(aGLFWWindow);
    
    if (s_InstanceCount <= 0)
    {
        initGLEW();
        
        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
    }
    
    GLH::ClearColor(GFX::Color::CornflowerBlue);
    
    return aGLFWWindow;
}
    
Window::Window(const ConstructionParameters &aParams)
: m_Title(aParams.name)
, m_HandleToGLFWWindow(initGLFWWindow(aParams.windowSize, aParams.name), [](GLFWwindow* ptr){glfwDestroyWindow(ptr);})
, m_OnInit(aParams.onInit)
, m_OnUpdate(aParams.onUpdate)
, m_OnDraw(aParams.onDraw)
, m_OnWantsToClose(aParams.onWantsToClose)
{
    if (aParams.onWantsToClose == nullptr)
        throw GDK::Exception(TAG, "A GFX::Window's wantsToClose event was not handled!");
        
    if (m_OnInit != nullptr)
        m_OnInit(*this);
        
    ++s_InstanceCount;
}
    
Window::Window(Window &&a)
{
    m_Title              = a.m_Title;
    m_HandleToGLFWWindow = a.m_HandleToGLFWWindow;
    m_OnInit             = a.m_OnInit;
    m_OnUpdate           = a.m_OnUpdate;
    m_OnDraw             = a.m_OnDraw;
    m_OnWantsToClose     = a.m_OnWantsToClose;
}
    
Window::~Window()
{
    if (m_HandleToGLFWWindow.get() != nullptr)
        --s_InstanceCount;
        
    if (s_InstanceCount < 0)
        destroyGLFW();
}

void Window::draw()
{
    glfwMakeContextCurrent(m_HandleToGLFWWindow.get());
    
    if (m_OnDraw != nullptr)
        m_OnDraw(*this);
    
    glfwSwapBuffers(m_HandleToGLFWWindow.get());
}

void Window::update()
{
    if(!glfwWindowShouldClose(m_HandleToGLFWWindow.get()))
    {
        glfwMakeContextCurrent(m_HandleToGLFWWindow.get());
        
        if (m_OnUpdate != nullptr)
            m_OnUpdate(*this);
        
        glfwPollEvents();
    }
    else
    {
        if (m_OnWantsToClose != nullptr)
            m_OnWantsToClose(*this);
    }
}

std::string Window::getTitle()const
{
    return m_Title;
}

void Window::setTitle(const std::string& aTitle)
{
    m_Title = aTitle;
    glfwSetWindowTitle(m_HandleToGLFWWindow.get(),aTitle.c_str());
}

std::weak_ptr<GLFWwindow> Window::getHandleToGLFWWindow() const
{
    return std::weak_ptr<GLFWwindow>(m_HandleToGLFWWindow);
}

Math::IntVector2 Window::getFramebufferSize() const
{
    Math::IntVector2 frameBufferSize;
    glfwGetWindowSize(m_HandleToGLFWWindow.get(), &frameBufferSize.x, &frameBufferSize.y);
    
    return frameBufferSize;
}

