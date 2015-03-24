#include "BeganScene.h"
#include "PublicDefine.h"
#include "ChooseHero.h"
#include "GameScene.h"

CCScene* BeginSceneLayer::scene()
{
	CCScene *scene = NULL;

	do
	{
		scene = CCScene::create();
		CC_BREAK_IF(!scene);

		BeginSceneLayer *layer = BeginSceneLayer::create();
		CC_BREAK_IF(!scene);

		scene->addChild(layer);
	} while (0);
	return scene;
	CCLog("CCCRMainsceneLayer::scene Run Error!");
}

bool BeginSceneLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		//开启安卓设备支持
		setKeypadEnabled(true);

		//创建背景图片//
		CCSprite *pBackGround = CCSprite::create("startbg2.jpg");
		CC_BREAK_IF(pBackGround == NULL);
		pBackGround->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ / 2));
		this->addChild(pBackGround, enZOrderBackGround);

		//添加出战选择图片
		m_pChuzhan = CCSprite::create("chuzhan.png");
		CC_BREAK_IF(m_pChuzhan == NULL);
		this->addChild(m_pChuzhan, enZOrderChuzhanImg);
		m_pChuzhan->setPosition(ccp(_SCREEN_WIDTH_ / 5 - 5.f, 3 * _SCREEN_HEIGHT_ / 4 - 25.f));
		//play按钮//
		CCMenuItemImage *pPlayItem = CCMenuItemImage::create(
			"startbtn.png",
			"startbtn.png",
			this,
			menu_selector(BeginSceneLayer::menuPlayCallback));
		CC_BREAK_IF(!pPlayItem);
		pPlayItem->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ / 2 - 190.f));

		/*
		//about按钮//
		CCMenuItemImage *pAboutItem = CCMenuItemImage::create(
			"btn-about.png",
			"btn-about-down.png",
			this,
			menu_selector(BeginSceneLayer::menuAboutCallback));
		CC_BREAK_IF(!pAboutItem);
		pAboutItem->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ / 2 - 150.f));

		//退出按钮
		CCMenuItemImage *pExitItem = CCMenuItemImage::create(
			"exit_game_n.png",
			"exit_game_d.png",
			this,
			menu_selector(BeginSceneLayer::menuExitCallback));
		CC_BREAK_IF(!pExitItem);
		pExitItem->setPosition(ccp(_SCREEN_WIDTH_ / 2, _SCREEN_HEIGHT_ / 2 - 260.f));
		*/

		//将menu添加到场景
		CCMenu *pMenu = CCMenu::create(pPlayItem, /*pAboutItem, pExitItem,*/ NULL);
		pMenu->setPosition(CCPointZero);
		CC_BREAK_IF(!pMenu);

		this->addChild(pMenu, enZOrderBtn, enTagChopper);

		bRet = true;
	} while (0);
	return bRet;
}

void BeginSceneLayer::menuPlayCallback(CCObject* pSender)
{
	do 
	{
		//create game scene and callback
		CCScene *pScene = GameScene::CreateScene(0);
		CC_BREAK_IF(pScene == NULL);

		CCDirector::sharedDirector()->replaceScene(pScene);
		return;
	} while (false);
	CCLog("Fun CCCMainsceneLayer::menuPlayCallback Error!");
}

void BeginSceneLayer::keyBackClicked()
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
				CCCallFunc::create(this, callfunc_selector(BeginSceneLayer::OnStopAnimationCallBack)),
				NULL);
			runAction(pPauseAction);
		}
		return;
	} while (false);
	CCLog("Func BeginSceneLayer::keyBackClicked Error!");
	return;
}

//游戏暂停
void BeginSceneLayer::OnStopAnimationCallBack()
{
	CCDirector::sharedDirector()->pause();
}

//bool BeginSceneLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
//{
//	do
//	{
//		//获得菜单
//		CCMenu * pChopper = dynamic_cast<CCMenu *>(this->getChildByTag(enTagChopper));
//		CC_BREAK_IF(pChopper == NULL);
//		m_bIsBtnClicked = pChopper->ccTouchBegan(pTouch, pEvent);
//
//		return true;
//	} while (false);
//	CCLog("CCCQutiLayer::ccTouchBegan Run Error!");
//	return true;
//}
//
//void BeginSceneLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
//{
//	do 
//	{
//		//获得菜单
//		CCMenu * pChopper = dynamic_cast<CCMenu *>(this->getChildByTag(enTagChopper));
//		CC_BREAK_IF(pChopper == NULL);
//
//		if (m_bIsBtnClicked)
//		{
//			if (pTouch->getLocation().x <= _SCREEN_WIDTH_ / 2)
//			{
//				m_pChuzhan->setPosition(ccp(_SCREEN_WIDTH_ / 4, _SCREEN_HEIGHT_ / 2 + 100.f));
//			}
//			else
//			{
//				m_pChuzhan->setPosition(ccp(_SCREEN_WIDTH_ - _SCREEN_WIDTH_ / 4, _SCREEN_HEIGHT_ / 2 + 100.f));
//			}
//		}
//		return;
//	} while (false);
//	CCLog("CCCQutiLayer::ccTouchEnded Run Error!");
//}
//
//void BeginSceneLayer::onEnter()
//{
//	CCLayer::onEnter();
//	//独占触摸层
//	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -130, true);
//}
//
//void BeginSceneLayer::onExit()
//{
//	CCLayer::onExit();
//	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
//}