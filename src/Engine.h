#pragma once

#include "GraphicsManager.h"
#include "InputManager.h"
#include "Types.h"

namespace bbq
{
    class Engine
    {
        public:
            GraphicsManager graphics;
            InputManager input;

            void Startup();

            void Shutdown();

            void RunGameLoop(const UpdateCallback& callback);
    };
}