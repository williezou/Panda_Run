#include "AboutLayer.h"




AboutLayer::AboutLayer()
{
}


AboutLayer::~AboutLayer()
{
}

bool AboutLayer::init()
{
	bool bRet = false;
	do 
	{
		auto board = Sprite::create("ui/about-board.png");
		CC_BREAK_IF(board == NULL);
		board->setPosition(Point(WINSIZE.width / 2 + 300, WINSIZE.height / 2));
		this->addChild(board, enZOrderBoard, enTagBoard);
		auto actionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINSIZE.width / 2, WINSIZE.height / 2)));
		board->runAction(actionTo);

		auto backBtn = Button::create("ui/back-btn.png", "ui/back-btn.png", "");
		backBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
			switch (type)
			{
			case ui::Widget::TouchEventType::BEGAN:
				break;
			case ui::Widget::TouchEventType::ENDED:
				backToMenu();
				break;
			default:
				break;
			}
		});

		backBtn->setPosition(Point(WINSIZE.width + 100, 60));
		backBtn->runAction(EaseElasticOut::create(MoveTo::create(1, Point(WINSIZE.width / 2 - 100, WINSIZE.height / 2 - 190))));
		this->addChild(backBtn, enZOrderBackBtn,enTagBackBtn);

		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func AboutLayer::init Run Error!");
	return bRet;
}


void AboutLayer::backToMenu()
{
	this->removeFromParent();
}

void AboutLayer::onEnter()
{
	Layer::onEnter();

	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(AboutLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(AboutLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(AboutLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void AboutLayer::onExit()
{
	//    auto director = Director::getInstance();
	//    director->getTouchDispatcher()->removeDelegate(this);
	Layer::onExit();
}

bool AboutLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

void AboutLayer::onTouchMoved(Touch* touch, Event* event)
{

}

void AboutLayer::onTouchEnded(Touch* touch, Event* event)
{

}