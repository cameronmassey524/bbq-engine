--std::cout << "Space is pressed. \n";
if (KeyIsDown(32)) --glfw space keycode
then
    PlaySound("hitsound.wav")
    --make entity with sprite "rangercat.png"
    myPos = Position.new()
    --myPos.x=0;
    --myPos.y=0;
    myVel = Velocity.new()
    --myVel.x=0;
    --myVel.y=0;
    myGrav=Gravity.new()
    --myGrav.meters_per_second = 0;
    myHealth = Health.new()
    --myHealth.percent = 100;
    myScript = Script.new()
    --myScript.name = "scroll_x.lua";
    myScript.name = "shrink_sprite.lua";
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
    --mySprite = GetSpriteResource("rangercat.png")
    mySprite = randSprite
    --mySprite.scale = 1 + std::rand() % 100
    mySprite.scale = math.random(1,100)
    --mySprite.scale = 10
    --done making entity components. (currently all required)

    --game.ecs.Create(myPos, myVel, myGrav, myHealth, myScript, mySprite);
    entity = CreateEntity(myPos, myVel, myGrav, myHealth, myScript, mySprite)
else
    --do nothing?
end

