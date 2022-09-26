#include "SoundManager.h"
#include "soloud.h"
#include "soloud_wav.h"
#include <string>
#include <iostream>

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
    std::string fullpath = path + name;
    
    mSoundManager->sample.load(fullpath.c_str());
    //std::cout << fullpath.c_str();
    //mSoundManager->sample.load("assets/sounds/hitsound.wav");

    return false;
}

void SoundManager::PlaySound()
{
    mSoundManager->soloud.play(mSoundManager->sample);
}

SoundManager::SoundManager()
{
    mSoundManager = std::make_unique<SoundManagerImpl>();
}

SoundManager::~SoundManager()
{
    //idk?
}

