--std::cout << "Space is pressed. \n";
if (KeyIsDown(32)) --glfw space keycode
then
    PlaySound("hitsound.wav")
    myPos = Position.new()
    myVel = Velocity.new()
    myGrav=Gravity.new()
    myHealth = Health.new()
    myScript = Script.new()
    myScript.name = "scroll_x.lua";
    --myScript.name = "shrink_sprite.lua";
    randInt = math.random(1,4)
    if (randInt==1) then
        randSprite = GetSpriteResource("cow.png")
        --print("1")
    elseif (randInt==2) then
        randSprite = GetSpriteResource("beam.png")
        --print("2")
    elseif (randInt==3) then
        randSprite = GetSpriteResource("ufo.png")
        --print("3")
    else
        randSprite = GetSpriteResource("rangercat.png") 
        --print("4")
    end
    mySprite = randSprite
    mySprite.scale = math.random(1,100)
    entity = CreateEntity(myPos, myVel, myGrav, myHealth, myScript, mySprite)
else
    --do nothing?
end

