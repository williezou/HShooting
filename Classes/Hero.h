#ifndef __HERO_H__
#define __HERO_H__

#include "PublicDefine.h"

#define FIRE_CD 5

/************************************************************************/
/* 普通英雄类                                                            */
/************************************************************************/
class NormalHero : public CCSprite, public Sender
{
protected:
	
	int m_nFireCD;			//开火的时间计数器
	int m_nShootRate;		//开火的频率，开火CD
	int m_nDamageAmount;	//子弹的伤害
	
public:
	CCRect m_rtRectForCollision;		//飞机的碰撞体积
	static NormalHero*  CreateHero(Receiver* pReceiver);

	//循环判断Hero是否开火
	void HeroLoop();
	//Hero的碰撞体积
	virtual CCRect BoundingBox();
protected:
	bool Init(Receiver* pReceiver);
	//判断是否开火
	virtual bool IsFire();
	//开火
	virtual void Fire();

};

#endif//__HERO_H__

