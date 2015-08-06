#include "LogoScene.h"
#include "LogoLayer.h"

USING_NS_CC;
 

bool LogoScene::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Scene::init());
		auto logoLayer = LogoLayer::create();
		CC_BREAK_IF(logoLayer == nullptr);
		this->addChild(logoLayer);

		bRet = true;
		return bRet;
	} while (false);
	
	CCLOG("Func LogoScene::init Run Error!");
	
	return bRet;
}
