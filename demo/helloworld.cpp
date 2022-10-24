#include <iostream>
#include "Engine.h"
#include "GraphicsManager.h"
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

        game.scripting.RunScript("spacebar_script.lua");
        

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


    //make entity with sprite "rangercat.png"
    Position myPos;
    Velocity myVel;
    Gravity myGrav;
    Health myHealth;
    Script myScript;
    //myScript.name = "scroll_x.lua";
    myScript.name = "shrink_sprite.lua";
    Sprite mySprite = game.resources.GetSprite("rangercat.png"); // mySprite becomes a copy of the sprite at location
    mySprite.scale = 1 + std::rand() % 100;
    //done making entity components. (currently all required)
    EntityID myEntity = game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);

    //game.ecs.Get<Sprite>(myEntity).position.x = 50;


    game.RunGameLoop(test_callback);

    return 0;
}