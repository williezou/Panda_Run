#include "LogoLayer.h"
#include "Chapter2.h"
#include "SimpleAudioEngine.h"
#include "StartScene.h"

USING_NS_CC;
 

bool LogoLayer::init()
{ 

	Size winSize = Director::getInstance()->getWinSize();
	 
	auto bg =  Sprite::create("open-bg.png");
	bg->setPosition(Point(winSize.width / 2, winSize.height / 2));
	//this->addChild(bg, 0);
	this->addChild(bg, enZOrderBg,enTagBg);

	auto team = Sprite::create("maxon-team.png");
	team->setPosition(Point(winSize.width / 2, winSize.height / 2));
	team->setScale(0.4f);
	team->setOpacity(0);
	//this->addChild(team, 1);
	this->addChild(team, enZOrderMxonTeam,enTagMxonTeam);

	auto fadeIn =  FadeIn::create(1.0);
	auto fadeOut = FadeOut::create(1.0);
	auto delay = DelayTime::create(1.0);
	auto seq = Sequence::create(
		fadeIn,
		delay,
		fadeOut,
		CallFunc::create([&]() { 
		//Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, Chapter2::createScene()/*, Color3B(0, 255, 255)*/));
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, StartScene::create()/*, Color3B(0, 255, 255)*/));
	} ),
		nullptr);
	team->runAction(seq);
	 
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sounds/opening.mp3");


    return true;
}
