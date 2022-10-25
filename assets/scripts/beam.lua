local entity = ...

--print("beam spawned")

if (KeyIsDown(262)) then
    --right
    GetPosition(entity).x = GetPosition(entity).x + 2.5
elseif (KeyIsDown(263)) then
    --left
    GetPosition(entity).x = GetPosition(entity).x - 2.5
else
    --do nothing
end

if (KeyIsDown(32)) then
    GetSprite(entity).scale = 50;
else
    GetSprite(entity).scale = 0;
end

--DestroyEntity(entity)