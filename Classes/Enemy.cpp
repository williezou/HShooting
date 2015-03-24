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

//���˸��º���
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
	//	//�ƶ�����µ�����ײ�����λ�á�
	//	m_rtEnemyForCollision.setRect(this->getPositionX() - this->boundingBox().size.width*0.3, this->getPositionY() - this->boundingBox().size.height*0.2, this->boundingBox().size.width*0.5, this->boundingBox().size.height*0.5);
	//}

}

//�ж��Ƿ�����
bool Enemy::IsDead()
{
	if (m_nHp < 1)
	{
		return true;
	}
	return false;
}

//�����е���Ѫ������
void Enemy::Hurt(int nBulletDamage)
{
	m_nHp -= nBulletDamage;
}

bool Enemy::Init(CCTexture2D* pTexture, Receiver* pReceiver, float fSpeed, int nScore, int nHp)
{
	do 
	{
		CC_BREAK_IF(!CCSprite::initWithTexture(pTexture));
		//����Ա������ֵ
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

//�ж��Ƿ��ƶ�
bool Enemy::IsMove()
{
	return true;
}

// Enemy��·��
CCFiniteTimeAction* Enemy::Route()
{
	int time = VisibleRect::right().x / m_fSpeed;
	int w = boundingBox().size.width;
	return  CCMoveBy::create(time, ccp(-VisibleRect::right().x - boundingBox().size.width, 0));
}

//�ƶ�
void Enemy::Move()
{
	// TODO
	//SetPositionWithRand();

	CCActionInterval* pMoveAction = CCSequence::create(Route(), CCCallFunc::create(this, callfunc_selector(Enemy::Disappear)), NULL);
	this->setPositionX(this->getPositionX() - m_fSpeed);
	pMoveAction->setTag(100);
	this->runAction(pMoveAction);
}

//�жϳ�����Ļ������ʧ
bool Enemy::IsDisappear()
{
	//�����Ļ��С
	CCRect WinRect = CCRectMake(0.f, 0.f, _SCREEN_WIDTH_, _SCREEN_HEIGHT_);

	//����Ļ������ �� �����������򳹵�û�н��� ����ΪӦ������
	if (WinRect.intersectsRect(this->boundingBox()))
	{
		return false;
	}
	else
	{
		return true;
	}
}

//������Ϣ���ٵ���
void Enemy::Disappear()
{
	stopAllActions();
	EnemyForDisappearMsg Info;
	Info.pSelf = this;
	this->SendMsg(enMsgEnemyForDisappear, &Info, sizeof(Info));
}

//���ű�ը����
void Enemy::Dead()
{
	do 
	{
		//Ϊ��ֹ����ѭ��ʱ�������ţ�����һ�����أ������ſ�ʼʱ���ٲ���
		if (m_bIsAnimationOn)
		{
			//�ӷ�
			AddScoreMsg Info;
			Info.nScore = m_nScore;
			SendMsg(enMsgAddScore, &Info, sizeof(Info));

			//��Ϊ��������ֻ��Ҫ����һ�Σ����Բ���Ҫ�ٴ�
			m_bIsAnimationOn = false;
			CCAnimation* pBoom = CCAnimationCache::sharedAnimationCache()->animationByName("baozha");
			CC_BREAK_IF(pBoom == NULL);

			//���ű�ը�������������ú�������Ϣ����
			runAction(CCSequence::create(CCAnimate::create(pBoom), CCCallFunc::create(this, callfunc_selector(Enemy::Disappear)), NULL));
		}
		return;
	} while (false);
	CCLog("Func Enemy::Dead Error!");
	return;
}
