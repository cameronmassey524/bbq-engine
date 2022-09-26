#pragma once

#include "GraphicsManager.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "ResourceManager.h"
#include "Types.h"

namespace bbq
{
    class Engine
    {
        public:
            GraphicsManager graphics;
            InputManager input;
            SoundManager sound;

            void Startup();

            void Shutdown();

            void RunGameLoop(const UpdateCallback& callback);
    };
}