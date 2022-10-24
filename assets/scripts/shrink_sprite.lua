local entity = ...

GetSprite(entity).scale = GetSprite(entity).scale - 5.0;

if ((GetSprite(entity).scale) <= 0)
then
    DestroyEntity(entity)
else
    --nothing here
end