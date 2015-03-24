#include "BackGround.h"

#define BACKGROUND_SPEED 3.2f
#define MAX_DISPLACEMENT 800


BackGroundNode* BackGroundNode::CreateBackGround(const char* pFileName)
{
	do 
	{
		BackGroundNode* pBackGround = new BackGroundNode;
		if (pBackGround && pBackGround->Init(pFileName))
		{
			pBackGround->autorelease();
			return pBackGround;
		}
		delete pBackGround;
	} while (false);
	CCLog("Fun BackGround::CreateBackGround Error!");
	return NULL;
}

//��ʼ��
bool BackGroundNode::Init(const char* pFileName)
{
	do 
	{
		CC_BREAK_IF(!CCNode::init());
		m_fDisplacement = 0;
		m_fSpeed = BACKGROUND_SPEED;

		//��ӱ���ͼƬ
		CCSprite* pBackGround1 = CCSprite::create(pFileName);
		CC_BREAK_IF(pBackGround1 == NULL);
		pBackGround1->setPosition(ccp(pBackGround1->getContentSize().width*0.5f, 0.f));
		this->addChild(pBackGround1, enZOrderBack, enTagBack1);

		//��ӱ���ͼƬ
		CCSprite* pBackGround2 = CCSprite::create(pFileName);
		CC_BREAK_IF(pBackGround2 == NULL);
		pBackGround2->setPosition(ccp(-pBackGround2->getContentSize().width*0.5f, 0.f));
		this->addChild(pBackGround2, enZOrderBack, enTagBack2);

		//ע�����ں���
		this->schedule(schedule_selector(BackGroundNode::BackGroundLoop));

		return true;
	} while (false);
	CCLog("Fun BackGround::Init Error!");
	return false;
}

void BackGroundNode::BackGroundLoop(float ft)
{
	if (IsReset())
	{
		Reset();
	}
	if (IsMove())
	{
		//����fT����ֵ�����������һ��������Ҫ�ƶ���λ����
		m_fSpeed = (ft / 0.02f)* BACKGROUND_SPEED;
		Move();
	}
}

bool BackGroundNode::IsMove()
{
	return true;
}
//����
void BackGroundNode::Move()
{
	do
	{
		m_fDisplacement += m_fSpeed;
		CCSprite* pBackGround1 = dynamic_cast<CCSprite*>(this->getChildByTag(enTagBack1));
		CC_BREAK_IF(pBackGround1 == NULL);
		CCSprite* pBackGround2 = dynamic_cast<CCSprite*>(this->getChildByTag(enTagBack2));
		CC_BREAK_IF(pBackGround2 == NULL);

		pBackGround1->setPositionX(pBackGround1->getPositionX() - m_fSpeed);
		pBackGround2->setPositionX(pBackGround2->getPositionX() - m_fSpeed);

		return;
	} while (false);
	CCLog("Fun BackGround::Move Error!");
}

//�ж��Ƿ���Ҫ����ĳһ�ű���ͼλ��
bool BackGroundNode::IsReset()
{
	if (m_fDisplacement >= MAX_DISPLACEMENT)
	{
		m_fDisplacement = 0;
		return true;
	}
	return false;
}

void BackGroundNode::Reset()
{
	do 
	{
		//�������ͼƬ
		CCSprite* pBackGround1 = dynamic_cast<CCSprite*>(this->getChildByTag(enTagBack1));
		CC_BREAK_IF(pBackGround1 == NULL);
		CCSprite* pBackGround2 = dynamic_cast<CCSprite*>(this->getChildByTag(enTagBack2));
		CC_BREAK_IF(pBackGround2 == NULL);
		//�ж����ű���ͼ���ϣ�Ȼ�����һ��ͼ������һ��ͼ�ĺ���
		if (pBackGround1->getPositionX() < pBackGround2->getPositionX())
		{
			pBackGround1->setPositionX(pBackGround1->getPositionX() + MAX_DISPLACEMENT * 2);
		}
		else
		{
			pBackGround2->setPositionX(pBackGround2->getPositionX() + MAX_DISPLACEMENT * 2);
		}
		return;
	} while (false);
	CCLog("Fun BackGround::Reset Error!");
}