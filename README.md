# bbq Game Engine

A 2D game engine including graphics, sound, lua scripting, and respective resources.

## Platform setup

Built with xmake and compiled with MSVC compiler

## What is the Engine?

The `Engine` class is actually quite small and simple. It stores all the managers. All the managers get a reference to the engine so they can access each other. `Engine::Startup()` calls `Startup()` on the managers in the right order. `Engine::Shutdown()` does the same. `Engine` also runs the game loop.

## Managers

SoundManager: Uses SoLoud to manage and play audio resources. <br /><br />
GraphicsManager: Sets up GLFW to open windows and use sokol_gfx's OpenGL Backend. Loads and draws images. <br /><br />
InputManager: Uses GLFW To get keyboard input from the player. <br /><br />
EntityManager: Entity Component System which efficiently manages each objects position, velocity, gravity, health, sprite, scripts, and collider. <br /><br />
CollisionManager: Detects simple 2D box collision between entities with box collider components. <br /><br />
ResourceManager: Currently stores standalone sprites which are not attached to any game object. <br /><br />
ScriptManager: Uses sol to expose C++ Engine functionalities to Lua, allowing users to operate the engine from Lua. Also Loads and run scripts and entity script components. <br />

## Technology Used

xmake:  https://xmake.io/#/ <br />
sokol:  https://github.com/floooh/sokol <br />
GLFW:   https://www.glfw.org <br />
SoLoud: https://solhsa.com/soloud/ <br />
sol:    https://github.com/ThePhD/sol2 <br />
