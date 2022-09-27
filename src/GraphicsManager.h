#pragma once
#include "Types.h"
#include <memory>
#include <string>

namespace bbq
{
    class GraphicsManager
    {
        friend class InputManager;

        private:
            //void* window;
            class GraphicsManagerImpl;
            std::unique_ptr<GraphicsManagerImpl> mGraphicsManager;
        
        public:
            GraphicsManager();
            ~GraphicsManager();
            void Startup();
            void Shutdown();
            bool ShouldQuit();
            void Draw(const std::vector< Sprite >& sprites);
            bool LoadAnImage(const std::string& name, const std::string& path);
            void* GetWindow();



    };
}