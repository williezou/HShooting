#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "PublicDefine.h"
/************************************************************************/
/* ����������                                                           */
/************************************************************************/
class Enemy : public CCSprite, public Sender
{
protected:
	float		m_fSpeed;			//�����ٶ�
	int			m_nScore;			//��ɱ���˻�÷���
	int			m_nHp;				//����Ѫ��
	bool		m_bIsAnimationOn;	//��ը��������
public:
	CCRect m_rtEnemyForCollision;		//���˵���ײ���
	static Enemy* CreateEnemy(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp);
	//���˸��º���
	void EnemyLoop();
	//�ж��Ƿ�����
	bool IsDead();
	//�����е���Ѫ������
	void Hurt(int nBulletDamage);

	virtual CCFiniteTimeAction* Route(); //·��

	//�ƶ�
	virtual void Move();
protected:
	bool Init(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp);
	//�ж��Ƿ��ƶ�
	bool IsMove();

	//�ж��Ƿ���ʧ
	bool IsDisappear();
	//����
	void Disappear();
	//���ű�ը����
	void Dead();
};
#endif //__ENEMY_H__

