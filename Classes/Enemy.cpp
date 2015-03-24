#include "Enemy.h"

Enemy* Enemy::CreateEnemy(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp)
{
	do 
	{
		Enemy* pEnemy = new Enemy;
		if (pEnemy && pEnemy->Init(pTexture, pReceiver,fSpeed, nScore, nHp))
		{
			pEnemy->autorelease();
			return pEnemy;
		}
		else
		{
			CC_SAFE_DELETE(pEnemy);
		}
	} while (false);
	CCLog("Func Enemy::CreateEnemy Error!");
	return NULL;
}

//敌人更新函数
void Enemy::EnemyLoop()
{
	if (IsDead())
	{
		Dead();
		return;
	}
	if (IsDisappear())
	{
		Disappear();
		return;
	}

	//if (IsMove())
	//{
	//	Move();
	//	//移动后更新敌人碰撞方块的位置。
	//	m_rtEnemyForCollision.setRect(this->getPositionX() - this->boundingBox().size.width*0.3, this->getPositionY() - this->boundingBox().size.height*0.2, this->boundingBox().size.width*0.5, this->boundingBox().size.height*0.5);
	//}

}

//判断是否死亡
bool Enemy::IsDead()
{
	if (m_nHp < 1)
	{
		return true;
	}
	return false;
}

//被击中敌人血量减少
void Enemy::Hurt(int nBulletDamage)
{
	m_nHp -= nBulletDamage;
}

bool Enemy::Init(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp)
{
	do 
	{
		CC_BREAK_IF(!CCSprite::initWithTexture(pTexture));
		//给成员变量赋值
		m_pReceiver = pReceiver;
		m_fSpeed = fSpeed;
		this->m_nScore = nScore;
		this->m_nHp = nHp;
		m_bIsAnimationOn = true;
		return true;
	} while (false);
	CCLog("Func Enemy::Init Error!");
	return false;
}

//判断是否移动
bool Enemy::IsMove()
{
	return true;
}

// Enemy的路线
CCFiniteTimeAction* Enemy::Route()
{
	int time = VisibleRect::right().x / m_fSpeed;
	int w = boundingBox().size.width;
	return  CCMoveBy::create(time, ccp(-VisibleRect::right().x - boundingBox().size.width, 0));
}

//移动
void Enemy::Move()
{
	// TODO
	//SetPositionWithRand();

	CCActionInterval* pMoveAction = CCSequence::create(Route(), CCCallFunc::create(this, callfunc_selector(Enemy::Disappear)), NULL);
	this->setPositionX(this->getPositionX() - m_fSpeed);
	pMoveAction->setTag(100);
	this->runAction(pMoveAction);
}

//判断超出屏幕敌人消失
bool Enemy::IsDisappear()
{
	//获得屏幕大小
	CCRect WinRect = CCRectMake(0.f, 0.f, _SCREEN_WIDTH_, _SCREEN_HEIGHT_);

	//若屏幕的区域 与 敌人自身区域彻底没有交集 则认为应该消除
	if (WinRect.intersectsRect(this->boundingBox()))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//发送消息销毁敌人
void Enemy::Disappear()
{
	stopAllActions();
	EnemyForDisappearMsg Info;
	Info.pSelf = this;
	this->SendMsg(enMsgEnemyForDisappear, &Info, sizeof(Info));
}

//播放爆炸动画
void Enemy::Dead()
{
	do 
	{
		//为防止动画循环时反复播放，设置一个开关，当播放开始时则不再播放
		if (m_bIsAnimationOn)
		{
			//加分
			AddScoreMsg Info;
			Info.nScore = m_nScore;
			SendMsg(enMsgAddScore, &Info, sizeof(Info));

			//因为死亡动画只需要播放一次，所以不需要再打开
			m_bIsAnimationOn = false;
			CCAnimation* pBoom = CCAnimationCache::sharedAnimationCache()->animationByName("baozha");
			CC_BREAK_IF(pBoom == NULL);

			//播放爆炸动画，结束调用函数发消息销毁
			runAction(CCSequence::create(CCAnimate::create(pBoom), CCCallFunc::create(this, callfunc_selector(Enemy::Disappear)), NULL));
		}
		return;
	} while (false);
	CCLog("Func Enemy::Dead Error!");
	return;
}
