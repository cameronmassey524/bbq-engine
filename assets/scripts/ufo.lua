local entity = ...

if (KeyIsDown(262)) then
    --right
    GetPosition(entity).x = GetPosition(entity).x + 2.5
elseif (KeyIsDown(263)) then
    --left
    GetPosition(entity).x = GetPosition(entity).x - 2.5
else
        --do nothing?
end

if (KeyIsDown(32)) then
    PlaySound("hitsound.wav")
    -- beamPos = Position.new()
    -- beamPos.x = GetPosition(entity).x
    -- beamPos.y = GetPosition(entity).y - 50
    -- beamVel = Velocity.new()
    -- beamGrav=Gravity.new()
    -- beamHealth = Health.new()
    -- beamScript = Script.new()
    -- beamScript.name = "beam.lua";
    -- beamSprite = GetSpriteResource("beam.png")
    -- beamSprite.scale = 50
    -- beamSprite.z = 1.0
    -- beam_entity = CreateEntity(beamPos, beamVel, beamGrav, beamHealth, beamScript, beamSprite)
else
    --do nothing
end


