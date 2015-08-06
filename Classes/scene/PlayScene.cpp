#include "PlayScene.h"


PlayScene::PlayScene()
:m_bGameOver(false)
{
} 


PlayScene::~PlayScene()
{
}

PlayScene* PlayScene::createPlayScene()
{
	PlayScene *pRet = new PlayScene();
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

bool PlayScene::init()
{
	return false;
}
