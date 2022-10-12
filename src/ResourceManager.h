#pragma once

#include <memory>
#include <string>
#include <Types.h>

namespace bbq
{
    class ResourceManager
    {

        public:
            ResourceManager();
            ~ResourceManager();
            void Startup();
            void Shutdown();
            std::string ResolvePath(std::string partial_path);
            void AddSprite(Sprite s);
            Sprite& GetSprite(std::string name);
        private:

            class ResourceManagerImpl;
            std::unique_ptr<ResourceManagerImpl> mResourceManager;
    };
}