#ifndef __BULLET_H__
#define __BULLET_H__

#include "PublicDefine.h"
/************************************************************************/
/* 创建子弹类                                                           */
/************************************************************************/

class Bullet : public CCSprite, public Sender
{
protected:
	CCPoint		m_ptBulletEndPoint;					//子弹移动的目标点
	bool		m_bIsShutGun;						//判断是否是多重抢
	int			m_nBulletDamage;					//子弹伤害量
public:
	static Bullet* CreateBullet(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage);
	//获得子弹的伤害量
	int GetBulletDamage();
protected:
	bool Init(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage);
	//子弹更新函数，被主场景调用
	void BulletLoop(float ft);
	//子弹移动
	void Move();
	//判断子弹是否消除
	bool IsDisappear();
	//消除子弹
	void Disappear();

};
#endif//__BULLET_H__

