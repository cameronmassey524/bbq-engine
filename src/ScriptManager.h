#pragma once
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "Types.h"

namespace bbq
{
    class ScriptManager
    {
        private:
            
        
        public:
            sol::state lua;
            void Startup();
            void Shutdown();
            void Update();
            bool LoadScript( const string& name, const string& path);
    };
}