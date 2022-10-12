#pragma once

#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "ResourceManager.h"
#include "EntityManager.h"
#include "Types.h"
#include "ScriptManager.h"

namespace bbq
{
    class Engine
    {
        public:
            GraphicsManager graphics;
            InputManager input;
            SoundManager sound;
            EntityManager ecs;
            ResourceManager resources;
            ScriptManager scripting;

            void Startup();

            void Shutdown();

            void RunGameLoop(const UpdateCallback& callback);
    };
}