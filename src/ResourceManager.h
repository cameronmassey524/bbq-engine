#pragma once

#include <memory>
#include <string>

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
        private:

            class ResourceManagerImpl;
            std::unique_ptr<ResourceManagerImpl> mResourceManager;
    };
}