local entity = ...

--Eventually update this to work on entity position, not sprite position.
--For this, go to the draw function and make it so that it accounts for entity position as well.
--(Currently entity position doesnt affect sprite position, or really do anything)
GetSprite(entity).position.x = GetSprite(entity).position.x - 5.0;
--print(GetSprite(entity).position.x)

--destroy sprite if scrolls far away from 0
if (GetSprite(entity).position.x > 300) --aribitrary 1000
then
    DestroyEntity(entity)
else
    --nothing?
end
