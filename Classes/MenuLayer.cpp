#include "MenuLayer.h"
#include "SimpleAudioEngine.h"
#include "Public.h"
#include "AboutLayer.h"
#include "GameModeLayer.h"
#include "RankLayer.h"
#include "SettingLayer.h"

MenuLayer::MenuLayer()
{

}

MenuLayer::~MenuLayer()
{
}


bool MenuLayer::init()
{
	bool bRet = false;
	do 
	{
		//添加背景图片
		auto pBgImg = Sprite::create("menu-bg.png");
		CC_BREAK_IF(pBgImg == NULL);
		pBgImg->setPosition(Point(WINSIZE.width / 2, WINSIZE.height / 2));
		this->addChild(pBgImg, enZOrderBg, enTagBg);
		auto moveBg = EaseElasticOut::create(MoveTo::create(5, Point(WINSIZE.width / 2, WINSIZE.height / 2)));
		pBgImg->runAction(moveBg);

		//init logo
		auto pLogo = Sprite::create("game-logo.png");
		pLogo->setPosition(Point(250, WINSIZE.height - 160));
		pLogo->setScale(0.8);
		this->addChild(pLogo,enZOrderLogo,enTagLogo);
		//logo动作
		auto logoMove = EaseElasticOut::create(MoveTo::create(1, Point(250, WINSIZE.height - 150)));
		auto logoShaking = EaseElasticIn::create(MoveTo::create(1, Point(250, WINSIZE.height - 250)));
		auto logoShakingBack = EaseElasticOut::create(MoveTo::create(1, Point(250, WINSIZE.height - 140)));
		auto logoShakingSeq = Sequence::create(logoShaking, logoShakingBack, nullptr);
		auto logoSeq = Sequence::create(
			logoMove, 
			logoShaking, 
			logoShakingBack, 
			logoShakingSeq, 
			logoShakingSeq,
			nullptr);
		pLogo->runAction(RepeatForever::create(logoSeq));


		//exit btn
		auto exitBtn = MenuItemImage::create(
			"ui/back-btn.png", 
			"ui/back-btn.png", 
			CC_CALLBACK_1(MenuLayer::onButtonCallback, this));
		exitBtn->setScale(0.8);
		exitBtn->setPosition(Point(75, 75));
		exitBtn->setTag(enTagExitBtn);

		//play btn
		auto playBtn = MenuItemImage::create(
			"play-btn.png",
			"play-btn-s.png",
			CC_CALLBACK_1(MenuLayer::onButtonCallback, this));

		playBtn->setPosition(Point(-200, WINSIZE.height));
		playBtn->setTag(enTagPlayBtn);

		//playBtn 动作
		auto playBtnMove = EaseElasticInOut::create(MoveTo::create(2, Point(200, 220)), 0.8f);
		auto playBtnShaking = EaseIn::create(MoveTo::create(1, Point(200, 220)), 2.0f);
		auto playBtnShakingBack = EaseOut::create(MoveTo::create(1, Point(200, 210)), 2.0f);
		auto playBtnShakingSeq = Sequence::create(playBtnShaking, playBtnShakingBack, nullptr);
		auto seqPlayBtn = Sequence::create(
			playBtnMove,
			playBtnShaking,
			playBtnShakingBack,
			playBtnShakingSeq,
			playBtnShakingSeq,
			nullptr);
		playBtn->runAction(RepeatForever::create(seqPlayBtn));

		//rankBtn
		auto rankBtn = MenuItemImage::create(
			"rank-btn.png",
			"rank-btn.png",
			CC_CALLBACK_1(MenuLayer::onButtonCallback, this));
		rankBtn->setTag(enTagRankBtn);
		rankBtn->setPosition(Point(WINSIZE.width + 200, WINSIZE.height - 220));
		//storeBtn 动作
		auto rankBtnActionTo = EaseElasticOut::create(MoveTo::create(2.0f, Point(700, 320)));
		auto rankBtnSharking = EaseBackInOut::create(MoveTo::create(2.0f, Point(693, 320)));
		auto rankBtnShakingBack = EaseBackInOut::create(MoveTo::create(2.0f, Point(708, 320)));
		auto rankBtnShakingSeq = Sequence::create(rankBtnSharking, rankBtnShakingBack, nullptr);
		auto rankBtnSeq = Sequence::create(
			rankBtnActionTo,
			rankBtnSharking,
			rankBtnShakingBack,
			rankBtnShakingSeq, nullptr);
		rankBtn->runAction(RepeatForever::create(rankBtnSeq));

		//settingBtn
		auto setBtn = MenuItemImage::create(
			"set-btn.png",
			"set-btn-s.png",
			CC_CALLBACK_1(MenuLayer::onButtonCallback, this));
		setBtn->setTag(enTagSetBtn);
		setBtn->setPosition(Point(200, WINSIZE.height - 300));

		//settingBtn 动作
		auto setBtnActionTo = EaseElasticOut::create(MoveTo::create(2.0f, Point(700, 240)));
		auto setBtnShaking = EaseBackInOut::create(MoveTo::create(2.0f, Point(693, 240)));
		auto setBtnShakingBack = EaseBackInOut::create(MoveTo::create(2.0f, Point(708, 240)));
		auto setBtnShakingSeq = Sequence::create(DelayTime::create(0.3f), setBtnShaking, setBtnShakingBack, nullptr);
		auto setBtnSeq = Sequence::create(
			setBtnActionTo, 
			setBtnShaking, 
			setBtnShakingBack, 
			setBtnShakingSeq, nullptr);
		setBtn->runAction(RepeatForever::create(setBtnSeq));

		//aboutBtn
		auto aboutBtn = MenuItemImage::create(
			"about-btn.png",
			"about-btn-s.png",
			CC_CALLBACK_1(MenuLayer::onButtonCallback, this));
		aboutBtn->setTag(enTagAboutBtn);
		aboutBtn->setPosition(Point(WINSIZE.width - 200, WINSIZE.height + 100));

		//aboutBtn 动作
		auto aboutBtnActionTo = EaseElasticOut::create(MoveTo::create(2.0f, Point(700, 160)));
		auto aboutBtnShaking = EaseBackInOut::create(MoveTo::create(2.0f, Point(693, 160)));
		auto aboutBtnShakingBack = EaseBackInOut::create(MoveTo::create(2.0f, Point(708, 160)));
		auto aboutBtnShakingSeq = Sequence::create(DelayTime::create(0.2f), aboutBtnShaking, aboutBtnShakingBack, nullptr);
		auto aboutBtnSeq = Sequence::create(
			aboutBtnActionTo, 
			aboutBtnShaking, 
			aboutBtnShakingBack, 
			aboutBtnShakingSeq, nullptr);
		aboutBtn->runAction(RepeatForever::create(aboutBtnSeq));

		auto menu = Menu::create(exitBtn, playBtn, rankBtn, setBtn, aboutBtn, nullptr);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, enZOrderBtn, enTagMenu);

		//@TODO:Bug1# panda 倒退
		//add an player here
		auto pSpriteFrameCache = SpriteFrameCache::getInstance();
		pSpriteFrameCache->addSpriteFramesWithFile("panda.plist");
		auto pSpriteBatchNode = SpriteBatchNode::create("panda.png");
		m_pSpritePanda = Sprite::createWithSpriteFrameName("panda_run_01.png");
		m_pSpritePanda->setPosition(Point(40, 60));
		pSpriteBatchNode->addChild(m_pSpritePanda);
		addChild(pSpriteBatchNode);

		//CCArray* animFrames = CCArray::createWithCapacity(8);
		Vector<SpriteFrame*> animFrames;
		//animFrames.capacity;
		char str[100] = { 0 };

		for (int i = 1; i < 8; i++)
		{
			sprintf(str, "panda_run_0%d.png", i);
			CCSpriteFrame* frame = pSpriteFrameCache->spriteFrameByName(str);
			//animFrames->addObject(frame);
			animFrames.pushBack(frame);
		}

		CCAnimation* animation = CCAnimation::createWithSpriteFrames(animFrames, 0.08f);
		m_pSpritePanda->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
		

		auto moveTo = MoveTo::create(10.0f, Point(WINSIZE.width + 200, 60));
		///auto move2 = MoveTo::create(10.0f, Point(-400,60));

		//设置move2为动作回调函数，将panda的位置重置
		//注意Lambda表达式的用法，改为成员变量就能取到panda精灵
		auto sequence = Sequence::create(
			moveTo,
			CallFunc::create([&]() {
			m_pSpritePanda->setPosition(-400, 60);
		}),
			nullptr);

		m_pSpritePanda->runAction(CCRepeatForever::create(sequence));

		//添加粒子效果
		createParticle("circle_particle.plist");

		scheduleUpdate();

		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func MenuLayer::init Run Error!");
	return bRet;
}


