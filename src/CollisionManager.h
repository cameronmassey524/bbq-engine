#pragma once

#include "Types.h"

namespace bbq
{
    class CollisionManager
    {
        private:
            int funnyTimer;
        
        public:
            void Startup();
            void Shutdown();
            void Update();
            
            
            bool BoxCollide(EntityID e1, EntityID e2); //Check if they collide using position
            //For pixel perfect, we will check for box collisions, then use mask to check for collision.
            //masks will be made from the sprites.
            //Then masks can be shifted and "anded" and if the result of this is 0, nothing collided.
    };
}