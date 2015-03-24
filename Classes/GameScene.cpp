#include "GameScene.h"
#include "BeganScene.h"
#include "BackGround.h"
#include "Hero.h"
#include "ChooseHero.h"
#include "Bullet.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include "SimpleAudioEngine.h"
#include "FileSystem.h"

using namespace CocosDenshion;

//有几种敌人
#define ENEMY_TYPE_COUNT 6
struct EnemyManagerPkg
{
	CCTexture2D* pTexture;  //纹理
	float fSpeed;			//移动速度
	int	nCD;				//刷新速度
	int nScore;				//分数
	int	nHp;				//血量
};

/************************************************************************/
/* 游戏场景                                                             */
/************************************************************************/
//建立场景和层
CCScene* GameScene::CreateScene(int nChooper)
{
	do 
	{
		//建立场景
		CCScene* pScene = CCScene::create();
		CC_BREAK_IF(pScene == NULL);

		//建立层
		GameScene* pLayer = new GameScene();
		if (pLayer->init(nChooper) && pLayer!=NULL)
		{
			pScene->addChild(pLayer);
		}
		return pScene;

	} while (false);
	CCLog("Fun GameScene::CreateScene Error!");
	return NULL;
}

bool GameScene::init(int nChooper)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(CCLayer::init() == false);

		//设置单点触摸
		this->setTouchEnabled(true);
		this->setTouchMode(kCCTouchesOneByOne);
		//开启back&menu
		this->setKeypadEnabled(true);

		//英雄类型
		m_nChooper = nChooper + 1;

		//初始化子弹集合
		m_pBulletArray = CCArray::create();
		CC_BREAK_IF(m_pBulletArray == NULL);
		m_pBulletArray->retain();
		//初始化被删除的子弹集合
		m_pBulletArrayDeleted = CCArray::create();
		CC_BREAK_IF(m_pBulletArrayDeleted == NULL);
		m_pBulletArrayDeleted->retain();
		//初始化敌人集合
		m_pEnemyArray = CCArray::create();
		CC_BREAK_IF(m_pEnemyArray == NULL);
		m_pEnemyArray->retain();
		//初始化被删除的敌人集合
		m_pEnemyArrayDeleted = CCArray::create();
		CC_BREAK_IF(m_pEnemyArrayDeleted == NULL);
		m_pEnemyArrayDeleted->retain();
		//初始化敌人管理器集合
		m_pEnemyManagerArray = CCArray::create();
		CC_BREAK_IF(m_pEnemyManagerArray == NULL);
		m_pEnemyManagerArray->retain();

		CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

		//add homemenu item, which is clicked to go back the BeganScene
		CCMenuItemImage *pHomeItem = CCMenuItemImage::create(
			"home.png",
			"home.png",
			this,
			menu_selector(GameScene::menuHomeCallback));

		pHomeItem->setPosition(ccp(pHomeItem->getContentSize().width / 2,
			origin.y + pHomeItem->getContentSize().height / 2));
		pHomeItem->setTag(enTagHomeBtn);

		//add pause item,which is clicked to pause the GameScene
		CCMenuItemImage* pPauseImage = CCMenuItemImage::create(
			"pause.png",
			"pause.png",
			this,
			menu_selector(GameScene::OnPause));
		CC_BREAK_IF(pPauseImage == NULL);

		pPauseImage->setPosition(ccp(pHomeItem->getPositionX() + pPauseImage->getContentSize().width,
			origin.y + pPauseImage->getContentSize().height / 2));
		pPauseImage->setTag(enTagPauseBtn);

		//add music item,which is clicked to close the BackgroundMusic
		CCMenuItemImage* pMusicImage = CCMenuItemImage::create(
			"music_open.png",
			"music_close.png",
			this,
			menu_selector(GameScene::OnPause));
		CC_BREAK_IF(pMusicImage == NULL);
		pMusicImage->setPosition(ccp(pPauseImage->getPositionX() + pMusicImage->getContentSize().width,
			origin.y + pMusicImage->getContentSize().height / 2));
		pMusicImage->setTag(enTagMusicBtn);

		//add bomb item,which is clicked to bombed all the animy
		CCMenuItemImage* pBombImage = CCMenuItemImage::create(
			"bombbtn.png",
			"bombbtn.png",
			this,
			menu_selector(GameScene::OnPause));
		CC_BREAK_IF(pBombImage == NULL);
		pBombImage->setPosition(ccp(origin.x + visibleSize.width - pBombImage->getContentSize().width / 2,
			origin.y + pBombImage->getContentSize().height / 2));
		pBombImage->setTag(enTagBombBtn);

		// create menu
		CCMenu* pMenu = CCMenu::create(pHomeItem, pPauseImage, pMusicImage, pBombImage, NULL);
		CC_BREAK_IF(pMenu == NULL);
		pMenu->setPosition(CCPointZero);
		addChild(pMenu, enZOrderBtn);

		//建立玩家对象
		NormalHero* pHero = NormalHero::CreateHero(this);
		CC_BREAK_IF(pHero == NULL);
		pHero->setPosition(ccp(_SCREEN_WIDTH_*0.2f, _SCREEN_HEIGHT_*0.5f));
		this->addChild(pHero, enZOrderFront, enTagPlayer);

		//建立背景对象
		BackGroundNode* pBackGround = BackGroundNode::CreateBackGround("bg.png");
		CC_BREAK_IF(pBackGround == NULL);
		pBackGround->setPosition(ccp(_SCREEN_WIDTH_*0.5f, _SCREEN_HEIGHT_*0.5f));
		addChild(pBackGround, enZOrderBack, enTagBackGround);

		//添加分数显示器
		CCLabelTTF* pScore = CCLabelTTF::create("score:", "Comic Sans MS", 35);
		CC_BREAK_IF(pScore == NULL);
		pScore->setColor(ccc3(100, 255, 0));
		pScore->setAnchorPoint(ccp(0, 0.5));
		pScore->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ - 10.f));
		addChild(pScore, enZOrderBtn, enTagScore);
		m_nScore = 0;

		//敌人信息集合 纹理，移动速度，刷新速度，分数，血量
		const EnemyManagerPkg tempEnemyManagerArray[ENEMY_TYPE_COUNT] = {
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy1.png"), 7, 4000, 100, 1 },
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy2.png"), 5, 1300, 200, 1 },
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy3.png"), 3, 2500, 300, 1 },
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy4.png"), 6, 4000, 400, 1 },
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy5.png"), 2, 3000, 500, 1 },
			{ CCTextureCache::sharedTextureCache()->addImage("Enemy6.png"), 4, 1600, 600, 1 } };

		//遍历敌人信息集合，建立每种敌人的管理器
		for (int i = 0; i < ENEMY_TYPE_COUNT; i++)
		{
			EnemyManager* pEnemyManager = EnemyManager::CreateEnemyManager(
				tempEnemyManagerArray[i].pTexture, tempEnemyManagerArray[i].fSpeed,
				tempEnemyManagerArray[i].nCD, tempEnemyManagerArray[i].nScore,
				tempEnemyManagerArray[i].nHp, this);
			//什么情况下使用CCassert？
			CCAssert(pEnemyManager != NULL, "pEnemyManage==NULL");
			//防止引擎释放敌人管理器，需要在层的onExit函数释放。
			pEnemyManager->retain();
			//将建立的敌人管理器存入敌人管理器集合
			m_pEnemyManagerArray->addObject(pEnemyManager);
		}

		//播放声音
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgsound.mp3", true);

		InitAnimation();
		//注册Update函数
		this->schedule(schedule_selector(GameScene::OnPreFrameUpdate));

		bRet = true;
		return bRet;
	} while (0);
	CCLog("Fun GameScene::init Error!");
	return bRet;
}

