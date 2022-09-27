#include <iostream>
#include "Engine.h"
#include "GraphicsManager.h"

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
        game.graphics.Draw(sprites);
    }
}

int main( int argc, const char* argv[] ) {
    //std::cout << "Hello, World!\n";
    std::cout << "Hello World!\nPress space to play a sound.\nPress the X in the graphics window to quit.\n";

    // Engine game;
    game.Startup();
    game.sound.LoadSound("hitsound.wav","assets/sounds/");
    
    game.graphics.LoadAnImage("rangercat.png", "assets/sprites/");


    game.RunGameLoop(test_callback);

    return 0;
}