void MenuLayer::onButtonCallback(Ref* pSender)
{
	Sprite* pSpriteBuf = static_cast<Sprite*>(pSender);
	int nTagBuf = pSpriteBuf->getTag();
	switch (nTagBuf)
	{
	case enTagPlayBtn:
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/button.mp3");
			CCLOG("==========MenuLayer::onPlayBtnCallback==============");
			auto pGameModeLayer = GameModeLayer::creatGameModeLayer();
			this->addChild(pGameModeLayer, enZOrderPopLayer, enTagGameModeLayer);
			break;
		}

	case enTagExitBtn:
	{
		Director::getInstance()->end();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		exit(0);
	#endif
		break;
	}


	case enTagRankBtn:
	{
		auto pRankLayer = RankLayer::create();
		this->addChild(pRankLayer, enZOrderPopLayer, enTagAboutLayer);
		break;
	}

	case enTagSetBtn:
	{
		auto pSettingLayer = SettingLayer::create();
		this->addChild(pSettingLayer, enZOrderPopLayer, enTagSettingLayer);
		break;
	}

	case enTagAboutBtn:
		{
			auto pAboutLayer = AboutLayer::create();
			this->addChild(pAboutLayer, enZOrderPopLayer, enTagAboutLayer);
			break;
		}
	}
}

void MenuLayer::createParticle(const std::string& filename)
{
	ParticleSystemQuad *particle = ParticleSystemQuad::create(filename);
	this->addChild(particle);
	particle->setPosition(Vec2(800, 100));
}