bool GameScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void GameScene::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	do
	{
		NormalHero* pHero = dynamic_cast<NormalHero*>(this->getChildByTag(enTagPlayer));
		CC_BREAK_IF(pHero == NULL);
		//防止玩家英雄飞出屏幕
		CCSize HeroSize = pHero->getTexture()->getContentSize();
		if ((pHero->getPosition() + pTouch->getLocation() - pTouch->getPreviousLocation()).x > HeroSize.width*0.5 &&
			(pHero->getPosition() + pTouch->getLocation() - pTouch->getPreviousLocation()).x < _SCREEN_WIDTH_ - HeroSize.width*0.5 &&
			(pHero->getPosition() + pTouch->getLocation() - pTouch->getPreviousLocation()).y > HeroSize.height*0.5 &&
			(pHero->getPosition() + pTouch->getLocation() - pTouch->getPreviousLocation()).y < _SCREEN_HEIGHT_ - HeroSize.height*0.5
			)
		{
			//玩家移动距离为：当前检测到的位置与上一次检测到的位置之差加上玩家位置。
			pHero->setPosition(pHero->getPosition() + pTouch->getLocation()
				- pTouch->getPreviousLocation());
		} 

		return;
	} while (false);
	CCLog("Fun GameScene::ccTouchMoved Error!");
}

