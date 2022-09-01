#include <iostream>
#include "Engine.h"
#include "GraphicsManager.h"

using namespace bbq;

int main( int argc, const char* argv[] ) {
    std::cout << "Hello, World!\n";

    Engine game;
    game.Startup();
    game.RunGameLoop();

    return 0;
}