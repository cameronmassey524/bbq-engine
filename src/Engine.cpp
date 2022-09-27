#include "Engine.h"
#include "GraphicsManager.h"
#include "SoundManager.h"
#include "ResourceManager.h"
#include "Types.h"
#include <thread>
#include <chrono>
#include <iostream>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"


using namespace bbq;


//GraphicsManager graphics;
//InputManager input;

void Engine::Startup()
{
    //graphics = GraphicsManager();
    graphics.Startup();
    input.Startup();
    sound.Startup();
}

void Engine::Shutdown()
{
    graphics.Shutdown();
    input.Shutdown();
    sound.Shutdown();
}

void Engine::RunGameLoop(const UpdateCallback& callback)
{
    //auto start_time = std::chrono::steady_clock::now();
    
    //int seconds_passed = 0;
    //int sixtieths = 0;
    //double last_length = 0.0;
    
    while (true)
    //while (sixtieths<600)
    {
        //double start_time = glfwGetTime();

        input.Update();
        callback(*this);

        //graphics.Draw() (pseudo)


        // sixtieths+=1;
        // //do game loop stuff
        // if (sixtieths>=60)
        // {
        //     sixtieths = 0;
        //     seconds_passed +=1;
        //     if (seconds_passed == 10)
        //     {
        //         std::cout << seconds_passed;
        //         seconds_passed = 0;
        //     }

                
        // }
        
        //manage timestep 

        //double end_time = glfwGetTime();
        //double time_diff = end_time-start_time;

        //const auto timestep = std::chrono::duration<real>( ((1.0/60.0) - (end_time-start_time)) );
        //const auto timestep = std::chrono::duration<real>( ((1.0/60.0) - (last_length - (1.0/60.0))) );
        const auto timestep = std::chrono::duration<real>( 1.0/60.0 );
        
        
        
        std::this_thread::sleep_for(timestep);

        //last_length = glfwGetTime() - start_time;

        //std::cout << ((1.0/60.0) - (end_time-start_time) - (last_length - (1./60.)));
        //std::cout << last_length;
        //std::cout << "\n";
    }
    //std::cout << "Loop exited after 10 seconds\n";
}