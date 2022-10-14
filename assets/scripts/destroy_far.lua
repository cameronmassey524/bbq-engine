local entity = ...

--Eventually update this to work on entity position, not sprite position.
--For this, go to the draw function and make it so that it accounts for entity position as well.
--(Currently entity position doesnt affect sprite position, or really do anything)

if (GetSprite(entity).position.x > 1000) --aribitrary 1000
then
    DestroyEntity(entity)
else
    --nothing?
end
