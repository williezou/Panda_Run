#ifndef __CHAPTER2LEVEL1_H__
#define __CHAPTER2LEVEL1_H__

#include "cocos2d.h"

#include <iostream>

USING_NS_CC;

class Chapter2Level1 : public Node
{
public:
	static cocos2d::Scene* createScene();

	bool init();
};

#endif // __CHAPTER2LEVEL1_H__
