#ifndef __ABOUT_LAYER_H__
#define __ABOUT_LAYER_H__

#include "Public.h"
#include "MenuLayer.h"

class AboutLayer: public MenuLayer
{
public:
	AboutLayer();
	~AboutLayer();

	bool init();
	CREATE_FUNC(AboutLayer);

protected:
	enum enTag
	{
		enTagBoard = 50,
		enTagBackBtn
	};

	enum enZOrder
	{
		enZOrderBoard = 50,
		enZOrderBackBtn
	};

	void backToMenu();

public:
	virtual void onEnter() override;
	virtual void onExit() override;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif //__ABOUT_LAYER_H__