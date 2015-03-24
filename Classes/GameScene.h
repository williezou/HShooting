#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "PublicDefine.h"
/************************************************************************/
/* ��Ϸ����                                                             */
/************************************************************************/

class GameScene : public CCLayer,public Receiver
{
protected:
	CCArray* m_pBulletArray;					//�ӵ�����	
	CCArray* m_pBulletArrayDeleted;				//�ӵ�ɾ������
	CCArray* m_pEnemyArray;						//��������
	CCArray* m_pEnemyArrayDeleted;				//����ɾ������
	CCArray* m_pEnemyManagerArray;				//���˹�������

	int m_nChooper;				//ѡ���Ӣ��

	int m_nScore;				//����
	bool m_bIsRun;				//�Ƿ��ƶ�
public:
	static CCScene* CreateScene(int nChooper);

protected:
	//��ʼ��
	bool init(int nChooper);

	//�����ص�����
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	//android���ؼ�
	virtual void keyBackClicked();
	//������Ϣ
	void OnMsgReceive(int enMsg, void* pData, int nSize);

	//���º���
	void OnPreFrameUpdate(float ft);

	void menuHomeCallback(CCObject* pSender);
	void OnPause(CCObject* pSender);

	virtual void onEnter();
	virtual void onExit();

	//��Ϸ��ͣ��ť
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
	//������Ϣ
	void BulletCreate(BulletForCreateMsg* pData);
	void BulletDisappear(BulletForDisappearMsg* pData);
	void EnemyCreate(EnemyForCreateMsg* pData);
	void EnemyDisappear(EnemyForDisappearMsg* pData);
	void AddScore(AddScoreMsg* pData);

	//��ײ���
	void Collision();
	//��һ��intת����char
	const char* GetStringFromInt(int Num);

	//������Ϸ������
	void ShowGameOverLayer();
	//��ը����
	void InitAnimation();
};

/************************************************************************/
/* ��ͣ�˳���                                                           */
/************************************************************************/
class PauseBackLayer : public CCLayer
{
public:
	static PauseBackLayer* create();

protected:

	int		m_nLabelNum;		//��¼����
	bool    m_bIsBtnClicked;	//�ж��Ƿ�������ť

	//��ʼ��
	virtual bool init();

	//�ص������������ͷ���
	void menuContinueCallback(CCObject* pSender);
	void menuQuitCallback(CCObject* pSender);

	//���ô���
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