void GameScene::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}

//重写的接收函数，每当被调用则根据收到的不同消息执行不同命令
void GameScene::OnMsgReceive(int enMsg, void* pData, int nSize)
{
	switch (enMsg)
	{
	case enMsgBulletForCreate:
	{
		if (sizeof(BulletForCreateMsg) != nSize)
		{
			CCAssert(false, "sizeof(BulletForCreateMsg)!=nSize");
		}
		this->BulletCreate((BulletForCreateMsg*)pData);
	}
		break;
	case enMsgBulletForDisappear:
	{
		if (sizeof(BulletForDisappearMsg) != nSize)
		{
			CCAssert(false, "sizeof(BulletForDisappearMsg)!=nSize");
		}
		this->BulletDisappear((BulletForDisappearMsg*)pData);
	}
		break;
	case enMsgEnemyForCreate:
	{
		if (sizeof(EnemyForCreateMsg) != nSize)
		{
			CCAssert(false, "sizeof(EnemyForCreateMsg)!=nSize");
		}
		this->EnemyCreate((EnemyForCreateMsg*)pData);
	}
		break;
	case enMsgEnemyForDisappear:
	{
		if (sizeof(EnemyForDisappearMsg) != nSize)
		{
			CCAssert(false, "sizeof(EnemyForDisappearMsg)!=nSize");
		}
		this->EnemyDisappear((EnemyForDisappearMsg*)pData);
	}
		break;
	case enMsgAddScore:
	{
		if (sizeof(AddScoreMsg) != nSize)
		{
			CCAssert(false, "sizeof(EnemyForDisappearMsg)!=nSize");
		}
		this->AddScore((AddScoreMsg*)pData);
	}
		break;
	}
}

//更新函数
void GameScene::OnPreFrameUpdate(float ft)
{
	do 
	{
		//玩家每帧循环
		NormalHero* pHero = dynamic_cast<NormalHero*>(this->getChildByTag(enTagPlayer));
		CC_BREAK_IF(pHero == NULL);
		pHero->HeroLoop();

		//删除上一帧被标记（存入删除集合的子弹对象）需要删除的子弹
		m_pBulletArray->removeObjectsInArray(m_pBulletArrayDeleted);
		m_pBulletArrayDeleted->removeAllObjects();

		CCObject* pObj = NULL;
		//遍历敌人管理器集合，刷出满足刷新条件的敌人
		CCARRAY_FOREACH(m_pEnemyManagerArray, pObj)
		{
			EnemyManager* pEnemyManager = dynamic_cast<EnemyManager*>(pObj);
			CCAssert(pEnemyManager != NULL, "pEnemyManager == NULL");
			pEnemyManager->EnemyManagerLoop();
		}

		//遍历敌人集合，并循环
		CCARRAY_FOREACH(m_pEnemyArray, pObj)
		{
			Enemy* pEnemy = dynamic_cast<Enemy*>(pObj);
			CCAssert(pEnemy != NULL, "pEnemy == NULL");
			pEnemy->EnemyLoop();
		}

		//删除需要被删除的敌人
		m_pEnemyArray->removeObjectsInArray(m_pEnemyArray);
		m_pEnemyArrayDeleted->removeAllObjects();

		//碰撞
		this->Collision();

		//修改分数
		CCLabelTTF* pScore = dynamic_cast<CCLabelTTF*>(getChildByTag(enTagScore));
		CC_BREAK_IF(pScore == NULL);
		pScore->setString(GetStringFromInt(m_nScore));

		return;
	} while (false);
	CCLog("Func GameScene::OnPreFrameUpdate Error!");
	return;
}

