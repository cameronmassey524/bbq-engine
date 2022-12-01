local entity = ...
t = 25
move = 1

if (KeyIsDown(262)) then
    --right
    GetState(entity).cur = "right"
    if (GetState(entity).timer < t) then
        GetState(entity).timer = t
    end
elseif (KeyIsDown(263)) then
    --left
    GetState(entity).cur = "left"
    if (GetState(entity).timer < t) then
        GetState(entity).timer = t
    end
else
    --do nothing
    GetState(entity).cur = "idle"
end

curr = GetState(entity).cur

if (curr == "right") then
    --right
    GetPosition(entity).x = GetPosition(entity).x + move
    
    if (GetState(entity).timer < 50) then
        if (KeyIsDown(46)) then --period
            ChangeSprite(entity, "enemy_block.png")
            --print("Play Sound: bruh.wav")
            PlaySound("bruh.wav")
            GetState(entity).timer = 120
        else
            ChangeSprite(entity, "towerRight.png")
        end
    end

elseif (curr == "left") then
    --left
    GetPosition(entity).x = GetPosition(entity).x - move

    if (GetState(entity).timer < 50) then
        if (KeyIsDown(44)) then --comma
            ChangeSprite(entity, "ufo.png")
            --print("Play Sound: bruh.wav")
            PlaySound("bruh.wav")
            GetState(entity).timer = 120
        else
            ChangeSprite(entity, "towerLeft.png")
        end
    end

else
    --do nothing
    if (GetState(entity).timer < 0 and GetSprite(entity).name ~= "tower.png") then
        ChangeSprite(entity, "tower.png")
    end
end

if (GetState(entity).timer > -1) then
    GetState(entity).timer = GetState(entity).timer - 1
end