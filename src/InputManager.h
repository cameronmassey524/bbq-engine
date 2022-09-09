#pragma once

namespace bbq
{
    class InputManager
    {
        private:
        
        public:
            void Startup();
            void Shutdown();
            void Update();
            bool KeyIsPressed(int key_name);
    };
}