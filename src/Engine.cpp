#include "Engine.h"
//#include "GraphicsManager.h"
//#include "SoundManager.h"
//#include "ResourceManager.h"
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
    ecs.Startup();
    graphics.Startup();
    input.Startup();
    sound.Startup();
    resources.Startup();
    scripting.Startup();
    collisions.Startup();

}

void Engine::Shutdown()
{
    ecs.Shutdown();
    graphics.Shutdown();
    input.Shutdown();
    sound.Shutdown();
    resources.Shutdown();
    scripting.Shutdown();
    collisions.Shutdown();
}

void Engine::preciseSleep(double seconds) {
    //NOTE: THIS IS NOT MY CODE. IT IS FROM:
    //https://blat-blatnik.github.io/computerBear/making-accurate-sleep-function/
    //This is preferable to using std::this_thread::sleep_for because that calls
    //the windows sleep function which SUCKS for doing this game loop timing.
    //This implementation is cross platform and much more precise.

    using namespace std;
    using namespace std::chrono;

    static double estimate = 5e-3;
    static double mean = 5e-3;
    static double m2 = 0;
    static int64_t count = 1;

    while (seconds > estimate) {
        auto start = high_resolution_clock::now();
        this_thread::sleep_for(milliseconds(1));
        auto end = high_resolution_clock::now();

        double observed = (end - start).count() / 1e9;
        seconds -= observed;

        ++count;
        double delta = observed - mean;
        mean += delta / count;
        m2   += delta * (observed - mean);
        double stddev = sqrt(m2 / (count - 1));
        estimate = mean + stddev;
    }

    // spin lock
    auto start = high_resolution_clock::now();
    while ((high_resolution_clock::now() - start).count() / 1e9 < seconds);
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
        double start_time = glfwGetTime();

        //game loop stuff
        input.Update();
        callback(*this);
        scripting.Update();//run script on each sprite
        collisions.Update();//check all collidable entities for collision
        graphics.Draw();


        // //print every 1 second
        // sixtieths+=1;
        // //do game loop stuff
        // if (sixtieths>=60)
        // {
        //     sixtieths = 0;
        //     seconds_passed +=1;
        //     if (seconds_passed == 1)
        //     {
        //         std::cout << seconds_passed;
        //         seconds_passed = 0;
        //     }
        // }
        
        //manage timestep 

        double end_time = glfwGetTime();
        //double time_diff = end_time-start_time;

        //const auto timestep = std::chrono::duration<real>( ((1.0/60.0) - (end_time-start_time)) );
        //const auto timestep = std::chrono::duration<real>( ((1.0/60.0) - (last_length - (1.0/60.0))) );
        //const auto timestep = std::chrono::duration<real>( 1.0/60.0 );
        //const auto timestep = std::chrono::duration<real>( 1.0/120.0 );
        
        
        
        //std::this_thread::sleep_for(timestep);
        preciseSleep((1.0/60.0)-(end_time - start_time));

        //last_length = glfwGetTime() - start_time;

        //std::cout << ((1.0/60.0) - (end_time-start_time) - (last_length - (1./60.)));
        //std::cout << last_length;
        //std::cout << "\n";
    }
    //std::cout << "Loop exited after 10 seconds\n";
}