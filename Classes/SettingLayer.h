#ifndef __SETTING_LAYER_H__
#define __SETTING_LAYER_H__

#include "Public.h"
#include "RankLayer.h"

class SettingLayer : public Layer
{
public:
	SettingLayer();
	~SettingLayer();

	bool init();
	CREATE_FUNC(SettingLayer);

private:
	enum 
	{
		enTagDrawNode,
		enTagBgImg,
		enTagBackBtn
	};

	enum
	{
		enZOrderBackBtn = 5,
	};

public:
	inline void onButtonCallback(Ref* pSender) { removeFromParent(); };

public:
	virtual void onEnter() override;
	virtual void onExit() override;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif //__SETTING_LAYER_H__