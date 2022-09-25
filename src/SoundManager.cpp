#include "SoundManager.h"
#include "soloud.h"
#include "soloud_wav.h"
#include <string>

using namespace bbq;

class SoundManager::SoundManagerImpl
{

    private:


    public:
        SoLoud::Soloud soloud;
        SoLoud::Wav sample;

};

void SoundManager::Startup()
{
    mSoundManager->soloud.init();
}

void SoundManager::Shutdown()
{
    mSoundManager->soloud.deinit();
}

bool SoundManager::LoadSound( const std::string& name, const std::string& path )
{
    return false;
}

SoundManager::SoundManager()
{
    mSoundManager = std::make_unique<SoundManagerImpl>();
}

SoundManager::~SoundManager()
{
    //idk?
}

