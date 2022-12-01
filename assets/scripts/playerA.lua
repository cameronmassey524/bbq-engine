local entity = ...


if (KeyIsDown(262)) then
    --right
    GetState(entity).cur = "right"
elseif (KeyIsDown(263)) then
    --left
    GetState(entity).cur = "left"
else
    --do nothing
    GetState(entity).cur = "idle"
end

curr = GetState(entity).cur

if (curr == "right") then
    --right
    GetPosition(entity).x = GetPosition(entity).x + 2.5
elseif (curr == "left") then
    --left
    GetPosition(entity).x = GetPosition(entity).x - 2.5
else
    --do nothing
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

