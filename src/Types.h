#pragma once

#include <string>
#include <functional>
#include "glm/glm.hpp"

namespace bbq {
    typedef double real;
    typedef std::string string;
    
    class Engine;
    class GraphicsManager;
    class InputManager;

    class SoundManager;
    //class GraphicsManager::GraphicsManagerImpl;

    typedef std::function<void(Engine&)> UpdateCallback;
    typedef glm::vec2 vec2;

    typedef struct { string image; real scale; vec2 position; real z; } Sprite;
}