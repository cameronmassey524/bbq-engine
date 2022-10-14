#pragma once

#include <string>
#include <functional>
#include "glm/glm.hpp"
//#include <sol/sol.hpp>

namespace bbq {
    typedef double real;
    typedef std::string string;
    
    class Engine;
    class GraphicsManager;
    class InputManager;

    class SoundManager;
    class ScriptManager;
    //class GraphicsManager::GraphicsManagerImpl;

    typedef std::function<void(Engine&)> UpdateCallback;
    typedef glm::vec2 vec2;
    typedef glm::vec3 vec3;

    

    //Entity Components
    //struct Position : public vec2 {};
    //struct Velocity : public vec2 {};
    struct Position { real x, y; };
    struct Velocity { real x, y; };
    struct Gravity { real meters_per_second; };
    //struct Sprite { string image; real size; };
    struct Health { real percent; };
    struct Script { string name; };

    typedef long EntityID;

    //sprite
    typedef struct { string image; real scale; vec2 position; real z; } Sprite;
}