#ifndef __BULLET_H__
#define __BULLET_H__

#include "PublicDefine.h"
/************************************************************************/
/* �����ӵ���                                                           */
/************************************************************************/

class Bullet : public CCSprite, public Sender
{
protected:
	CCPoint		m_ptBulletEndPoint;					//�ӵ��ƶ���Ŀ���
	bool		m_bIsShutGun;						//�ж��Ƿ��Ƕ�����
	int			m_nBulletDamage;					//�ӵ��˺���
public:
	static Bullet* CreateBullet(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage);
	//����ӵ����˺���
	int GetBulletDamage();
protected:
	bool Init(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage);
	//�ӵ����º�����������������
	void BulletLoop(float ft);
	//�ӵ��ƶ�
	void Move();
	//�ж��ӵ��Ƿ�����
	bool IsDisappear();
	//�����ӵ�
	void Disappear();

};
#endif//__BULLET_H__

