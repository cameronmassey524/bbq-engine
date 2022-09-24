#include "SoundManager.h"
#include "soloud.h"
#include <string>

using namespace bbq;

class SoundManager::SoundManagerImpl
{

    private:
        SoLoud::Soloud soloud;
        SoLoud::Wav sample;

    public:


};

void SoundManager::Startup()
{
    this.soloud.init();
}

void SoundManager::Shutdown()
{
    this.soloud.deinit();
}

bool SoundManager::LoadSound( const string& name, const string& path )
{
    return false;
}


