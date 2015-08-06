#include "RankLayer.h"


RankLayer::RankLayer()
{
}


RankLayer::~RankLayer()
{
}

bool RankLayer::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(false == Layer::init());
		auto pRankLayerBgImg = Sprite::create("rank-board.png");
		CC_BREAK_IF(nullptr == pRankLayerBgImg);
		pRankLayerBgImg->setPosition(WINWIDTH / 2, WINHEIGHT);
		pRankLayerBgImg->setScale(0.55f);
		this->addChild(pRankLayerBgImg, enZOrderPopLayer, enTagBgImg);
		auto BoardActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2, WINHEIGHT / 2)));
		pRankLayerBgImg->runAction(BoardActionTo);


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
		backBtn->setPosition(Point(WINWIDTH / 2 - 100, WINHEIGHT));
		this->addChild(backBtn, enZOrderBackBtn, enTagBackBtn);
		auto backBtnActionTo = EaseElasticOut::create(MoveTo::create(1, Point(WINWIDTH / 2 - 150, WINHEIGHT / 4)));
		backBtn->runAction(backBtnActionTo);


		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func RankLayer::init Run Error!");
	return bRet;
}


void RankLayer::onButtonCallback(Ref* pSender)
{
	Sprite* pSpriteBuf = static_cast<Sprite*>(pSender);
	int nTagBuf = pSpriteBuf->getTag();
	switch (nTagBuf)
	{
	case enTagBackBtn:
		//this->runAction(EaseElasticInOut::create(Sequence::create(MoveTo::create(1, Point(-250, WINHEIGHT - 190)), 0.45)));
		this->removeFromParent();
		break;
	}
}

void RankLayer::onEnter()
{
	Layer::onEnter();

	// Register Touch Event
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(RankLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(RankLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(RankLayer::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void RankLayer::onExit()
{
	//    auto director = Director::getInstance();
	//    director->getTouchDispatcher()->removeDelegate(this);
	Layer::onExit();
}

bool RankLayer::onTouchBegan(Touch* touch, Event* event)
{

	return true;
}

void RankLayer::onTouchMoved(Touch* touch, Event* event)
{

}

void RankLayer::onTouchEnded(Touch* touch, Event* event)
{

}