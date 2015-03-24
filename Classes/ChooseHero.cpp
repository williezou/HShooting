#include "ChooseHero.h"
#include "BackGround.h"
#include "GameScene.h"
#include "BeganScene.h"

//创建类
CCScene* ChooseHero::CreateScene()
{
	do
	{
		CCScene* pScene = CCScene::create();
		CC_BREAK_IF(pScene == NULL);

		ChooseHero* pLayer = ChooseHero::create();
		CC_BREAK_IF(pLayer == NULL);

		//pScene->addChild(pLayer, enZOrderFront);

		//添加滚动背景
		//BackGroundNode* pBackGround = BackGroundNode::CreateBackGround("bg.png");
		//CC_BREAK_IF(pBackGround == NULL);
		//pBackGround->setPosition(ccp(_SCREEN_WIDTH_*0.5f, _SCREEN_HEIGHT_));
		//pScene->addChild(pBackGround, enZOrderBack, enTagBackGround);

		////添加返回按钮
		//CCMenuItemImage* pBackImage = CCMenuItemImage::create(
		//	"btn_back_normal.png",
		//	"btn_back_press.png",
		//	pLayer,
		//	menu_selector(CZHPChooseLevel::menuBackCallback)
		//	);
		//CC_BREAK_IF(pBackImage == NULL);
		//pBackImage->setScale(2.f);
		//pBackImage->setPosition(ccp(_SCREEN_WIDTH_ - 80.f, 80.f));

		////添加暂停按钮
		//CCMenu* pMenu = CCMenu::create(pBackImage, NULL);
		//CC_BREAK_IF(pMenu == NULL);
		//pMenu->setPosition(CCPointZero);
		//pScene->addChild(pMenu, enZOrderBackBtn);

		return pScene;
	} while (false);
	CCLog("Fun ChooseLevel::CreateScene Error!");
	return NULL;
}

bool ChooseHero::init()
{
	do 
	{
		CC_BREAK_IF(CCLayer::init() == false);
		//启动触屏
		setTouchEnabled(true);

		//启动触屏为单点触控
		setTouchMode(kCCTouchesOneByOne);

		return true;
	} while (false);
	CCLog("Fun ChooseHero::init Error!");
	return false;
}

void ChooseHero::keyBackClicked()
{
	do 
	{
		CCScene* pScene = BeginSceneLayer::scene();
		CC_BREAK_IF(pScene == NULL);
		CCDirector::sharedDirector()->replaceScene(pScene);
		return;
	} while (false);
	CCLog("ChooseHero::keyBackClicked Run Error!");
}

bool ChooseHero::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	return true;
}

void ChooseHero::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{

}

void ChooseHero::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}