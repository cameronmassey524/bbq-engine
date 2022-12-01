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
            ChangeSprite(entity, "rangercat.png")
            PlaySound("vine.wav")
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
            PlaySound("vine.wav")
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


--[[
switch (state_)
  {
    case STATE_STANDING:
      if (input == PRESS_B)
      {
        state_ = STATE_JUMPING;
        yVelocity_ = JUMP_VELOCITY;
        setGraphics(IMAGE_JUMP);
      }
      else if (input == PRESS_DOWN)
      {
        state_ = STATE_DUCKING;
        setGraphics(IMAGE_DUCK);
      }
      break;

    case STATE_JUMPING:
      if (input == PRESS_DOWN)
      {
        state_ = STATE_DIVING;
        setGraphics(IMAGE_DIVE);
      }
      break;

    case STATE_DUCKING:
      if (input == RELEASE_DOWN)
      {
        state_ = STATE_STANDING;
        setGraphics(IMAGE_STAND);
      }
      break;
  }
--]]

