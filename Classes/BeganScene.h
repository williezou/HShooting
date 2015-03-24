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
	virtual bool init();							//��������ظ�ͼ��ר�õ���Դ
	
	void menuPlayCallback(CCObject* pSender);		//�����ť��ת����Ϸ����

	//��׿���ؼ�
	virtual void keyBackClicked();

	void OnStopAnimationCallBack();

	/*
	void menuAboutCallback(CCObject* pSender);		//��ת�����ڳ���
	void menuExitCallback(CCObject* pSender);		//�Ƿ��˳���Ϸ
	//��ͣ���Ҷ���
	void OnStopAnimationCallBack();

	
	*/

	////���ô���
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
	bool	m_bIsBtnClicked;		//�ж��Ƿ�������ť
};

/*
class QutiLayer :public CCLayer
{
public:
	static QutiLayer* create();
protected:

	int		m_nLabelNum;			//��¼����
	bool	m_bIsBtnClicked;		//�ж��Ƿ�������ť

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
*/
#endif	//_BEGAN_SCENE_HEAD_
