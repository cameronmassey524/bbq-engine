//#pragma once
#include "ScriptManager.h"
#include "Types.h"
#include "Engine.h"
#include <iostream>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

using namespace bbq;

extern Engine game;

void ScriptManager::Startup()
{
    lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table);

    //vec2
    lua.new_usertype<glm::vec2>("vec2",
        sol::constructors<glm::vec2(), glm::vec2(float), glm::vec2(float, float)>(),
        "x", &glm::vec2::x,
        "y", &glm::vec2::y,
        // optional and fancy: operator overloading. see: https://github.com/ThePhD/sol2/issues/547
        sol::meta_function::addition, sol::overload( [](const glm::vec2& v1, const glm::vec2& v2) -> glm::vec2 { return v1+v2; } ),
        sol::meta_function::subtraction, sol::overload( [](const glm::vec2& v1, const glm::vec2& v2) -> glm::vec2 { return v1-v2; } ),
        sol::meta_function::multiplication, sol::overload(
            [](const glm::vec2& v1, const glm::vec2& v2) -> glm::vec2 { return v1*v2; },
            [](const glm::vec2& v1, float f) -> glm::vec2 { return v1*f; },
            [](float f, const glm::vec2& v1) -> glm::vec2 { return f*v1; }
        )
    );
    
    //vec3
    lua.new_usertype<glm::vec3>("vec3",
        sol::constructors<glm::vec3(), glm::vec3(float), glm::vec3(float, float, float)>(),
        "x", &glm::vec3::x,
        "y", &glm::vec3::y,
        "z", &glm::vec3::z,
        // optional and fancy: operator overloading. see: https://github.com/ThePhD/sol2/issues/547
        sol::meta_function::addition, sol::overload( [](const glm::vec3& v1, const glm::vec3& v2) -> glm::vec3 { return v1+v2; } ),
        sol::meta_function::subtraction, sol::overload( [](const glm::vec3& v1, const glm::vec3& v2) -> glm::vec3 { return v1-v2; } ),
        sol::meta_function::multiplication, sol::overload(
            [](const glm::vec3& v1, const glm::vec3& v2) -> glm::vec3 { return v1*v2; },
            [](const glm::vec3& v1, float f) -> glm::vec3 { return v1*f; },
            [](float f, const glm::vec3& v1) -> glm::vec3 { return f*v1; }
        )
    );

    //Sprite
    lua.new_usertype<Sprite>("Sprite",
        sol::constructors<Sprite()>(),
        "image", &Sprite::image,
        "scale", &Sprite::scale,
        "position", &Sprite::position,
        "z", &Sprite::z
        );

    //Position
    lua.new_usertype<Position>("Position",
        sol::constructors<Position()>(),
        "x", &Position::x,
        "y", &Position::y
        );

    //Velocity
    lua.new_usertype<Velocity>("Velocity",
        sol::constructors<Velocity()>(),
        "x", &Velocity::x,
        "y", &Velocity::y
        );

    //Gravity
    lua.new_usertype<Gravity>("Gravity",
        sol::constructors<Gravity()>(),
        "meters_per_second", &Gravity::meters_per_second
        );

    //Health
    lua.new_usertype<Health>("Health",
        sol::constructors<Health()>(),
        "percent", &Health::percent
        );

    //Script
    lua.new_usertype<Script>("Script",
        sol::constructors<Script()>(),
        "name", &Script::name
        );
    
    lua.set_function( "KeyIsDown", [&]( const int keycode ) { return game.input.KeyIsPressed( keycode ); } );

    lua.set_function( "PlaySound", [&]( const string name ) { return game.sound.PlaySound( name ); } );
    lua.set_function( "LoadSound", [&]( const std::string& name, const std::string& path) { return game.sound.LoadSound( name, path ); } );

    lua.set_function( "CreateEntity", [&]( Position pos, Velocity vel, Gravity grav, Health health, Script sc, Sprite sp ) { return game.ecs.Create( pos, vel, grav, health, sc, sp ); } );
    lua.set_function( "DestroyEntity", [&]( const EntityID entity ) { return game.ecs.Destroy( entity ); } );

    //Old functions
    //lua.set_function( "GetSprite", [&]( const EntityID entity ) { return game.ecs.Get<Sprite>( entity ); } );
    //lua.set_function( "GetPosition", [&]( const EntityID entity ) { return game.ecs.Get<Position>( entity ); } );
    //lua.set_function( "GetVelocity", [&]( const EntityID entity ) { return game.ecs.Get<Velocity>( entity ); } );
    //lua.set_function( "GetGravity", [&]( const EntityID entity ) { return game.ecs.Get<Gravity>( entity ); } );
    //lua.set_function( "GetScript", [&]( const EntityID entity ) { return game.ecs.Get<Script>( entity ); } );
    //lua.set_function( "GetHealth", [&]( const EntityID entity ) { return game.ecs.Get<Health>( entity ); } );

    lua.set_function( "GetSprite", [&]( const EntityID e ) -> Sprite& { return game.ecs.Get<Sprite>(e); } );
    lua.set_function( "GetPosition", [&]( const EntityID e ) -> Position& { return game.ecs.Get<Position>(e); } );
    lua.set_function( "GetVelocity", [&]( const EntityID e ) -> Velocity& { return game.ecs.Get<Velocity>(e); } );
    lua.set_function( "GetGravity", [&]( const EntityID e ) -> Gravity& { return game.ecs.Get<Gravity>(e); } );
    lua.set_function( "GetScript", [&]( const EntityID e ) -> Script& { return game.ecs.Get<Script>(e); } );
    lua.set_function( "GetHealth", [&]( const EntityID e ) -> Health& { return game.ecs.Get<Health>(e); } );

    

    lua.set_function( "GetSpriteResource", [&]( const std::string name) { return game.resources.GetSprite( name ); } );
}

void ScriptManager::Shutdown()
{

}

void ScriptManager::Update()
{
    game.ecs.ForEach<Script>( [&]( EntityID e )
    {
        Script& s = game.ecs.Get<Script>(e);
        //game.scripting.RunScript(e);
        script_load_map[s.name](e);
    } );
}

bool ScriptManager::LoadScript( const string& name, const string& path)
{
    string fullpath = path + name;
    //sol::load_result script = lua.load_file(fullpath);
    script_load_map[name] = lua.load_file(fullpath);
    
    
    auto f = lua.load_file(fullpath);

    // if( !f.valid() ) {
    //     std::cerr << "Failed to load script: " << sol::error(f).what() << std::endl;
    //     return false;
	// }

	if (!f.valid()) {
		sol::error err = f;
		std::cerr << "failed to load string-based script into the program" << err.what() << std::endl;
	}

    return true; //default for now
}

void ScriptManager::RunScript(string name, string args[])
{
    //std::cout << "RunscriptEnteredNotice\n";
    script_load_map[name]();
}

void ScriptManager::RunEntityScript(EntityID e)
{
    //script_load_map[name]();
}