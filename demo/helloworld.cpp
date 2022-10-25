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


    //make entity with sprite "ufo.png"
    Position myPos;
    myPos.y = 50;
    myPos.x = 0;
    Velocity myVel;
    Gravity myGrav;
    Health myHealth;
    Script myScript;
    //myScript.name = "scroll_x.lua";
    //myScript.name = "shrink_sprite.lua";
    myScript.name = "ufo.lua";
    Sprite mySprite = game.resources.GetSprite("ufo.png"); // mySprite becomes a copy of the sprite at location
    //mySprite.scale = 1 + std::rand() % 100;
    mySprite.scale = 10;
    mySprite.z = 0.1;

    EntityID myEntity = game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);


    //make entity with sprite "ufo.png"
    Position beamPos;
    beamPos.y = 0;
    beamPos.x = 0;
    Velocity beamVel;
    Gravity beamGrav;
    Health beamHealth;
    Script beamScript;
    //myScript.name = "scroll_x.lua";
    //myScript.name = "shrink_sprite.lua";
    beamScript.name = "beam.lua";
    Sprite beamSprite = game.resources.GetSprite("beam.png"); // mySprite becomes a copy of the sprite at location
    beamSprite.scale = 0;
    beamSprite.z = 0.1;

    //done making entity components. (currently all required)
    EntityID beamEntity = game.ecs.Create(beamPos, beamVel, beamGrav, beamHealth, beamScript, beamSprite);
    

    //game.ecs.Get<Sprite>(myEntity).position.x = 50;


    game.RunGameLoop(test_callback);

    return 0;
}