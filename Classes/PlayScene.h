#ifndef __PLAY_SCENE_H__
#define __PLAY_SCENE_H__

#include "Public.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();

	bool init();
	CREATE_FUNC(PlayScene);

public:
	bool initSpace();
	bool initState();
	bool initCamera();
	bool initStatistics();
	bool intSettings();

	void update(float delta);

	
protected:
	bool m_bGameOver;
	Camera* m_pCamera;
	cpSpace* m_pSpace;
	Point m_CenterPos;
	bool m_bDirty;

public:
	inline void setX(float x) { m_CenterPos.x = x; };
	inline float getX() { return m_CenterPos.x; }
	inline void setY(float y) { m_CenterPos.y = y; };
	inline float getY() { return m_CenterPos.y; };
	inline void setPos(Point pos) { m_CenterPos.x = pos.x; m_CenterPos.y = pos.y; };
	inline void setDirty(bool dirty) { m_bDirty = dirty; };
	inline bool getDirty() {return m_bDirty;}

	inline void setGameState(bool state) { m_bGameOver = state; };
	inline bool getgameState() { return m_bGameOver; };

public:
	virtual void onEnter() override;
	virtual void onExit() override;
};

#endif //__PLAY_SCENE_H__