//接受消息
void GameScene::BulletCreate(BulletForCreateMsg* pData)
{
	do
	{
		Bullet* pBullet = Bullet::CreateBullet(this, pData->ptBulletEndPoint, pData->IsShutGun, pData->nBulletDamage);
		CC_BREAK_IF(pBullet == NULL);

		pBullet->setPosition(pData->ptBulletStartPoint);
		this->addChild(pBullet, enZOrderMiddle);

		m_pBulletArray->addObject(pBullet);

		return;
	} while (false);
	CCLog("Fun GameScene::BulletCreate Error!");
	return;
}
void GameScene::BulletDisappear(BulletForDisappearMsg* pData)
{
	do
	{
		this->removeChild(pData->pSelf);
		m_pBulletArrayDeleted->addObject(pData->pSelf);
		return;
	} while (false);
	CCLog("Fun GameScene::BulletDisappear Error!");
	return;
}

void GameScene::EnemyCreate(EnemyForCreateMsg* pData)
{
	do 
	{
		Enemy* pEnemy = Enemy::CreateEnemy(pData->pTexture, this, pData->fSpeed, pData->nScore, pData->nHp);
		CC_BREAK_IF(pEnemy == NULL);
		pEnemy->Move();
		pEnemy->setPosition(pData->pStartPoint);
		this->addChild(pEnemy, enZOrderMiddle);
		m_pEnemyArray->addObject(pEnemy);

		return;
	} while (false);
	CCLog("Func GameScene::EnemyCreate Error!");
	return;
}

//删除敌人，释放数组
void GameScene::EnemyDisappear(EnemyForDisappearMsg* pData)
{
	do 
	{
		this->removeChild(pData->pSelf);
		m_pEnemyArrayDeleted->addObject(pData->pSelf);
		return;
	} while (false);
	CCLog("Func GameScene::EnemyDisappear Error!");
	return;
}
void GameScene::AddScore(AddScoreMsg* pData)
{
	m_nScore += pData->nScore;
}

//碰撞检测
void GameScene::Collision()
{
	do 
	{
		//遍历敌人数组，检测当前敌人是否与某子弹或玩家碰撞
		CCObject* pObj = NULL;
		CCARRAY_FOREACH(m_pEnemyArray, pObj)
		{
			Enemy* pEnemy = dynamic_cast<Enemy*>(pObj);
			CCAssert(pEnemy != NULL, "pEnemy == NULL");
			//遍历子弹数组
			CCObject* pBulletObj = NULL;
			CCARRAY_FOREACH(m_pBulletArray, pBulletObj)
			{
				Bullet* pBullet = dynamic_cast<Bullet*>(pBulletObj);
				CCAssert(pBullet != NULL, "pBullet == NULL");
				//如果当前子弹在当前敌人的纹理范围内且敌人未死亡则发生碰撞
				if (pBullet->boundingBox().intersectsRect(pEnemy->boundingBox()) && pEnemy->IsDead() == false)
				{
					pEnemy->Hurt(pBullet->GetBulletDamage());
					this->removeChild(pBullet);
					m_pBulletArrayDeleted->addObject(pBullet);
				}
			}
			//如果玩家在当前敌人的纹理范围内且敌人未死亡，则游戏结束
			NormalHero* pHero = dynamic_cast<NormalHero*>(this->getChildByTag(enTagPlayer));
			CCAssert(pHero != NULL, "pHero == NULL");
			if (pHero->BoundingBox().intersectsRect(pEnemy->m_rtEnemyForCollision) && pEnemy->IsDead() == false)
			{
				this->unschedule(schedule_selector(GameScene::OnPreFrameUpdate));
				CCAnimation* pBoom = CCAnimationCache::sharedAnimationCache()->animationByName("baozha");
				CC_BREAK_IF(pBoom == NULL);
				pHero->runAction(CCSequence::create(CCAnimate::create(pBoom), CCCallFunc::create(this, callfunc_selector(GameScene::ShowGameOverLayer)), NULL));
				this->setTouchEnabled(false);
				break;
			}
		}
		return;
	} while (false);
	CCLog("Func GameScene::Collision Error!");
	return;
}
//将一个int转换成char
const char* GameScene::GetStringFromInt(int Num)
{
	char szStringName[_NAME_LEN_] = { 0 };
	sprintf(szStringName, "%d", Num);
	CCString* CCStr = CCString::createWithFormat(szStringName);
	const char* cStr = CCStr->getCString();
	return cStr;
}

