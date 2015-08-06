#ifndef __LOGO_LAYER_H__
#define __LOGO_LAYER_H__

#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

class LogoLayer : public Layer
{
public:
	// static cocos2d::Scene* createScene();
	bool init();
	CREATE_FUNC(LogoLayer);
private:

	enum 
	{
		enZOrderBg,
		enZOrderMxonTeam
	};

	enum
	{
		enTagBg,
		enTagMxonTeam
	};
};

#endif // __HELLOWORLD_SCENE_H__
