#include <iostream>
#include "Engine.h"
#include "GraphicsManager.h"
//#include "Types.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

using namespace bbq;

Engine game; //global engine

std::vector< Sprite > sprites; //global sprites for now

void test_callback(Engine& e)
{
    //std::cout << "Hello World! Press space to receive a message.\n";
    
    if (game.graphics.ShouldQuit())
    {
        exit(0);
    }
    
    if (game.input.KeyIsPressed(GLFW_KEY_SPACE))
    {
        std::cout << "Space is pressed. \n";
        game.sound.PlaySound();
        //game.graphics.Draw();
        
        //make entity with sprite "rangercat.png"
        Position myPos;
        //myPos.x=0;
        //myPos.y=0;
        Velocity myVel;
        //myVel.x=0;
        //myVel.y=0;
        Gravity myGrav;
        //myGrav.meters_per_second = 0;
        Health myHealth;
        //myHealth.percent = 100;
        Script myScript;
        //myScript.name = "none(placeholder)";
        Sprite mySprite = sprites[0];
        mySprite.scale = 1 + std::rand() % 100;
        //done making entity components. (currently all required)
        
        game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);
        

    }
}

int main( int argc, const char* argv[] ) {
    //std::cout << "Hello, World!\n";
    std::cout << "Hello World!\nPress space to play a sound and show a cool image.\nPress the X in the graphics window to quit.\n";

    // Engine game;
    game.Startup();
    game.sound.LoadSound("hitsound.wav","assets/sounds/");
    
    game.graphics.LoadAnImage("rangercat.png", "assets/sprites/");


    game.RunGameLoop(test_callback);

    return 0;
}