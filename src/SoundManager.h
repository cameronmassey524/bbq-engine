#pragma once
//#include "soloud.h"
//#include "soloud_wav.h"
#include <string>
#include <memory>

namespace bbq
{
    class SoundManager
    {

        public:
            SoundManager();
            ~SoundManager();
            void Startup();
            void Shutdown();
            bool LoadSound( const std::string& name, const std::string& path);
            void PlaySound();

        private:
            //SoLoud::Soloud soloud;
            //SoLoud::Wav sample;
            class SoundManagerImpl;
            std::unique_ptr<SoundManagerImpl> mSoundManager;
    };
}