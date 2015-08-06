#include "PlayScene.h"
#include "BackGround.h"


PlayScene::PlayScene()
//:m_bGameOver(false), 
//m_CenterPos((WINWIDTH / 2, 0)),
//m_bDirty(false),
//m_pSpace(NULL),
//m_pCamera(NULL)
{
} 


PlayScene::~PlayScene()
{
}

bool PlayScene::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(false == Scene::init());

		bRet = true;
		return bRet;
	} while (false);
	CCLOG("Func PlayScene::init Run Error!");
	return bRet;
}

//bool PlayScene::initSpace()
//{
//	bool bRet = false;
//	do 
//	{
//		bRet = true;
//		return bRet;
//	} while (false);
//	CCLOG("Func PlayScene::initSpace Run Error!");
//	return bRet;
//}
//
//bool PlayScene::initState()
//{
//	bool bRet = false;
//	do
//	{
//		bRet = true;
//		return bRet;
//	} while (false);
//	CCLOG("Func PlayScene::initState Run Error!");
//	return bRet;
//}
//
//bool PlayScene::initCamera()
//{
//	bool bRet = false;
//	do
//	{
//		Point desPoint;
//
//		bRet = true;
//		return bRet;
//	} while (false);
//	CCLOG("Func PlayScene::initCamera Run Error!");
//	return bRet;
//}
//
//bool PlayScene::initStatistics()
//{
//	bool bRet = false;
//	do
//	{
//		bRet = true;
//		return bRet;
//	} while (false);
//	CCLOG("Func PlayScene::initStatistics Run Error!");
//	return bRet;
//}
//
//bool PlayScene::intSettings()
//{
//	bool bRet = false;
//	do
//	{
//		bRet = true;
//		return bRet;
//	} while (false);
//	CCLOG("Func PlayScene::intSettings Run Error!");
//	return bRet;
//}


void PlayScene::update(float delta)
{

}

void PlayScene::onEnter()
{
	Scene::onEnter();
	this->addChild(BackGroundNode::createBg("far-bg.png"));
	//this->addChild(BackGroundNode::createBg("far-bg1.png"));
}

void PlayScene::onExit()
{
	Scene::onExit();
}