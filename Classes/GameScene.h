#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "PublicDefine.h"
/************************************************************************/
/* 游戏场景                                                             */
/************************************************************************/

class GameScene : public CCLayer,public Receiver
{
protected:
	CCArray* m_pBulletArray;					//子弹数组	
	CCArray* m_pBulletArrayDeleted;				//子弹删除数组
	CCArray* m_pEnemyArray;						//敌人数组
	CCArray* m_pEnemyArrayDeleted;				//敌人删除数组
	CCArray* m_pEnemyManagerArray;				//敌人管理数组

	int m_nChooper;				//选择的英雄

	int m_nScore;				//分数
	bool m_bIsRun;				//是否移动
public:
	static CCScene* CreateScene(int nChooper);

protected:
	//初始化
	bool init(int nChooper);

	//触摸回调函数
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	//android返回键
	virtual void keyBackClicked();
	//接收消息
	void OnMsgReceive(int enMsg, void* pData, int nSize);

	//更新函数
	void OnPreFrameUpdate(float ft);

	void menuHomeCallback(CCObject* pSender);
	void OnPause(CCObject* pSender);

	virtual void onEnter();
	virtual void onExit();

	//游戏暂停按钮
	void OnStopAnimationCallBack();
protected:
	enum
	{
		enZOrderBack,
		enZOrderFront,
		enZOrderBtn,
		enZOrderPauseBackLayer,
	};

	enum
	{
		enTagPlayer,
		enTagBackGround,
		enTagHomeBtn,
		enTagPauseBtn,
		enTagBombBtn,
		enTagMusicBtn,
		enTagScore,
		enTagPauseBackLayer,
	};
protected:
	//接受消息
	void BulletCreate(BulletForCreateMsg* pData);
	void BulletDisappear(BulletForDisappearMsg* pData);
	void EnemyCreate(EnemyForCreateMsg* pData);
	void EnemyDisappear(EnemyForDisappearMsg* pData);
	void AddScore(AddScoreMsg* pData);

	//碰撞检测
	void Collision();
	//将一个int转换成char
	const char* GetStringFromInt(int Num);

	//播放游戏结束层
	void ShowGameOverLayer();
	//爆炸动画
	void InitAnimation();
};

/************************************************************************/
/* 暂停退出层                                                           */
/************************************************************************/
class PauseBackLayer : public CCLayer
{
public:
	static PauseBackLayer* create();

protected:

	int		m_nLabelNum;		//记录分数
	bool    m_bIsBtnClicked;	//判断是否点击到按钮

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

#endif //__GAME_SCENE_H__
