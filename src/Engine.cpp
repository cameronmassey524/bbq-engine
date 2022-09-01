#include "Engine.h"
#include "GraphicsManager.h"
#include "Types.h"
#include <thread>
#include <chrono>
#include <iostream>

#include "GLFW/glfw3.h"


using namespace bbq;


GraphicsManager graphics;

void Engine::Startup()
{
    graphics.Startup();
}

void Engine::Shutdown()
{
    graphics.Shutdown();
}

void Engine::RunGameLoop()
{
    //auto start_time = std::chrono::steady_clock::now();
    
    //int seconds_passed = 0;
    //int sixtieths = 0;
    
    while (true)
    //while (sixtieths<600)
    {
        double start_time = glfwGetTime();
        //sixtieths+=1;
        //do game loop stuff
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
        
        // std::chrono::steady_clock::duration time_span = std::chrono::steady_clock::now() - start_time;
        
        //double n_seconds = double(time_span.count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;

        double end_time = glfwGetTime();
        double time_diff = end_time-start_time;
        //std::cout << (1.0/60.0) - time_diff; 
        //std::cout << "\n";
        const auto timestep = std::chrono::duration<real>( (1.0/60.0) - time_diff);
        
        
        
        std::this_thread::sleep_for(timestep);
        //std::cout << time_diff = "\n";
        
        


    }
    //std::cout << "Loop exited after 10 seconds\n";
}