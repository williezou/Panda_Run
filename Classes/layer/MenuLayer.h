#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__

#include "Public.h"

class MenuLayer : public Layer
{
public:
	MenuLayer();
	~MenuLayer();

	bool init();
	CREATE_FUNC(MenuLayer);

	//´´½¨Á£×Ó
	void createParticle(const std::string& filename);


protected:
	void onButtonCallback(Ref* pSender);

private:
	Sprite* m_pSpritePanda;

	//void backToMenu(Ref* pSender);

};


#endif //__MENU_LAYER_H__