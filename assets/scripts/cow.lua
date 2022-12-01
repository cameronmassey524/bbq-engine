local entity = ...
space = false

if (KeyIsDown(262))
then
    --right
    GetPosition(entity).x = GetPosition(entity).x + 2.5
end
if (KeyIsDown(263))
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
if (KeyIsDown(32)) then
    --space
    space = false
end
 