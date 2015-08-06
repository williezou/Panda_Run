#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include "cocos2d.h"
USING_NS_CC;
#include "ui/CocosGUI.h"
using namespace ui;

#define		WINSIZE		Director::getInstance()->getWinSize()

#define		WINWIDTH	Director::getInstance()->getWinSize().width
#define		WINHEIGHT	Director::getInstance()->getWinSize().height

enum
{
	enZOrderBg,
	enZOrderLogo,
	enZOrderBtn,
	enZOrderDrawNode,
	enZOrderPopLayer,

};

enum
{
	enTagBg,
	enTagLogo,
	enTagMenu,
	enTagPlayBtn,
	enTagExitBtn,
	enTagRankBtn,
	enTagAboutBtn,
	enTagSetBtn,
	enTagAboutLayer,
	enTagRankLayer,
	enTagGameModeLayer,
	enTagSettingLayer

};

#endif //__PUBLIC_H__