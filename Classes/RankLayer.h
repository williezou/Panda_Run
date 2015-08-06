#ifndef __RANK_LAYER_H__
#define __RANK_LAYER_H__

#include "Public.h"

class RankLayer : public Layer
{
public:
	RankLayer();
	~RankLayer();

	bool init();
	CREATE_FUNC(RankLayer);



protected:
	enum enTag
	{
		enTagBgImg,
		enTagBackBtn
	};

	enum enZOrder
	{
		enZOrderBackBtn = 5,
	};

public:

	virtual void onButtonCallback(Ref* pSender);

public:
	virtual void onEnter() override;
	virtual void onExit() override;
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif //__RANK_LAYER_H__