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

//获得子弹伤害值
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
		//子弹移动结束目标点
		m_ptBulletEndPoint = ptBulletEndPoint;
		//判断是否是多重抢
		m_bIsShutGun = IsShutGun;

		//记录子弹的伤害量
		m_nBulletDamage = nBulletDamage;

		Move();

		this->schedule(schedule_selector(Bullet::BulletLoop));
		bRet = true;
		return bRet;
	} while (false);
	CCLog("Func Bullet::Init Error!");
	return bRet;
}
//子弹更新函数，被主场景调用
void Bullet::BulletLoop(float ft)
{
	if (IsDisappear())
	{
		Disappear();
		return;
	}
}
//子弹移动
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
//判断子弹是否消除
bool Bullet::IsDisappear()
{
	//获得屏幕区域
	CCRect WinRect = CCRectMake(0.f, 0.f, _SCREEN_WIDTH_, _SCREEN_HEIGHT_);
	if (WinRect.intersectsRect(boundingBox()))
	{
		return false;
	}
	return true;
}

//消除子弹
void Bullet::Disappear()
{
	BulletForDisappearMsg Info;
	Info.pSelf = this;
	this->SendMsg(enMsgBulletForDisappear, &Info, sizeof(Info));
}