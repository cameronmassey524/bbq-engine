#pragma once
#include "Types.h"
//#include "Engine.h"
#include "EntityManager.h"
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
            //void Draw(const std::vector< Sprite >& sprites);
            void Draw();
            bool LoadAnImage(const std::string& name, const std::string& path);
            void* GetWindow();



    };
}