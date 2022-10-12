#include "ResourceManager.h"
#include <string>
#include <unordered_map>
#include "Types.h"
//#include "Engine.h"

using namespace bbq;

extern Engine game;

class ResourceManager::ResourceManagerImpl
{

    public:
        //std::vector<Sprite> sprites;
        std::unordered_map<string, Sprite> sprites;
        //std::unordered_map<std::string, SoLoud::Wav> sounds;

    private:

};

void ResourceManager::Startup()
{
    
}

void ResourceManager::Shutdown()
{
    
}

void ResourceManager::AddSprite(Sprite s)
{
    mResourceManager->sprites[s.image] = s;
}

Sprite& ResourceManager::GetSprite(std::string name)
{
    return mResourceManager->sprites[name];
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
