#ifndef __HERO_H__
#define __HERO_H__

#include "PublicDefine.h"

#define FIRE_CD 5

/************************************************************************/
/* ��ͨӢ����                                                            */
/************************************************************************/
class NormalHero : public CCSprite, public Sender
{
protected:
	
	int m_nFireCD;			//�����ʱ�������
	int m_nShootRate;		//�����Ƶ�ʣ�����CD
	int m_nDamageAmount;	//�ӵ����˺�
	
public:
	CCRect m_rtRectForCollision;		//�ɻ�����ײ���
	static NormalHero*  CreateHero(Receiver* pReceiver);

	//ѭ���ж�Hero�Ƿ񿪻�
	void HeroLoop();
	//Hero����ײ���
	virtual CCRect BoundingBox();
protected:
	bool Init(Receiver* pReceiver);
	//�ж��Ƿ񿪻�
	virtual bool IsFire();
	//����
	virtual void Fire();

};

#endif//__HERO_H__

