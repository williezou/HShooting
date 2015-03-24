#include "Bullet.h"

Bullet* Bullet::CreateBullet(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage)
{
	do 
	{
		Bullet* pBullet = new Bullet;
		if (pBullet && pBullet->Init(pReceiver,ptBulletEndPoint,IsShutGun,nBulletDamage))
		{
			pBullet->autorelease();
			return pBullet;
		}
		else
		{
			CC_SAFE_DELETE(pBullet);
		}
	} while (false);
	CCLog("Func Bullet::CreateBullet Error!");
	return NULL;
}

//����ӵ��˺�ֵ
int Bullet::GetBulletDamage()
{
	return m_nBulletDamage;
}

bool Bullet::Init(Receiver* pReceiver, CCPoint ptBulletEndPoint, bool IsShutGun, int nBulletDamage)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!CCSprite::initWithFile("p_bullet_2.png"));
		m_pReceiver = pReceiver;
		//�ӵ��ƶ�����Ŀ���
		m_ptBulletEndPoint = ptBulletEndPoint;
		//�ж��Ƿ��Ƕ�����
		m_bIsShutGun = IsShutGun;

		//��¼�ӵ����˺���
		m_nBulletDamage = nBulletDamage;

		Move();

		this->schedule(schedule_selector(Bullet::BulletLoop));
		bRet = true;
		return bRet;
	} while (false);
	CCLog("Func Bullet::Init Error!");
	return bRet;
}
//�ӵ����º�����������������
void Bullet::BulletLoop(float ft)
{
	if (IsDisappear())
	{
		Disappear();
		return;
	}
}
//�ӵ��ƶ�
void Bullet::Move()
{
	do 
	{
		if (m_bIsShutGun == false)
		{
			CCActionInterval* pMoveBy = CCMoveBy::create(1.f, m_ptBulletEndPoint);
			CC_BREAK_IF(pMoveBy == NULL);
			this->runAction(pMoveBy);
		}
		else
		{
			CCActionInterval* pMoveBy = CCMoveBy::create(0.1f, m_ptBulletEndPoint);
			CC_BREAK_IF(pMoveBy == NULL);
			CCActionInterval* pMoveByCross = CCMoveBy::create(0.9f, ccp(0, _SCREEN_HEIGHT_ + 100.f));
			CC_BREAK_IF(pMoveByCross == NULL);
			CCFiniteTimeAction* pSeq = CCSequence::create(pMoveBy, pMoveByCross, NULL);
			CC_BREAK_IF(pSeq == NULL);
			this->runAction(pSeq);
		}
		return;
	} while (false);
	CCLOG("Func Bullet::Move Error!");
	return;
}
//�ж��ӵ��Ƿ�����
bool Bullet::IsDisappear()
{
	//�����Ļ����
	CCRect WinRect = CCRectMake(0.f, 0.f, _SCREEN_WIDTH_, _SCREEN_HEIGHT_);
	if (WinRect.intersectsRect(boundingBox()))
	{
		return false;
	}
	return true;
}

//�����ӵ�
void Bullet::Disappear()
{
	BulletForDisappearMsg Info;
	Info.pSelf = this;
	this->SendMsg(enMsgBulletForDisappear, &Info, sizeof(Info));
}