//播放游戏结束层
void GameScene::ShowGameOverLayer()
{

}
//爆炸动画
void GameScene::InitAnimation()
{
	do 
	{
		//创建爆炸动画
		//将图片加入到缓存帧
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("baozha.plist", "baozha.png");
		//创建一个动画
		CCAnimation* pBoomAnimation = CCAnimation::create();
		CC_BREAK_IF(pBoomAnimation == NULL);
		pBoomAnimation->setDelayPerUnit(0.1f);
		pBoomAnimation->setLoops(1);
		pBoomAnimation->setRestoreOriginalFrame(false);
		//向动画添加帧
		int nIndex = 1;
		char FrameName[20] = { 0 };
		while (true)
		{
			sprintf(FrameName, "baozha_%d.png", nIndex++);
			//FrameName = CCString::createWithFormat("baozha_%d.png", nIndex++);
			CCSpriteFrame* pFram = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(FrameName);
			CC_BREAK_IF(pFram == NULL);
			pBoomAnimation->addSpriteFrame(pFram);
		}
		CCAnimationCache::sharedAnimationCache()->addAnimation(pBoomAnimation, "baozha");

		return;

	} while (false);
	CCLog("Func GameScene::InitAnimation Error!");
}

void GameScene::menuHomeCallback(CCObject* pSender)
{
	do
	{
		CCScene *pScene = BeginSceneLayer::scene();
		CC_BREAK_IF(pScene == NULL);

		CCDirector::sharedDirector()->replaceScene(pScene);
		return;
	} while (false);
	CCLog("Fun CCCMainsceneLayer::menuPlayCallback Error!");
}

void GameScene::OnPause(CCObject* pSender)
{
	do 
	{
		PauseBackLayer* pQuitLayer = dynamic_cast<PauseBackLayer*>(getChildByTag(enTagPauseBackLayer));
		if (pQuitLayer == NULL)
		{
			//创建游戏暂停层
			PauseBackLayer* pPauseLayer = PauseBackLayer::create();
			CC_BREAK_IF(pPauseLayer == NULL);
			addChild(pPauseLayer, enZOrderPauseBackLayer, enTagPauseBackLayer);

			CCAction* pPauseAction = CCSequence::create(
				CCDelayTime::create(0.02f),
				CCCallFunc::create(this, callfunc_selector(GameScene::OnStopAnimationCallBack)),
				NULL);
			runAction(pPauseAction);
		}
		return;
	} while (false);
	CCLog("Fun MainSceneLayer::menuExitCallback Error!");
}

void GameScene::keyBackClicked()
{
	do 
	{
		PauseBackLayer* pQuitLayer = dynamic_cast<PauseBackLayer*>(getChildByTag(enZOrderPauseBackLayer));
		if (pQuitLayer == NULL)
		{
			//创建游戏暂停层
			PauseBackLayer* pPauseLayer = PauseBackLayer::create();
			CC_BREAK_IF(pPauseLayer == NULL);
			addChild(pPauseLayer, enZOrderPauseBackLayer, enTagPauseBackLayer);

			CCAction* pPauseAction = CCSequence::create(
				CCDelayTime::create(0.02f),
				CCCallFunc::create(this, callfunc_selector(GameScene::OnStopAnimationCallBack)),
				NULL);
			runAction(pPauseAction);
		}
		return;
	} while (false);
	CCLog("Func MainSceneLayer::keyBackClicked Error!");
	return;
}

