#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

class Chapter2 : public Layer
{
public:
	static cocos2d::Scene* createScene();
	bool init();
	CREATE_FUNC(Chapter2);

};

#endif // __HELLOWORLD_SCENE_H__
