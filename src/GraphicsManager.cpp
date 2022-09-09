#include "GraphicsManager.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <string>
#include <iostream>

using namespace bbq;

    
void GraphicsManager::Startup()
{
    //hard coding these for now
    int window_width = 640;
    int window_height = 480;
    int window_fullscreen = 0;
    const char * window_name = "default window name";

    glfwInit();
    // We'll use sokol_gfx's OpenGL backend
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    //GLFWwindow* window = glfwCreateWindow( window_width, window_height, window_name, window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0 );
    this->window = (void*) glfwCreateWindow( window_width, window_height, window_name, window_fullscreen ? glfwGetPrimaryMonitor() : 0, 0 );
    glfwSetWindowAspectRatio( (GLFWwindow*) window, window_width, window_height );
    if( !this->window )
    {
        std::cerr << "Failed to create a window." << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent( (GLFWwindow*) this->window );
    glfwSwapInterval(0);
}

void GraphicsManager::Shutdown()
{
    //does nothing right now
}

bool GraphicsManager::ShouldQuit()
{
    if (glfwWindowShouldClose((GLFWwindow*)this->window))
    {
        return true;
    }
    return false;
}