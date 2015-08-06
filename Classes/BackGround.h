#ifndef __BACK_GROUND_H__
#define __BACK_GROUND_H__

#include "Public.h"

class BackGroundNode : public Node
{
protected:
	Sprite* m_pNearBag;		//��������ͼƬ
	float m_fNearBgWidth;	//��������ͼƬ���
	int m_nNearBgIndex;		//��ǰ��������ͼƬ

public:
	static BackGroundNode* createBg(const std::string& filename);

protected:
	bool init(const std::string& filename);

};

#endif //__BACK_GROUND_H__