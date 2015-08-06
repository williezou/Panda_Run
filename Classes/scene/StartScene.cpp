#include "StartScene.h"
#include "MenuLayer.h"

//StartScene::StartScene()
//{
//}
//
//
//StartScene::~StartScene()
//{
//}

bool StartScene::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Scene::init());

		auto pMenuLayer = MenuLayer::create();
		CC_BREAK_IF(pMenuLayer == NULL);
		this->addChild(pMenuLayer);

		bRet = true;
		return bRet;

	} while (false);
	CCLOG("Func StartScene::init Run Error!");
	return bRet;
}
