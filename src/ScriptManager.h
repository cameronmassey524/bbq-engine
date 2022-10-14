#pragma once
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <string>
#include <unordered_map>

#include "Types.h"

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

namespace bbq
{
    class ScriptManager
    {
        private:
            
        
        public:
            sol::state lua;
            std::unordered_map<string, sol::load_result> script_load_map;
            void Startup();
            void Shutdown();
            void Update();
            bool LoadScript( const string& name, const string& path);
            void RunScript(string name);
            void RunEntityScript(EntityID e);
    };
}