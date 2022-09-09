#pragma once

#include <string>
#include <functional>
namespace bbq {
    typedef double real;
    typedef std::string string;
    
    class Engine;
    class GraphicsManager;
    class InputManager;

    typedef std::function<void(Engine&)> UpdateCallback;
}