#include "BackGround.h"

BackGroundNode* BackGroundNode::createBg(const std::string& filename)
{
	BackGroundNode* pRet = new BackGroundNode;
	if (pRet && pRet->init(filename))
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

bool BackGroundNode::init(const std::string& filename)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Node::init());
		auto pSprite = Sprite::create(filename);
		CC_BREAK_IF(NULL == pSprite);
		//位置函数 的应用
		pSprite->setPosition(WINWIDTH / 2, WINHEIGHT / 2);

		this->addChild(pSprite, 10, 2);

		bRet = true;
		return bRet;

	} while (false);
	CCLOG("Func BackGroundNode::init Run Error!");
	return bRet;
}