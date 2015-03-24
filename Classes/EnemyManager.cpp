#include "EnemyManager.h"

EnemyManager* EnemyManager::CreateEnemyManager(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver)
{
	do 
	{
		EnemyManager* pEnemyManager = new EnemyManager;
		if (pEnemyManager && pEnemyManager->Init(pTexture,fSpeed, nCD, nScore, nHp, pReceiver))
		{
			pEnemyManager->autorelease();
			return pEnemyManager;
		}
		else
		{
			CC_SAFE_DELETE(pEnemyManager);
		}
	} while (false);
	CCLog("Func EnemyManager::CreateEnemyManager Error!");
	return NULL;
}

//判断是否创建敌人
void EnemyManager::EnemyManagerLoop()
{
	if (IsCreate())
	{
		Create();
	}
}

bool EnemyManager::Init(CCTexture2D* pTexture, float fSpeed, int nCD, int nScore, int nHp, Receiver* pReceiver)
{	
	bool bRet = false;
	do 
	{
		//对敌人的属性赋值
		m_nScore = nScore;
		m_nHp = nHp;
		m_pReceiver = pReceiver;
		m_nCD = nCD;
		m_nCDTime = m_nCD;
		m_pTexture = pTexture;
		m_fSpeed = fSpeed;

		bRet = true;
		return bRet;
	} while (false);
	CCLog("Func EnemyManager::Init Error!");
	return bRet;
}

bool EnemyManager::IsCreate()
{
	if (m_nCD == 0)
	{
		m_nCD = m_nCDTime;
		return true;
	}
	else
	{
		m_nCD--;
		return false;
	}
}

//根据敌人属性创建敌人
void EnemyManager::Create()
{
	CCSize EnemySize = m_pTexture->getContentSize();
	EnemyForCreateMsg Info;
	Info.nScore = m_nScore;
	Info.nHp = m_nHp;
	Info.pTexture = m_pTexture;
	Info.fSpeed = m_fSpeed;
	//为了不让敌机产生一半在屏幕外的情况
	srand((int)time(0));
	Info.pStartPoint = CCPointMake(_SCREEN_WIDTH_ - EnemySize.width * 0.5, rand() % (int)(_SCREEN_HEIGHT_ - EnemySize.height)
		+ EnemySize.height*0.5);
	//发消息创建敌人
	this->SendMsg(enMsgEnemyForCreate, &Info, sizeof(Info));
}
