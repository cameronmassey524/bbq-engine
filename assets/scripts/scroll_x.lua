local entity = ...

--Eventually update this to work on entity position, not sprite position.
--For this, go to the draw function and make it so that it accounts for entity position as well.
--(Currently entity position doesnt affect sprite position, or really do anything)
--print(GetSprite(entity).position.x)
GetPosition(entity).x = GetPosition(entity).x + 5
--destroy sprite if scrolls far away from 0
if (GetPosition(entity).x > 100) --aribitrary 1000
then
    DestroyEntity(entity)
else
    --nothing?
end
