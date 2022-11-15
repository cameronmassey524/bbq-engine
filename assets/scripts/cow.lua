local entity = ...

if (KeyIsDown(68))
then
    --right
    GetPosition(entity).x = GetPosition(entity).x + 2.5
end
if (KeyIsDown(65))
then
    --left
    GetPosition(entity).x = GetPosition(entity).x - 2.5
end
if (KeyIsDown(87))
then
    --up
    GetPosition(entity).y = GetPosition(entity).y + 2.5
end
if (KeyIsDown(83))
then
    --down
    GetPosition(entity).y = GetPosition(entity).y - 2.5
end