# bbq Game Engine

A 2D game engine including graphics, sound, lua scripting, and respective resources.

## Platform setup

Built with xmake and compiled with MSVC compiler

## What is the Engine?

The `Engine` class is actually quite small and simple. Data-wise, it stores all the managers. All the managers get a reference to the engine so they can access each other. It takes some basic parameters as input (size of the window, whether to go full-screen, etc.). `Engine::Startup()` calls `Startup()` on the managers in the right order. `Engine::Shutdown()` does the same. `Engine` also runs the game loop.

## Technology Used

xmake:  https://xmake.io/#/
sokol:  https://github.com/floooh/sokol
GLFW:   https://www.glfw.org
SoLoud: https://solhsa.com/soloud/
sol:    https://github.com/ThePhD/sol2
