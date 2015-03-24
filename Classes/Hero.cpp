#include "Hero.h"

NormalHero*  NormalHero::CreateHero(Receiver* pReceiver)
{
	do 
	{
		NormalHero* pRet = new NormalHero();
		if (pRet && pRet->Init(pReceiver) == true)
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			CC_SAFE_DELETE(pRet);
		}
	} while (false);
	CCLog("Fun Hero::CreateHero Error!");
	return NULL;
}

//ѭ���ж�Hero�Ƿ񿪻�
void NormalHero::HeroLoop()
{
	if (IsFire())
	{
		Fire();
	}
}
//Hero����ײ���
CCRect NormalHero::BoundingBox()
{
	m_rtRectForCollision.setRect(this->getPositionX() - this->boundingBox().size.width*0.3f, this->getPositionY() - this->boundingBox().size.height*0.25f, this->boundingBox().size.width*0.5, this->boundingBox().size.height*0.5);
	return m_rtRectForCollision;
}

bool NormalHero::Init(Receiver* pReceiver)
{
	do 
	{
		CC_BREAK_IF(CCSprite::initWithFile("Chopper1_1.png") == false);
		m_pReceiver = pReceiver;

		//��xml�ļ�
		CCDictionary* pHeroInfo = CCDictionary::createWithContentsOfFile("heroinfo.xml");
		CC_BREAK_IF(pHeroInfo == NULL);

		//��ȡ�˺�ֵ
		CCString* pStringDamegeAmount = dynamic_cast<CCString*>(pHeroInfo->objectForKey("planedamageamount1"));
		CC_BREAK_IF(pStringDamegeAmount == NULL);
		//��ȡ���Ƶ��
		CCString* pStringShootRate = dynamic_cast<CCString*>(pHeroInfo->objectForKey("planeshootspeedrate1"));
		CC_BREAK_IF(pStringShootRate == NULL);

		m_nDamageAmount = atoi(pStringDamegeAmount->m_sString.c_str());
		m_nShootRate = atoi(pStringShootRate->m_sString.c_str());
	    m_nFireCD = m_nShootRate;

		return true;
	} while (false);
	CCLog("Fun Hero::Init Error!");
	return false;
}
	//�ж��Ƿ񿪻�
bool NormalHero::IsFire()
{
	if (m_nFireCD == 0)
	{
		m_nFireCD = m_nShootRate;
		return true;
	}
	else
	{
		m_nFireCD--;
		return false;
	}
}

//����
void NormalHero::Fire()
{
	BulletForCreateMsg CmdHeroFireInfo;
	CmdHeroFireInfo.ptBulletStartPoint = ccp(1.5*this->getPositionX(), this->getPositionY() + 0.5f);
	CmdHeroFireInfo.ptBulletEndPoint = ccp(_SCREEN_WIDTH_ + 100.f, 0);
	CmdHeroFireInfo.IsShutGun = false;
	CmdHeroFireInfo.nBulletDamage = m_nDamageAmount;
	this->SendMsg(enMsgBulletForCreate, &CmdHeroFireInfo, sizeof(CmdHeroFireInfo));
}