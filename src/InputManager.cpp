#include "InputManager.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "Engine.h"

#include <iostream>

using namespace bbq;

extern Engine game;

void InputManager::Startup()
{
    //does nothing right now
}

void InputManager::Shutdown()
{
    //does nothing right now
}

void InputManager::Update()
{
    glfwPollEvents();
}

bool InputManager::KeyIsPressed(int key_name)
{
    //does nothing right now
    //int test = glfwGetKey((GLFWwindow*) game.graphics.window, key_name);
    int test = glfwGetKey((GLFWwindow*) game.graphics.GetWindow(), key_name);
    if (test == GLFW_PRESS)
    {
        return true;
    }
    return false;
}