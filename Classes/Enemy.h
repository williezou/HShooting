#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "PublicDefine.h"
/************************************************************************/
/* 创建敌人类                                                           */
/************************************************************************/
class Enemy : public CCSprite, public Sender
{
protected:
	float		m_fSpeed;			//敌人速度
	int			m_nScore;			//击杀敌人获得分数
	int			m_nHp;				//敌人血量
	bool		m_bIsAnimationOn;	//爆炸动画开关
public:
	CCRect m_rtEnemyForCollision;		//敌人的碰撞体积
	static Enemy* CreateEnemy(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp);
	//敌人更新函数
	void EnemyLoop();
	//判断是否死亡
	bool IsDead();
	//被击中敌人血量减少
	void Hurt(int nBulletDamage);

	virtual CCFiniteTimeAction* Route(); //路线

	//移动
	virtual void Move();
protected:
	bool Init(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp);
	//判断是否移动
	bool IsMove();

	//判断是否消失
	bool IsDisappear();
	//销毁
	void Disappear();
	//播放爆炸动画
	void Dead();
};
#endif //__ENEMY_H__

