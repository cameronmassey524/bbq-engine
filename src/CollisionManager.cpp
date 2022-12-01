#pragma once
#include "CollisionManager.h"
#include "EntityManager.h"
#include "Engine.h"
#include <cmath>

using namespace bbq;
extern Engine game;

void CollisionManager::Startup()
{
    //does nothing right now
}

void CollisionManager::Shutdown()
{
    //does nothing right now
}

void CollisionManager::Update()
{
    game.ecs.ForEach<Collider>( [&]( EntityID e1 )
    {

        game.ecs.ForEach<Collider>( [&]( EntityID e2 )
        {
            if (e1!=e2)
            {
                BoxCollide(e1,e2);
            }
        } );
        
    } );
    
    //For now, just check 
}

bool CollisionManager::BoxCollide(EntityID e1, EntityID e2)
{
    //check horizontal first (more likely to happen in our game)

    if (std::abs(game.ecs.Get<Position>(e1).x - game.ecs.Get<Position>(e2).x) <= (game.ecs.Get<Collider>(e1).x + game.ecs.Get<Collider>(e2).x))
    {
        //horiztonal overlap,, could collide
        //check if vertical collide (collision would be true)
        if (std::abs(game.ecs.Get<Position>(e1).y - game.ecs.Get<Position>(e2).y) <= (game.ecs.Get<Collider>(e1).y + game.ecs.Get<Collider>(e2).y))
        {
            //vertical overlap also, collision is true

            std::cout << "A collision was detected\n";
            return true;
        }
        //else no collision, continue
    }
    //else no collision
    
    return false;



}