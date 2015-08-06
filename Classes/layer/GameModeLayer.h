#ifndef __GAME_MODE_LAYER_H__
#define __GAME_MODE_LAYER_H__

#include "Public.h"

class GameModeLayer : public Layer
{
public:
	GameModeLayer();
	~GameModeLayer();
	
	bool init();
	static GameModeLayer* creatGameModeLayer();

protected:
	enum enTag
	{
		enTagBoard = 100,
		enTagBackBtn,
		enTagModeOne,
		enTagModeTwo
	};

	enum enZOrder
	{
		enZOrderBoard = 100,
		enZOrderBackBtn,
		enZOrderModeOne,
		enZOrderModeTwo
	};

public:

	void onButtonCallback(Ref* sender);

public:
	virtual void onEnter() override;
	virtual void onExit() override;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

};

#endif //__GAME_MODE_LAYER_H__