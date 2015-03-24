#ifndef _CHOOSE_HERO_H_
#define _CHOOSE_HERO_H_

#include "PublicDefine.h"
/************************************************************************/
/* Heroѡ���                                                           */
/************************************************************************/
class ChooseHero : public CCLayer
{
protected:
	int			m_nSelectHeroKind;		//��ǰѡ�е�Ӣ������
	bool		m_bIsClickLeft;		//�����Ļ��ࣨfalseΪ�����Ļ�Ҳࣩ
public:
	static CCScene* CreateScene();
protected:
	CREATE_FUNC(ChooseHero);
	bool init();

	//�����ص�
	bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

	//���̷��ػص���Ӧ��Ӳ˵���
	virtual void  keyBackClicked();
	enum
	{
		enZOrderHomeBtn,
		enZOrderPauseBtn,
		enZOrderAudioBtn,
		enZOrderMissileBtn,
	};

	enum
	{
		enTagPlayer,
		enTagBackGround,

	};

};

#endif //_CHOOSE_HERO_H_

