#pragma once

namespace bbq
{
    class GraphicsManager
    {
        friend class InputManager;

        private:
            void* window;
        
        public:
            void Startup();
            void Shutdown();
            bool ShouldQuit();


    };
}