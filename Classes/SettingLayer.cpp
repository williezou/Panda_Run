#include "SettingLayer.h"


SettingLayer::SettingLayer()
{
}


SettingLayer::~SettingLayer()
{
}

bool SettingLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(false == Layer::init());
		auto pDrawNode = DrawNode::create();
		CC_BREAK_IF(nullptr == pDrawNode);
		pDrawNode->drawRect(Point(0, WINHEIGHT), Point(WINWIDTH, 0), Color4F(0, 0, 0, 80));
		this->addChild(pDrawNode, enZOrderDrawNode, enTagDrawNode);

		

		auto pSettingLayerBgImg = Sprite::create("ui/set-board.png");
		CC_BREAK_IF(nullptr == pSettingLayerBgImg);
		pSettingLayerBgImg->setPosition(WINWIDTH / 2 + 300, WINHEIGHT / 2);
		pSettingLayerBgImg->setScale(0.80f);
		this->addChild(pSettingLayerBgImg, enZOrderPopLayer, enTagBgImg);
		auto BoardActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2, WINHEIGHT / 2)));
		pSettingLayerBgImg->runAction(BoardActionTo);


		//backBtn
		auto backBtn = Button::create("ui/back-btn.png", "", "ui/back-btn.png");
		backBtn->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
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
		backBtn->setPosition(Point(WINWIDTH / 2 - 120, WINHEIGHT + 160));
		this->addChild(backBtn, enZOrderBackBtn, enTagBackBtn);
		auto backBtnActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2 -100, WINHEIGHT / 2 - 160)));
		backBtn->runAction(backBtnActionTo);



		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func SettingLayer::init Run Error!");
	return bRet;
}

void SettingLayer::onEnter()
{
	Layer::onEnter();

	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(SettingLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SettingLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SettingLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void SettingLayer::onExit()
{
	//    auto director = Director::getInstance();
	//    director->getTouchDispatcher()->removeDelegate(this);
	Layer::onExit();
}

bool SettingLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

void SettingLayer::onTouchMoved(Touch* touch, Event* event)
{

}

void SettingLayer::onTouchEnded(Touch* touch, Event* event)
{

}
