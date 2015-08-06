#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "Public.h"

class PlayScene : public Node
{
public:
	PlayScene();
	~PlayScene();

	static PlayScene* createPlayScene();
	bool init();
	
public:
	bool m_bGameOver;

public:
	inline void setGameState(bool state) { m_bGameOver = state; };
	inline bool getgameState() { return m_bGameOver; };
};

#endif //__PLAY_SCENE_H__