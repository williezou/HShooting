#ifndef _BEGAN_SCENE_HEAD_
#define _BEGAN_SCENE_HEAD_

#include "cocos2d.h"
USING_NS_CC;

/************************************************************************/
/* Game Began Scene                                                        */
/************************************************************************/

class BeginSceneLayer : public cocos2d::CCLayer
{
public:
	static cocos2d::CCScene* scene();

protected:

	CREATE_FUNC(BeginSceneLayer);
	virtual bool init();							//在这里加载该图层专用的资源
	
	void menuPlayCallback(CCObject* pSender);		//点击按钮跳转到游戏场景

	//安卓返回键
	virtual void keyBackClicked();

	void OnStopAnimationCallBack();

	/*
	void menuAboutCallback(CCObject* pSender);		//跳转到关于场景
	void menuExitCallback(CCObject* pSender);		//是否退出游戏
	//暂停左右动作
	void OnStopAnimationCallBack();

	
	*/

	////设置触摸
	//virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	//virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	//virtual void onEnter();
	//virtual void onExit();

	enum 
	{
		enTagChopper,
	};
	enum
	{
		enZOrderBackGround = 1,
		enZOrderChuzhanImg,
		enZOrderBtn,
		enZOrderQuitLayer,
		enZOrderPauseBackLayer,
	};

	enum
	{
		enTagQuitLayer,
		enTagPauseBackLayer
	};
	
protected:
	CCSprite* m_pChuzhan;
	bool	m_bIsBtnClicked;		//判断是否点击到按钮
};

/*
class QutiLayer :public CCLayer
{
public:
	static QutiLayer* create();
protected:

	int		m_nLabelNum;			//记录分数
	bool	m_bIsBtnClicked;		//判断是否点击到按钮

	//初始化
	virtual bool init();

	//回调函数，继续和返回
	void menuContinueCallback(CCObject* pSender);
	void menuQuitCallback(CCObject* pSender);

	//设置触摸
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onEnter();
	virtual void onExit();

	enum
	{
		enZOrderBackGround,
		enZOrderBtn,
	};

	enum
	{
		enTagMenu,
	};
};
*/
#endif	//_BEGAN_SCENE_HEAD_
