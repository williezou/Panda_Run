#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include "Public.h"

class BackGroundNode : public Node
{
protected:
	Sprite* m_pNearBag;		//¹ö¶¯±³¾°Í¼Æ¬
	float m_fNearBgWidth;	//¹ö¶¯±³¾°Í¼Æ¬¿í¶È
	int m_nNearBgIndex;		//µ±Ç°¹ö¶¯±³¾°Í¼Æ¬

public:
	static BackGroundNode* createBg(const std::string& filename);

protected:
	bool init(const std::string& filename);

};

#endif //__BACK_GROUND_H__