void GameScene::onEnter()
{
	CCLayer::onEnter();
}
void GameScene::onExit()
{
	CCLayer::onExit();
	m_pBulletArray->release();
	m_pBulletArrayDeleted->release();
	//敌人管理器集合内的所有成员都被手动防止释放，所以需要遍历分别释放
	m_pEnemyManagerArray->release();
	m_pEnemyArray->release();
	m_pEnemyArrayDeleted->release();
}

//游戏暂停
void GameScene::OnStopAnimationCallBack()
{
	CCDirector::sharedDirector()->pause();
}

/************************************************************************/
/* 暂停退出层                                                           */
/************************************************************************/
PauseBackLayer* PauseBackLayer::create()
{
	PauseBackLayer* pRet = new PauseBackLayer();
	if (pRet)
	{
		pRet->PauseBackLayer::init();
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool PauseBackLayer::init()
{
	bool bRet = false;
	do 
	{
		//场景父类初始化
		CC_BREAK_IF(!CCLayer::init());
		//判断是否点击到按钮
		m_bIsBtnClicked = false;

		//创建背景
		CCSprite* pBackGround = CCSprite::create("pauseTip.png");
		CC_BREAK_IF(pBackGround == NULL);
		pBackGround->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ / 2));
		this->addChild(pBackGround, enZOrderBackGround);

		CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
		//添加按钮
		CCMenuItemImage* pContinueItem = CCMenuItemImage::create(
			"go.png",
			"go.png",
			this,
			menu_selector(PauseBackLayer::menuContinueCallback));
		CC_BREAK_IF(!pContinueItem);
		
		pContinueItem->setPosition(ccp(pContinueItem->getContentSize().width + pContinueItem->getContentSize().width / 2,
			origin.y + pContinueItem->getContentSize().height / 2));

		//将menu添加到类里
		CCMenu* pMenu = CCMenu::create(pContinueItem, NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(!pMenu);
		this->addChild(pMenu, enZOrderBtn, enTagMenu);

		bRet = true;
		return bRet;
	} while (0);
	return bRet;
	CCLog("PauseBackLayer::init Error!");
}

//回调函数，继续和返回
void PauseBackLayer::menuContinueCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->resume();
	removeFromParent();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}
void PauseBackLayer::menuQuitCallback(CCObject* pSender)
{

}

//设置触摸
bool PauseBackLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	do 
	{
		//获得菜单
		CCMenu* pMenu = dynamic_cast<CCMenu*>(this->getChildByTag(enTagMenu));
		CC_BREAK_IF(pMenu);
		m_bIsBtnClicked = pMenu->ccTouchBegan(pTouch, pEvent);
		return true;
	} while (false);
	CCLog("QutiLayer::ccTouchBegan Run Error!");
	return false;
}
void PauseBackLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	do 
	{
		//获得菜单
		CCMenu* pMenu = dynamic_cast<CCMenu*>(this->getChildByTag(enTagMenu));
		CC_BREAK_IF(pMenu);
		if (m_bIsBtnClicked)
		{
			pMenu->ccTouchMoved(pTouch, pEvent);
		}
		return;
	} while (false);
	CCLog("QutiLayer::ccTouchMoved Run Error!");
	return;
}
void PauseBackLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	do
	{
		//获得菜单
		CCMenu* pMenu = dynamic_cast<CCMenu*>(this->getChildByTag(enTagMenu));
		CC_BREAK_IF(pMenu);
		if (m_bIsBtnClicked)
		{
			pMenu->ccTouchEnded(pTouch, pEvent);
		}
		return;
	} while (false);
	CCLog("QutiLayer::ccTouchEnded Run Error!");
	return;
}

void PauseBackLayer::onEnter()
{
	CCLayer::onEnter();
	//独占触摸层
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
}
void PauseBackLayer::onExit()
{
	CCLayer::onExit();
	CCDirector::sharedDirector()->resume();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}