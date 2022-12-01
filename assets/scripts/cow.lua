local entity = ...
space = false

if (KeyIsDown(68))
then
    --right (d)
    GetPosition(entity).x = GetPosition(entity).x + 2.5
elseif (KeyIsDown(65))
then
    --left (a)
    GetPosition(entity).x = GetPosition(entity).x - 2.5
end
if (KeyIsDown(87))
then
    --up (w)
    GetPosition(entity).y = GetPosition(entity).y + 2.5
end
if (KeyIsDown(83))
then
    --down (s)
    GetPosition(entity).y = GetPosition(entity).y - 2.5
end
if (KeyIsDown(32)) then
    --space
    space = false
end
 