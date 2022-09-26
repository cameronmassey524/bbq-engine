#include "ResourceManager.h"
#include <string>

using namespace bbq;

class ResourceManager::ResourceManagerImpl
{

    public:


    private:

};

void ResourceManager::Startup()
{
    
}

void ResourceManager::Shutdown()
{
    
}


ResourceManager::ResourceManager()
{
    mResourceManager = std::make_unique<ResourceManagerImpl>();
}

ResourceManager::~ResourceManager()
{
    //idk?
}

std::string ResourceManager::ResolvePath(std::string partial_path)
{
    // std::string str_bld = partial_path;
    // if (!(partial_path.substr(0,6).equals("assets")))
    // {
    //     str_bld = "assets"
    // }
    return partial_path;
}
