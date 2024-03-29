#include <iostream>
#include "Engine.h"
#include "GraphicsManager.h"
#include <string>
//#include "Types.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

using namespace bbq;

Engine game; //global engine

//std::vector< Sprite > sprites; //global sprites for now

void test_callback(Engine& e)
{
    //std::cout << "Hello World! Press space to receive a message.\n";
    
    if (game.graphics.ShouldQuit())
    {
        exit(0);
    }
    
    if (game.input.KeyIsPressed(GLFW_KEY_SPACE))
    {
        // std::cout << "Space is pressed. \n";
        // //game.sound.PlaySound("hitsound.wav");
        // game.scripting.RunScript("test_script.lua");
        // //make entity with sprite "rangercat.png"
        // Position myPos;
        // Velocity myVel;
        // Gravity myGrav;
        // Health myHealth;
        // Script myScript;
        // Sprite mySprite = game.resources.GetSprite("rangercat.png"); // mySprite becomes a copy of the sprite at location
        // mySprite.scale = 1 + std::rand() % 100;
        // //done making entity components. (currently all required)
        // game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);

        //string args[1] = {"placeholder"};
        //game.scripting.RunScript("spacebar_script.lua", args);
        

    }
}

int main( int argc, const char* argv[] ) {
    //std::cout << "Hello, World!\n";
    std::cout << "Hello World!\nPress space to play a sound and show a cool image.\nPress the X in the graphics window to quit.\n";

    // Engine game;
    game.Startup();
    game.sound.LoadSound("hitsound.wav","assets/sounds/");
    
    game.graphics.LoadAnImage("rangercat.png", "assets/sprites/");
    game.graphics.LoadAnImage("cow.png", "assets/sprites/");
    game.graphics.LoadAnImage("beam.png", "assets/sprites/");
    game.graphics.LoadAnImage("ufo.png", "assets/sprites/");

    game.scripting.LoadScript("test_script.lua", "assets/scripts/");
    game.scripting.LoadScript("spacebar_script.lua", "assets/scripts/");
    game.scripting.LoadScript("scroll_x.lua", "assets/scripts/");
    game.scripting.LoadScript("shrink_sprite.lua", "assets/scripts/");
    game.scripting.LoadScript("ufo.lua","assets/scripts/");
    game.scripting.LoadScript("beam.lua","assets/scripts/"); //not loading?
    game.scripting.LoadScript("cow.lua","assets/scripts/"); //not loading?


    //EntityID myEntity = game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);
    EntityID ufoEntity = game.ecs.Create();
    game.ecs.Get<Position>(ufoEntity).y = 50;
    game.ecs.Get<Position>(ufoEntity).x = 0;
    game.ecs.Get<Script>(ufoEntity).name = "ufo.lua";
    game.ecs.Get<Sprite>(ufoEntity) = game.resources.GetSprite("ufo.png");
    game.ecs.Get<Sprite>(ufoEntity).scale = 10;
    game.ecs.Get<Sprite>(ufoEntity).z = 0.1;
    
    Collider ufoCol;
    ufoCol.x=10;
    ufoCol.y=10;
    game.ecs.SetComponent<Collider>(ufoEntity, ufoCol);
    

    EntityID beamEntity = game.ecs.Create();
    game.ecs.Get<Position>(beamEntity).y = 0;
    game.ecs.Get<Position>(beamEntity).x = 0;
    game.ecs.Get<Script>(beamEntity).name = "beam.lua";
    game.ecs.Get<Sprite>(beamEntity) = game.resources.GetSprite("beam.png");
    game.ecs.Get<Sprite>(beamEntity).scale = 0;
    game.ecs.Get<Sprite>(beamEntity).z = 0.9;

    Collider beamCol;
    beamCol.x=0;
    beamCol.y=0;  
    //game.ecs.SetComponent<Collider>(beamEntity, beamCol);

    //start with "no" collider for now. later will want a tag maybe? or negative huge numbers for colliders. (for colllision toggling?)

    EntityID cowEntity = game.ecs.Create();
    game.ecs.Get<Position>(cowEntity).y = 0;
    game.ecs.Get<Position>(cowEntity).x = 0;
    game.ecs.Get<Script>(cowEntity).name = "cow.lua";
    game.ecs.Get<Sprite>(cowEntity) = game.resources.GetSprite("cow.png");
    game.ecs.Get<Sprite>(cowEntity).scale = 10;
    game.ecs.Get<Sprite>(cowEntity).z = 0.5;

    //game.ecs.Get<Sprite>(myEntity).position.x = 50;

    Collider cowCol;
    cowCol.x=10;
    cowCol.y=10;
    game.ecs.SetComponent<Collider>(cowEntity, cowCol);


    game.RunGameLoop(test_callback);

    return 0;
}