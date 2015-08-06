#include "Chapter2.h"

#include "Chapter2Level1.h"

USING_NS_CC;

Scene* Chapter2::createScene()
{
	
	auto scene = Scene::create();
	 

	if (scene != nullptr)
	{
		auto layer = Chapter2::create();
		scene->addChild(layer);
	}
	return scene;
}

bool Chapter2::init()
{
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // some upfront items that we need
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    Size playingSize = Size(visibleSize.width, visibleSize.height - (visibleSize.height/8)); // actual playing size to work with
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a scene for our game to hold everything
    // 'scene' is an autorelease object
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create the title dialog
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto color = Color4F(1.0f, 0.5f, 0.3f, 1);
    
    int verts = 4;
    
    Vec2 stripe1[] = {
        Vec2::ZERO,
        Vec2(0,200),
        Vec2(600,200),
        Vec2(600,0)
    };
    
    DrawNode* dotNode1 = DrawNode::create();
    dotNode1->setContentSize(Size(600, 200));
    dotNode1->drawPolygon(stripe1, verts, color, 0, color);
    
    dotNode1->setPosition(Vec2(visibleSize.width/2 - (dotNode1->getContentSize().width / 2),
                               playingSize.height - dotNode1->getContentSize().height));
    
    auto label = Label::createWithTTF("Super Cocos Aliens", "fonts/Marker Felt.ttf", 64);
    dotNode1->addChild(label, 1);
    auto dotNodeSize = dotNode1->getContentSize();
    label->setPosition(Vec2(dotNodeSize.width/2, dotNodeSize.height/2));

   // scene->addChild(dotNode1, -1);

    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold all labels
    // create the player and score labels
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int paddingX = 20;
    int paddingY = 20;
    
    auto labelNode = Node::create();
    
    auto player1 = Label::createWithTTF("Player 1", "fonts/Marker Felt.ttf", 32);
    auto player2 = Label::createWithTTF("Player 2", "fonts/Marker Felt.ttf", 32);
    
    auto player1Score = Label::createWithTTF("00000", "fonts/Marker Felt.ttf", 32);
    auto player2Score = Label::createWithTTF("00000", "fonts/Marker Felt.ttf", 32);
    
    labelNode->addChild(player1, 0);
    labelNode->addChild(player2, 0);
    labelNode->addChild(player1Score, 0);
    labelNode->addChild(player2Score, 0);

    auto player1Size = player1->getContentSize();
    auto player1ScoreSize = player1Score->getContentSize();
    auto player2Size = player2->getContentSize();
    auto player2ScoreSize = player2Score->getContentSize();

    player1->setPosition(Vec2(0 + player1Size.width / 2 + paddingX,
                              visibleSize.height - player1Size.height / 2 - paddingY));
    
    player1Score->setPosition(Vec2(0 + player1->getPositionX() + player1ScoreSize.width + paddingX,
                                   visibleSize.height - player1ScoreSize.height / 2 - paddingY));
    
    player2Score->setPosition(Vec2(visibleSize.width - player2ScoreSize.width / 2 - paddingX,
                                   visibleSize.height - player2ScoreSize.height / 2 - paddingY));

    player2->setPosition(Vec2(player2Score->getPositionX() - player2Size.width - paddingX,
                              visibleSize.height - player2Size.height / 2 - paddingY));

    this->addChild(labelNode, -1);
    
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold non-sprites.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto nodeItems = Node::create();
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a path/walkway
    // depending upon how large the screen is we need to decide how many blocks to lay down.
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto testSprite = Sprite::create("ZigzagForest_Square.png");
    auto spriteSize = testSprite->getContentSize();
    
    int howMany = std::ceil(visibleSize.width / spriteSize.width);
    
    int sX = 0; // act as a counter for setPosition x coordinate.
    int sY = 0; // act as a counter for setPosition y coordinate.
    
    playingSize = Size(visibleSize.width, visibleSize.height - spriteSize.height);
    
    for (int i=0; i < howMany; i++)
    {
        auto sprite = Sprite::create("ZigzagForest_Square.png");
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        nodeItems->addChild(sprite, 0);
    }
    
    testSprite = NULL;
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create the blocks
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    testSprite = Sprite::create("ZigzagGrass_Mud_Round.png");
    
    sX = visibleSize.width/2 - testSprite->getContentSize().width;
    sY = playingSize.height/2 - testSprite->getContentSize().height * 2;
    
    for (int i=0; i < 5; i++)
    {
        auto sprite = Sprite::create("ZigzagGrass_Mud_Round.png");
        sprite->setAnchorPoint(Vec2::ZERO);
        sprite->setPosition(sX,sY);
        
        sX += sprite->getContentSize().width;
        
        nodeItems->addChild(sprite, 0);
    }
    
    testSprite = NULL;

    this->addChild(nodeItems, 1);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold all sprites
    // create  a few sprites
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto spriteNode = Node::create();
    
    auto sprite1 = Sprite::create("Blue_Front1.png");
    sprite1->setAnchorPoint(Vec2(0,0));
    sprite1->setPosition(100, (visibleSize.height - playingSize.height));
    spriteNode->addChild(sprite1, 1);
    
    auto sprite2 = Sprite::create("LightBlue_Front1.png");
    sprite2->setAnchorPoint(Vec2(0,0));
    sprite2->setPosition(500, (visibleSize.height - playingSize.height));
    spriteNode->addChild(sprite2, 1);
    
    auto sprite3 = Sprite::create("White_Front1.png");
    sprite3->setAnchorPoint(Vec2(0,0));
    sprite3->setPosition(800, (visibleSize.height - playingSize.height));
    spriteNode->addChild(sprite3, 1);
    
    this->addChild(spriteNode, 1);
    
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // create a node to hold menu
    // create a menu
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    auto menuNode = Node::create();
    
    auto menuItem1 = MenuItemFont::create("Start Game");
    menuItem1->setFontNameObj("fonts/Marker Felt.ttf");
    menuItem1->setFontSizeObj(64);
    
    menuItem1->setCallback([&](Ref *sender) {
      // Director::getInstance()->replaceScene(Chapter2Level1::createScene());
		//TransitionFadeBL
		//TransitionFadeTR
		//TransitionFlipX::create()
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, Chapter2Level1::createScene(), TransitionScene::Orientation::LEFT_OVER/*, Color3B(0, 255, 255)*/));
		
    });
    
    auto menu = Menu::create(menuItem1, NULL);
    menuNode->addChild(menu, 0);
    
    this->addChild(menuNode, 2);


	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("animations/grossini-aliases.plist", "animations/grossini-aliases.png");


	auto sprite = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	sprite->setPosition(Vec2(visibleSize.width * 0.35f, 128) );//visibleSize.height * 0.5f));
	addChild(sprite);

	Vector<SpriteFrame*> aminFrames1(15);
	char szSpFrameName[100] = { 0 };
	for (int i = 1; i < 15; i++)
	{
		sprintf(szSpFrameName, "dance_%02d", i);
		auto frame = cache->getSpriteFrameByName(szSpFrameName);
		aminFrames1.pushBack(frame);
	}
	auto animation1 = Animation::createWithSpriteFrames(aminFrames1,0.3f);
	auto animateAction = Animate::create(animation1);
	sprite->runAction(RepeatForever::create(animateAction));

	//auto spriteBatch = SpriteBatchNode::create("animations/grossini-aliases.png");
	//spriteBatch->addChild(sprite);
	//addChild(spriteBatch);

	Vector<SpriteFrame*> animFrames(15);
	char str[100] = { 0 };
	for (int i = 1; i < 15; i++)
	{
		// Obtain frames by alias name
		sprintf(str, "dance_%02d", i);
		auto frame = cache->getSpriteFrameByName(str);
		animFrames.pushBack(frame);
	}

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.3f);
	// 14 frames * 1sec = 14 seconds
	//sprite->runAction(RepeatForever::create(Animate::create(animation)));


	auto texture = Director::getInstance()->getTextureCache()->addImage("animations/dragon_animation.png");

	// manually add frames to the frame cache
	auto frame0 = SpriteFrame::createWithTexture(texture, Rect(132 * 0, 132 * 0, 132, 132));
	auto frame1 = SpriteFrame::createWithTexture(texture, Rect(132 * 1, 132 * 0, 132, 132));
	auto frame2 = SpriteFrame::createWithTexture(texture, Rect(132 * 2, 132 * 0, 132, 132));
	auto frame3 = SpriteFrame::createWithTexture(texture, Rect(132 * 3, 132 * 0, 132, 132));
	auto frame4 = SpriteFrame::createWithTexture(texture, Rect(132 * 0, 132 * 1, 132, 132));
	auto frame5 = SpriteFrame::createWithTexture(texture, Rect(132 * 1, 132 * 1, 132, 132));


	//
	// Animation using Sprite BatchNode
	//
	auto spriteDragon = Sprite::createWithSpriteFrame(frame0);
	spriteDragon->setPosition(Vec2(visibleSize.width / 2 , visibleSize.height / 2 + 100));
	addChild(spriteDragon);

	Vector<SpriteFrame*> animFramesDragon(6);
	animFramesDragon.pushBack(frame0);
	animFramesDragon.pushBack(frame1);
	animFramesDragon.pushBack(frame2);
	animFramesDragon.pushBack(frame3);
	animFramesDragon.pushBack(frame4);
	animFramesDragon.pushBack(frame5);

	auto animationDragon = Animation::createWithSpriteFrames(animFramesDragon, 0.2f);
	auto animateDragon = Animate::create(animationDragon);
	auto seq = Sequence::create(animateDragon,
		FlipX::create(true),
		animateDragon->clone(),
		FlipX::create(false),
		nullptr);

	spriteDragon->runAction(RepeatForever::create(seq));

     
    return true;
}
