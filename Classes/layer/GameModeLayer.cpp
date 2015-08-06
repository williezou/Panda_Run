#include "GameModeLayer.h"
#include "PlayScene.h"


GameModeLayer::GameModeLayer()
{
}


GameModeLayer::~GameModeLayer()
{
}

GameModeLayer* GameModeLayer::creatGameModeLayer()
{
	GameModeLayer *pRet = new GameModeLayer();
	if (pRet && pRet->init())
	{ 
		pRet->autorelease();
		return pRet;
	} 
	else 
	{ 
		delete pRet;
		pRet = NULL;
		return NULL;
	} 
}


bool GameModeLayer::init()
{
	bool bRet = false;
	do 
	{
		//this->setTouchEnabled(true);

		auto pBoard = Sprite::create("mode-board.png");
		pBoard->setPosition(WINWIDTH / 2, WINHEIGHT);
		this->addChild(pBoard, enZOrderBoard, enTagBoard);
		auto BoardActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2, WINHEIGHT / 2)));
		pBoard->runAction(BoardActionTo);

		//模式1按钮
		auto modeOneBtn = Button::create("mode1.png", "", "mode1.png");
		modeOneBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				onButtonCallback(sender);
				break;
			default:
				break;
			}
		});
		modeOneBtn->setPosition(Point(WINWIDTH / 2 - 120, WINHEIGHT + 30));
		this->addChild(modeOneBtn, enZOrderModeOne,enTagModeOne);
		auto modeOneBtnActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2 - 120, WINHEIGHT / 2)));
		modeOneBtn->runAction(modeOneBtnActionTo);

		//模式2按钮
		auto modeTwoBtn = Button::create("mode2.png","","mode2.png");
		modeTwoBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				onButtonCallback(sender);
				break;
			default:
				break;
			}
		});
		modeTwoBtn->setPosition(Point(WINWIDTH / 2 + 120, WINHEIGHT + 30));
		this->addChild(modeTwoBtn, enZOrderModeTwo, enTagModeTwo);
		auto modeTwoBtnActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2 + 120, WINHEIGHT / 2)));
		modeTwoBtn->runAction(modeTwoBtnActionTo);


		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func GameModeLayer::init Run Error!");
	return bRet;
}


void GameModeLayer::onButtonCallback(Ref* sender)
{
	Sprite* pSpriteBuf = static_cast<Sprite*>(sender);
	int nTagBuf = pSpriteBuf->getTag();
	switch (nTagBuf)
	{
	case enTagModeOne:
	{
		CCLOG("==enTagModeOne==");
		auto pPlayScene = PlayScene::create();
		Director::getInstance()->replaceScene(pPlayScene);
		break;
	}

	case enTagModeTwo:
		CCLOG("==enTagModeTwo==");
		break;
	}
}

void GameModeLayer::onEnter()
{
	Layer::onEnter();

	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameModeLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameModeLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameModeLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameModeLayer::onExit()
{
	//    auto director = Director::getInstance();
	//    director->getTouchDispatcher()->removeDelegate(this);
	Layer::onExit();
}

bool GameModeLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

void GameModeLayer::onTouchMoved(Touch* touch, Event* event)
{

}

void GameModeLayer::onTouchEnded(Touch* touch, Event* event)
{

}